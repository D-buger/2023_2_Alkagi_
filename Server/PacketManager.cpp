#include <utility>
#include <cstring>


#include "UserManager.h"
#include "RoomManager.h"
#include "PacketManager.h"
#include "RedisManager.h"


void PacketManager::Init(const UINT32 maxClient_)
{
	mRecvFuntionDictionary = std::unordered_map<int, PROCESS_RECV_PACKET_FUNCTION>();

	mRecvFuntionDictionary[(int)PACKET_ID::SYS_USER_CONNECT] = &PacketManager::ProcessUserConnect;
	mRecvFuntionDictionary[(int)PACKET_ID::SYS_USER_DISCONNECT] = &PacketManager::ProcessUserDisConnect;

	mRecvFuntionDictionary[(int)PACKET_ID::LOGON_REQUEST] = &PacketManager::ProcessLogon;

	mRecvFuntionDictionary[(int)PACKET_ID::LOGIN_REQUEST] = &PacketManager::ProcessLogin;
	mRecvFuntionDictionary[(int)RedisTaskID::RESPONSE_LOGIN] = &PacketManager::ProcessLoginDBResult;
	mRecvFuntionDictionary[(int)RedisTaskID::RESPONSE_NOTICE] = &PacketManager::ProcessNoticeDBResult;

	mRecvFuntionDictionary[(int)PACKET_ID::ROOM_ENTER_REQUEST] = &PacketManager::ProcessEnterRoom;
	mRecvFuntionDictionary[(int)PACKET_ID::ROOM_LEAVE_REQUEST] = &PacketManager::ProcessLeaveRoom;
	mRecvFuntionDictionary[(int)PACKET_ID::ROOM_CHAT_REQUEST] = &PacketManager::ProcessRoomChatMessage;
	mRecvFuntionDictionary[(int)PACKET_ID::PLAYER_MOVEMENT] = &PacketManager::ProcessPlayerMovement;

	mRecvFuntionDictionary[(int)PACKET_ID::REPLAY_SAVE_REQUEST] = &PacketManager::ProcessSaveReplayRequest;
	mRecvFuntionDictionary[(int)PACKET_ID::REPLAY_LOAD_REQUEST] = &PacketManager::ProcessLoadReplayRequest;

	CreateCompent(maxClient_);

	mRedisMgr = new RedisManager;// std::make_unique<RedisManager>();
}

void PacketManager::CreateCompent(const UINT32 maxClient_)
{
	mUserManager = new UserManager;
	mUserManager->Init(maxClient_);


	UINT32 startRoomNummber = 0;
	UINT32 maxRoomCount = 10;
	UINT32 maxRoomUserCount = 4;
	mRoomManager = new RoomManager;
	mRoomManager->SendPacketFunc = SendPacketFunc;
	mRoomManager->Init(startRoomNummber, maxRoomCount, maxRoomUserCount);
}

bool PacketManager::Run()
{
	if (mRedisMgr->Run("127.0.0.1", 6379, 1) == false)
	{
		return false;
	}

	//�� �κ��� ��Ŷ ó�� �κ����� �̵� ��Ų��.
	mIsRunProcessThread = true;
	mProcessThread = std::thread([this]() { ProcessPacket(); });

	return true;
}

void PacketManager::End()
{
	mRedisMgr->End();

	mIsRunProcessThread = false;

	if (mProcessThread.joinable())
	{
		mProcessThread.join();
	}
}

void PacketManager::ClearConnectionInfo(INT32 clientIndex_)
{
	auto pReqUser = mUserManager->GetUserByConnIdx(clientIndex_);

	if (pReqUser->GetDomainState() == User::DOMAIN_STATE::ROOM)
	{
		auto roomNum = pReqUser->GetCurrentRoom();
		mRoomManager->LeaveUser(roomNum, pReqUser);
	}

	if (pReqUser->GetDomainState() != User::DOMAIN_STATE::NONE)
	{
		mUserManager->DeleteUserInfo(pReqUser);
	}
}

void PacketManager::ReceivePacketData(const UINT32 clientIndex_, const UINT32 size_, char* pData_)
{
	auto pUser = mUserManager->GetUserByConnIdx(clientIndex_);
	pUser->SetPacketData(size_, pData_);

	EnqueuePacketData(clientIndex_);
}

void PacketManager::EnqueuePacketData(const UINT32 clientIndex_)
{
	std::lock_guard<std::mutex> guard(mLock);
	mInComingPacketUserIndex.push_back(clientIndex_);
}

PacketInfo PacketManager::DequePacketData()
{
	UINT32 userIndex = 0;

	{
		std::lock_guard<std::mutex> guard(mLock);
		if (mInComingPacketUserIndex.empty())
		{
			return PacketInfo();
		}

		userIndex = mInComingPacketUserIndex.front();
		mInComingPacketUserIndex.pop_front();
	}

	auto pUser = mUserManager->GetUserByConnIdx(userIndex);
	auto packetData = pUser->GetPacket();
	packetData.ClientIndex = userIndex;
	return packetData;
}

void PacketManager::PushSystemPacket(PacketInfo packet_)
{
	std::lock_guard<std::mutex> guard(mLock);
	mSystemPacketQueue.push_back(packet_);
}

PacketInfo PacketManager::DequeSystemPacketData()
{

	std::lock_guard<std::mutex> guard(mLock);
	if (mSystemPacketQueue.empty())
	{
		return PacketInfo();
	}

	auto packetData = mSystemPacketQueue.front();
	mSystemPacketQueue.pop_front();

	return packetData;
}


void PacketManager::ProcessPacket()
{
	while (mIsRunProcessThread)
	{
		bool isIdle = true;

		if (auto packetData = DequePacketData(); packetData.PacketId > (UINT16)PACKET_ID::SYS_END)
		{
			isIdle = false;
			ProcessRecvPacket(packetData.ClientIndex, packetData.PacketId, packetData.DataSize, packetData.pDataPtr);
		}

		if (auto packetData = DequeSystemPacketData(); packetData.PacketId != 0)
		{
			isIdle = false;
			ProcessRecvPacket(packetData.ClientIndex, packetData.PacketId, packetData.DataSize, packetData.pDataPtr);
		}

		if (auto task = mRedisMgr->TakeResponseTask(); task.TaskID != RedisTaskID::INVALID)
		{
			isIdle = false;
			ProcessRecvPacket(task.UserIndex, (UINT16)task.TaskID, task.DataSize, task.pData);
			task.Release();
		}

		if (isIdle)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
}

void PacketManager::ProcessRecvPacket(const UINT32 clientIndex_, const UINT16 packetId_, const UINT16 packetSize_, char* pPacket_)
{
	auto iter = mRecvFuntionDictionary.find(packetId_);
	if (iter != mRecvFuntionDictionary.end())
	{
		(this->*(iter->second))(clientIndex_, packetSize_, pPacket_);
	}

}

void PacketManager::ProcessUserConnect(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	printf("[ProcessUserConnect] clientIndex: %d\n", clientIndex_);
	auto pUser = mUserManager->GetUserByConnIdx(clientIndex_);
	pUser->Clear();
}

void PacketManager::ProcessUserDisConnect(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	printf("[ProcessUserDisConnect] clientIndex: %d\n", clientIndex_);
	ClearConnectionInfo(clientIndex_);
}

void PacketManager::ProcessLogon(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	if (LOGON_REQUEST_PACKET_SIZE != packetSize_)
	{
		return;
	}

	auto pLogonReqPacket = reinterpret_cast<LOGON_REQUEST_PACKET*>(pPacket_);

	auto pUserID = pLogonReqPacket->userID;

	LOGON_RESPONSE_PACKET logonResPacket;

	RedisLogonReq dbReq;
	CopyUserID(dbReq.UserID, pLogonReqPacket->userID);
	CopyMemory(dbReq.UserPW, pLogonReqPacket->userPW, (MAX_USER_PW_LEN + 1));

	RedisTask task;
	task.UserIndex = clientIndex_;
	task.TaskID = RedisTaskID::REQUEST_LOGON;
	task.DataSize = sizeof(RedisLoginReq);
	task.pData = new char[task.DataSize];
	CopyMemory(task.pData, (char*)&dbReq, task.DataSize);
	mRedisMgr->PushTask(task);

	printf("Redis new user id = %s\n", pUserID);
}

void PacketManager::ProcessLogin(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	if (LOGIN_REQUEST_PACKET_SIZE != packetSize_)
	{
		return;
	}

	auto pLoginReqPacket = reinterpret_cast<LOGIN_REQUEST_PACKET*>(pPacket_);

	auto pUserID = pLoginReqPacket->userID;
	printf("requested user id = %s\n", pUserID);

	LOGIN_RESPONSE_PACKET loginResPacket;

	if (mUserManager->GetCurrentUserCnt() >= mUserManager->GetMaxUserCnt())
	{
		//�����ڼ��� �ִ���� �����ؼ� ���ӺҰ�
		loginResPacket.Result = (UINT16)ERROR_CODE::LOGIN_USER_USED_ALL_OBJ;
		SendPacketFunc(clientIndex_, sizeof(LOGIN_RESPONSE_PACKET), (char*)&loginResPacket);
		return;
	}

	//���⿡�� �̹� ���ӵ� �������� Ȯ���ϰ�, ���ӵ� ������� �����Ѵ�.
	if (mUserManager->FindUserIndexByID(pUserID) == -1)
	{
		RedisLoginReq dbReq;
		CopyUserID(dbReq.UserID, pLoginReqPacket->userID);
		CopyMemory(dbReq.UserPW, pLoginReqPacket->userPW, (MAX_USER_PW_LEN + 1));

		RedisTask task;
		task.UserIndex = clientIndex_;
		task.TaskID = RedisTaskID::REQUEST_LOGIN;
		task.DataSize = sizeof(RedisLoginReq);
		task.pData = new char[task.DataSize];
		CopyMemory(task.pData, (char*)&dbReq, task.DataSize);
		mRedisMgr->PushTask(task);

		printf("Login To Redis user id = %s\n", pUserID);
	}
	else
	{
		//�������� �������� ���и� ��ȯ�Ѵ�.
		loginResPacket.Result = (UINT16)ERROR_CODE::LOGIN_USER_ALREADY;
		SendPacketFunc(clientIndex_, sizeof(LOGIN_RESPONSE_PACKET), (char*)&loginResPacket);
		return;
	}
}

void PacketManager::ProcessLoginDBResult(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	printf("ProcessLoginDBResult. UserIndex: %d\n", clientIndex_);

	auto pBody = (RedisLoginRes*)pPacket_;

	LOGIN_RESPONSE_PACKET loginResPacket;

	if (pBody->Result == (UINT16)ERROR_CODE::NONE)
	{
		//�α��� �Ϸ�� �����Ѵ�
		auto pUser = mUserManager->GetUserByConnIdx(clientIndex_);
		pUser->SetLogin(pBody->UserID);

		loginResPacket.Result = clientIndex_;
		loginResPacket.IsSucceed = 1;
	}
	else {
		loginResPacket.Result = pBody->Result;
		loginResPacket.IsSucceed = 0;
	}

	SendPacketFunc(clientIndex_, sizeof(LOGIN_RESPONSE_PACKET), (char*)&loginResPacket);
}

void PacketManager::ProcessNoticeDBResult(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	printf("ProcessNoticeDBResult. UserIndex: %d\n", clientIndex_);
	auto pBody = (RedisNoticeRes*)pPacket_;
	ROOM_CHAT_NOTIFY_PACKET roomChatNtfyPkt;
	StringCbCopyA(roomChatNtfyPkt.userID, sizeof(roomChatNtfyPkt.userID), "[GM]");
	StringCbCopyA(roomChatNtfyPkt.Msg, sizeof(roomChatNtfyPkt.Msg), pBody->Message);
	mRoomManager->SendToAllUser(roomChatNtfyPkt.PacketLength, (char*)&roomChatNtfyPkt, clientIndex_, false);
}


void PacketManager::ProcessEnterRoom(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	UNREFERENCED_PARAMETER(packetSize_);

	auto pRoomEnterReqPacket = reinterpret_cast<ROOM_ENTER_REQUEST_PACKET*>(pPacket_);
	auto pReqUser = mUserManager->GetUserByConnIdx(clientIndex_);

	if (!pReqUser || pReqUser == nullptr)
	{
		return;
	}

	auto roomNumber = pRoomEnterReqPacket->RoomNumber;


	// Room::EnterUser()���� �����ϴ� �������� ��� ���� ����Ʈ�� �����Ѵ�
	auto enterResult = mRoomManager->EnterUser(roomNumber, pReqUser);

	{
		ROOM_ENTER_RESPONSE_PACKET roomEnterResPacket;
		roomEnterResPacket.Result = enterResult;
		SendPacketFunc(clientIndex_, sizeof(ROOM_ENTER_RESPONSE_PACKET), (char*)&roomEnterResPacket);
	}
	printf("Response Packet Sended");

	if (enterResult != (UINT16)ERROR_CODE::NONE)
	{
		return;
	}

	auto pRoom = mRoomManager->GetRoomByNumber(roomNumber);


	// ��� �����鿡�� �����ϴ� ���� ���� ����
	pRoom->NotifyUserEnter(clientIndex_, pReqUser->GetUserId());

}


void PacketManager::ProcessLeaveRoom(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	UNREFERENCED_PARAMETER(packetSize_);
	UNREFERENCED_PARAMETER(pPacket_);

	ROOM_LEAVE_RESPONSE_PACKET roomLeaveResPacket;

	auto reqUser = mUserManager->GetUserByConnIdx(clientIndex_);
	auto roomNum = reqUser->GetCurrentRoom();

	//TODO Room���� UserList��ü�� �� Ȯ���ϱ�
	roomLeaveResPacket.Result = mRoomManager->LeaveUser(roomNum, reqUser);
	SendPacketFunc(clientIndex_, sizeof(ROOM_LEAVE_RESPONSE_PACKET), (char*)&roomLeaveResPacket);
}

void PacketManager::ProcessPlayerMovement(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	UNREFERENCED_PARAMETER(packetSize_);
	UNREFERENCED_PARAMETER(pPacket_);

	auto playerMovement = reinterpret_cast<PLAYER_MOVEMENT_PACKET*>(pPacket_);

	if (playerMovement->userUUID != clientIndex_)
	{
		printf("[ProcessPlayerMovement] userUUID(%lld) != clientIndex_(%ld)\n", playerMovement->userUUID, clientIndex_);
		return;
	}


	printf("[ProcessPlayerMovement] userUUID(%lld) dx=%f, dy=%f, rx:%f, ry:%f, rz:%f \n", playerMovement->userUUID,
		playerMovement->dx, playerMovement->dy, playerMovement->rotation.x, playerMovement->rotation.y, playerMovement->rotation.z);

	auto reqUser = mUserManager->GetUserByConnIdx(clientIndex_);
	auto roomNum = reqUser->GetCurrentRoom();

	auto pRoom = mRoomManager->GetRoomByNumber(roomNum);
	if (pRoom == nullptr)
	{
		printf("[ProcessPlayerMovement] pRoom == nullptr userUUID(%lld), roomNum(%d)\n", playerMovement->userUUID, roomNum);
		return;
	}

	UPDATE_PLAYER_MOVEMENT_PACKET updateMovement;
	updateMovement.userUUID = playerMovement->userUUID;
	updateMovement.rotation = playerMovement->rotation;
	// Movement ó��
	updateMovement.motion = reqUser->UpdateMovement(playerMovement->dx, playerMovement->dy, playerMovement->rotation);

	pRoom->SendToAllUser(updateMovement.PacketLength, (char*)&updateMovement, clientIndex_, false);
}


void PacketManager::ProcessRoomChatMessage(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	UNREFERENCED_PARAMETER(packetSize_);

	auto pRoomChatReqPacketet = reinterpret_cast<ROOM_CHAT_REQUEST_PACKET*>(pPacket_);

	ROOM_CHAT_RESPONSE_PACKET roomChatResPacket;
	roomChatResPacket.Result = (INT16)ERROR_CODE::NONE;

	auto reqUser = mUserManager->GetUserByConnIdx(clientIndex_);
	auto roomNum = reqUser->GetCurrentRoom();

	const std::string cmdMessage = pRoomChatReqPacketet->Message;

	auto pRoom = mRoomManager->GetRoomByNumber(roomNum);
	if (pRoom == nullptr)
	{
		roomChatResPacket.Result = (INT16)ERROR_CODE::CHAT_ROOM_INVALID_ROOM_NUMBER;
		SendPacketFunc(clientIndex_, sizeof(ROOM_CHAT_RESPONSE_PACKET), (char*)&roomChatResPacket);
		return;
	}

	if (cmdMessage.find("/n", 0) == 0)
	{
		const std::string noticeMsg = cmdMessage.substr(2);
		RedisReqNotice(*reqUser, noticeMsg);
		return;
	}
	else if (cmdMessage.find("/b", 0) == 0)
	{
		pRoom->EnterNpc();
		return;
	}


	SendPacketFunc(clientIndex_, sizeof(ROOM_CHAT_RESPONSE_PACKET), (char*)&roomChatResPacket);

	pRoom->NotifyChat(clientIndex_, reqUser->GetUserId().c_str(), pRoomChatReqPacketet->Message);
}


void PacketManager::ProcessSaveReplayRequest(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	UNREFERENCED_PARAMETER(packetSize_);

	auto pSaveReplayReqPacket = reinterpret_cast<REPLAY_SAVE_REQUEST_PACKET*>(pPacket_);

	std::cout << std::endl << pSaveReplayReqPacket->Message << std::endl;
}

void PacketManager::ProcessLoadReplayRequest(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_)
{
	UNREFERENCED_PARAMETER(packetSize_);

	auto pLoadReplayReqPacket = reinterpret_cast<REPLAY_LOAD_REQUEST_PACKET*>(pPacket_);

	auto reqUser = mUserManager->GetUserByConnIdx(clientIndex_);
	auto roomNum = reqUser->GetCurrentRoom();

	auto pRoom = mRoomManager->GetRoomByNumber(roomNum);

	REPLAY_LOAD_DATA_PACKET replayLoadRequestPacket;
	StringCbCopyA(replayLoadRequestPacket.Message, sizeof(replayLoadRequestPacket.Message), "Replay Datas");

	std::cout << "requested replay id : " << pLoadReplayReqPacket->playID << " " << replayLoadRequestPacket.Message;

	SendPacketFunc(clientIndex_, sizeof(REPLAY_LOAD_DATA_PACKET), (char*)&replayLoadRequestPacket);
}

void PacketManager::RedisReqNotice(User& user, const std::string noticeMsg)
{
	RedisNoticeReq dbReq;
	CopyUserID(dbReq.UserID, "[GM]");
	StringCbCopyA(dbReq.UserID, sizeof(dbReq.UserID), "[GM]");
	StringCbCopyA(dbReq.Message, sizeof(dbReq.Message), noticeMsg.c_str());
	RedisTask task;
	task.UserIndex = user.GetNetConnIdx();
	task.TaskID = RedisTaskID::REQUEST_NOTICE;
	task.DataSize = sizeof(RedisNoticeReq);
	task.pData = new char[task.DataSize];
	CopyMemory(task.pData, (char*)&dbReq, task.DataSize);
	mRedisMgr->PushTask(task);
	printf("[Redis Request] Notice. userUUID(%d), userID(%s), msg:%s\n", user.GetNetConnIdx(), user.GetUserId(), noticeMsg.c_str());
}