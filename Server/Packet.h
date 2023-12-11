#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "unity.h"

struct RawPacketData
{
	UINT32 ClientIndex = 0;
	UINT32 DataSize = 0;
	char* pPacketData = nullptr;

	void Set(RawPacketData& vlaue)
	{
		ClientIndex = vlaue.ClientIndex;
		DataSize = vlaue.DataSize;

		pPacketData = new char[vlaue.DataSize];
		CopyMemory(pPacketData, vlaue.pPacketData, vlaue.DataSize);
	}

	void Set(UINT32 clientIndex_, UINT32 dataSize_, char* pData)
	{
		ClientIndex = clientIndex_;
		DataSize = dataSize_;

		pPacketData = new char[dataSize_];
		CopyMemory(pPacketData, pData, dataSize_);
	}

	void Release()
	{
		delete pPacketData;
	}
};


struct PacketInfo
{
	UINT32 ClientIndex = 0;
	UINT16 PacketId = 0;
	UINT16 DataSize = 0;
	char* pDataPtr = nullptr;
};


enum class  PACKET_ID : UINT16
{
	//SYSTEM
	SYS_USER_CONNECT = 11,
	SYS_USER_DISCONNECT = 12,
	SYS_END = 30,

	//DB
	DB_END = 199,

	LOGON_REQUEST = 200,
	LOGON_RESPONSE = 201,

	//Client
	LOGIN_REQUEST = 202,
	LOGIN_RESPONSE = 203,

	// Enter
	ROOM_ENTER_REQUEST = 206,
	ROOM_ENTER_RESPONSE = 207,
	ROOM_NEW_USER_NTF = 208, // �����ϴ� �������Ե� ����
	ROOM_USER_INFO_NTF = 209, // Zone�� �ִ� ���� ���� (�����ϴ� �������Ը� ����)

	// Leave
	ROOM_LEAVE_REQUEST = 215,
	ROOM_LEAVE_RESPONSE = 216,
	ROOM_LEAVE_USER_NTF = 217,

	// Move
	PLAYER_MOVEMENT,
	UPDATE_PLAYER_MOVEMENT,

	ROOM_CHAT_REQUEST = 221,
	ROOM_CHAT_RESPONSE = 222,
	ROOM_CHAT_NOTIFY = 223,

	REPLAY_SAVE_REQUEST,
	REPLAY_LOAD_REQUEST,
	REPLAY_LOAD_RESPONSE
};


#pragma pack(push,1)
struct PACKET_HEADER
{
	const UINT16 PacketLength;
	const UINT16 PacketId;
	const UINT8 Type = 0; //���࿩�� ��ȣȭ���� �� �Ӽ��� �˾Ƴ��� ��
	PACKET_HEADER() : PacketLength(0), PacketId(0), Type(0) {}
	PACKET_HEADER(UINT16 PacketLength, PACKET_ID PacketId, UINT8 Type = 0) : PacketLength{ PacketLength }, PacketId{ (UINT16)PacketId }, Type{ Type }
	{
	}
};
const UINT32 PACKET_HEADER_LENGTH = sizeof(PACKET_HEADER);

//- ȸ������ ��û
const int MAX_USER_ID_LEN = 32;
const int MAX_USER_PW_LEN = 32;

struct LOGON_REQUEST_PACKET : public PACKET_HEADER
{
	char userID[MAX_USER_ID_LEN + 1];
	char userPW[MAX_USER_PW_LEN + 1];

	LOGON_REQUEST_PACKET() : userID{ 0, }, PACKET_HEADER(sizeof(*this), PACKET_ID::LOGON_REQUEST) {}
};
const size_t LOGON_REQUEST_PACKET_SIZE = sizeof(LOGON_REQUEST_PACKET);


struct LOGON_RESPONSE_PACKET : public PACKET_HEADER
{
	UINT16 Result;

	LOGON_RESPONSE_PACKET() : Result{ 0 }, PACKET_HEADER(sizeof(*this), PACKET_ID::LOGON_RESPONSE) {}
};

//- �α��� ��û

struct LOGIN_REQUEST_PACKET : public PACKET_HEADER
{
	char userID[MAX_USER_ID_LEN + 1];
	char userPW[MAX_USER_PW_LEN + 1];

	LOGIN_REQUEST_PACKET() : userID{ 0, }, PACKET_HEADER(sizeof(*this), PACKET_ID::LOGIN_REQUEST) {}
};
const size_t LOGIN_REQUEST_PACKET_SIZE = sizeof(LOGIN_REQUEST_PACKET);


struct LOGIN_RESPONSE_PACKET : public PACKET_HEADER
{
	UINT16 Result;
	UINT16 IsSucceed;

	LOGIN_RESPONSE_PACKET() : Result{ 0 }, IsSucceed{0}, PACKET_HEADER(sizeof(*this), PACKET_ID::LOGIN_RESPONSE) {}
};


//- �뿡 ���� ��û
//const int MAX_ROOM_TITLE_SIZE = 32;
struct ROOM_ENTER_REQUEST_PACKET : public PACKET_HEADER
{
	INT32 RoomNumber;
	ROOM_ENTER_REQUEST_PACKET() : RoomNumber{ 0 }, PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_ENTER_REQUEST) {}
};

struct ROOM_ENTER_RESPONSE_PACKET : public PACKET_HEADER
{
	INT16 Result;
	//char RivaluserID[MAX_USER_ID_LEN + 1] = { 0, };
	ROOM_ENTER_RESPONSE_PACKET() : Result{ 0 }, PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_ENTER_RESPONSE) {}
};


struct ROOM_NEW_USER_NTF_PACKET : public PACKET_HEADER
{
	INT64 userUUID;
	char userID[MAX_USER_ID_LEN + 1];

	ROOM_NEW_USER_NTF_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_NEW_USER_NTF) {}
};

struct ROOM_USER_INFO_NTF_PACKET : public PACKET_HEADER
{

	INT64 userUUID;
	char userID[MAX_USER_ID_LEN + 1];
	Vector3 position;
	Quaternion rotation;

	ROOM_USER_INFO_NTF_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_USER_INFO_NTF) {}
};

struct PLAYER_MOVEMENT_PACKET : public PACKET_HEADER
{
	INT64 userUUID;
	float dx;
	float dy;
	Quaternion rotation;

	PLAYER_MOVEMENT_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::PLAYER_MOVEMENT) {}
};


struct UPDATE_PLAYER_MOVEMENT_PACKET : public PACKET_HEADER
{
	INT64 userUUID;
	Quaternion rotation;
	Vector3 motion;

	UPDATE_PLAYER_MOVEMENT_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::UPDATE_PLAYER_MOVEMENT) {}
};


//- �� ������ ��û
struct ROOM_LEAVE_REQUEST_PACKET : public PACKET_HEADER
{
	ROOM_LEAVE_REQUEST_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_LEAVE_REQUEST) {}
};


struct ROOM_LEAVE_RESPONSE_PACKET : public PACKET_HEADER
{
	INT16 Result;
	ROOM_LEAVE_RESPONSE_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_LEAVE_RESPONSE) {}
};


struct ROOM_LEAVE_USER_NTF_PACKET : public PACKET_HEADER
{
	INT64 userUUID;
	char userID[MAX_USER_ID_LEN + 1];
	ROOM_LEAVE_USER_NTF_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_LEAVE_USER_NTF) {}
};


// �� ä��
const static int MAX_CHAT_MSG_SIZE = 256;
struct ROOM_CHAT_REQUEST_PACKET : public PACKET_HEADER
{
	char Message[MAX_CHAT_MSG_SIZE + 1] = { 0, };

	ROOM_CHAT_REQUEST_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_CHAT_REQUEST) {}
};


struct ROOM_CHAT_RESPONSE_PACKET : public PACKET_HEADER
{
	INT16 Result;

	ROOM_CHAT_RESPONSE_PACKET() : Result{ 0 }, PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_CHAT_RESPONSE) {}
};


struct ROOM_CHAT_NOTIFY_PACKET : public PACKET_HEADER
{
	char userID[MAX_USER_ID_LEN + 1] = { 0, };
	char Msg[MAX_CHAT_MSG_SIZE + 1] = { 0, };

	ROOM_CHAT_NOTIFY_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_CHAT_NOTIFY) {}
};


// ���÷��� ���
const static int MAX_REPLAY_MSG_SIZE = 256;
struct REPLAY_SAVE_REQUEST_PACKET : public PACKET_HEADER
{
	char Message[MAX_REPLAY_MSG_SIZE + 1] = { 0, };

	REPLAY_SAVE_REQUEST_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::REPLAY_SAVE_REQUEST) {}
};

struct REPLAY_LOAD_REQUEST_PACKET : public PACKET_HEADER
{
	INT64 playID;

	REPLAY_LOAD_REQUEST_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::REPLAY_LOAD_REQUEST) {}
};

struct REPLAY_LOAD_DATA_PACKET : public PACKET_HEADER {

	char Message[MAX_REPLAY_MSG_SIZE + 1] = { 0, };

	REPLAY_LOAD_DATA_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::REPLAY_LOAD_RESPONSE) {}
};

#pragma pack(pop) //���� ������ ��ŷ������ �����

