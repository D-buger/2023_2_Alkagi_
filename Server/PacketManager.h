#pragma once

#include "Packet.h"

#include <unordered_map>
#include <deque>
#include <functional>
#include <thread>
#include <mutex>
#include <strsafe.h>

class User;
class UserManager;
class RoomManager;
class RedisManager;

class PacketManager {
public:
	PacketManager() = default;
	~PacketManager() = default;

	void Init(const UINT32 maxClient_);

	bool Run();

	void End();

	void ReceivePacketData(const UINT32 clientIndex_, const UINT32 size_, char* pData_);

	void PushSystemPacket(PacketInfo packet_);

	std::function<void(UINT32, UINT32, char*)> SendPacketFunc;

private:
	void CreateCompent(const UINT32 maxClient_);

	void ClearConnectionInfo(INT32 clientIndex_);

	void EnqueuePacketData(const UINT32 clientIndex_);
	PacketInfo DequePacketData();

	PacketInfo DequeSystemPacketData();


	void ProcessPacket();

	void ProcessRecvPacket(const UINT32 clientIndex_, const UINT16 packetId_, const UINT16 packetSize_, char* pPacket_);

	void ProcessUserConnect(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessUserDisConnect(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);

	void ProcessLogon(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessLogonDBResult(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);

	void ProcessLogin(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessLoginDBResult(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessNoticeDBResult(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);

	void ProcessEnterRoom(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessLeaveRoom(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessPlayerMovement(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessBallPosition(UINT32 cliendIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessPlayerTurnNotify(User& user_, UINT16 packetSize_, const std::string noticeTurnMsg);
	void ProcessRoomChatMessage(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);

	void ProcessSaveUserDataRequest(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessLoadUserDataRequest(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);
	void ProcessLoadUserDataDBResult(UINT32 clientIndex_, UINT16 packetSize_, char* pPacket_);

	void PacketManager::RedisReqNotice(User& user, const std::string noticeMsg);


	typedef void(PacketManager::* PROCESS_RECV_PACKET_FUNCTION)(UINT32, UINT16, char*);
	std::unordered_map<int, PROCESS_RECV_PACKET_FUNCTION> mRecvFuntionDictionary;

	UserManager* mUserManager;
	RoomManager* mRoomManager;
	RedisManager* mRedisMgr;

	std::function<void(int, char*)> mSendMQDataFunc;


	bool mIsRunProcessThread = false;

	std::thread mProcessThread;

	std::mutex mLock;

	std::deque<UINT32> mInComingPacketUserIndex;

	std::deque<PacketInfo> mSystemPacketQueue;
};

