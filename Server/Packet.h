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
	ROOM_NEW_USER_NTF = 208, // 입장하는 유저에게도 전송
	ROOM_USER_INFO_NTF = 209, // Zone에 있던 유저 정보 (입장하는 유저에게만 보냄)

	// Leave
	ROOM_LEAVE_REQUEST = 215,
	ROOM_LEAVE_RESPONSE = 216,
	ROOM_LEAVE_USER_NTF = 217,

	// Move
	PLAYER_MOVEMENT,
	UPDATE_PLAYER_MOVEMENT,

	// Ball Position
	BALL_POSITION,
	UPDATE_BALL_POSITION,

	PLAYER_TURN_NOTIFY,

	ROOM_CHAT_REQUEST = 230,
	ROOM_CHAT_RESPONSE = 231,
	ROOM_CHAT_NOTIFY = 232,

	USER_DATA_SAVE,
	USER_DATA_LOAD_REQUEST,
	USER_DATA_LOAD_RESPONSE
};


#pragma pack(push,1)
struct PACKET_HEADER
{
	const UINT16 PacketLength;
	const UINT16 PacketId;
	const UINT8 Type = 0; //압축여부 암호화여부 등 속성을 알아내는 값
	PACKET_HEADER() : PacketLength(0), PacketId(0), Type(0) {}
	PACKET_HEADER(UINT16 PacketLength, PACKET_ID PacketId, UINT8 Type = 0) : PacketLength{ PacketLength }, PacketId{ (UINT16)PacketId }, Type{ Type }
	{
	}
};
const UINT32 PACKET_HEADER_LENGTH = sizeof(PACKET_HEADER);

//- 회원가입 요청
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

//- 로그인 요청

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


//- 룸에 들어가기 요청
//const int MAX_ROOM_TITLE_SIZE = 32;
struct ROOM_ENTER_REQUEST_PACKET : public PACKET_HEADER
{
	INT32 RoomNumber;
	ROOM_ENTER_REQUEST_PACKET() : RoomNumber{ 0 }, PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_ENTER_REQUEST) {}
};

struct ROOM_ENTER_RESPONSE_PACKET : public PACKET_HEADER
{
	INT16 Result;
	INT32 PlayerNum;
	//char RivaluserID[MAX_USER_ID_LEN + 1] = { 0, };
	ROOM_ENTER_RESPONSE_PACKET() : Result{ 0 }, PlayerNum{ 0 }, PACKET_HEADER(sizeof(*this), PACKET_ID::ROOM_ENTER_RESPONSE) {}
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


struct BALL_POSITION : public PACKET_HEADER
{
	INT64 userUUID;
	INT32 childIndex;
	Vector3 ballPos;

	BALL_POSITION() : PACKET_HEADER(sizeof(*this), PACKET_ID::BALL_POSITION) {}
};

struct UPDATE_BALL_POSITION : public PACKET_HEADER
{
	INT64 userUUID;
	INT32 childIndex;
	Vector3 ballPos;

	UPDATE_BALL_POSITION() : PACKET_HEADER(sizeof(*this), PACKET_ID::UPDATE_BALL_POSITION) {}
};

const static int MAX_TURN_MSG_SIZE = 256;
struct PLAYER_TURN_NOTIFY : public PACKET_HEADER
{
	char userID[MAX_TURN_MSG_SIZE + 1] = { 0, };
	INT32 curTurn;
	char Msg[MAX_TURN_MSG_SIZE + 1] = { 0, };

	PLAYER_TURN_NOTIFY() : PACKET_HEADER(sizeof(*this), PACKET_ID::PLAYER_TURN_NOTIFY) {}
};

//- 룸 나가기 요청
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


// 룸 채팅
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


// 유저 데이터 불러오기
const static int MAX_USER_DATA_MSG_SIZE = 256;
struct USER_DATA_SAVE_REQUEST_PACKET : public PACKET_HEADER
{
	INT16 UserDataType;
	char Data[MAX_USER_DATA_MSG_SIZE + 1] = { 0, };

	USER_DATA_SAVE_REQUEST_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::USER_DATA_SAVE) {}
};

struct USER_DATA_LOAD_REQUEST_PACKET : public PACKET_HEADER
{
	USER_DATA_LOAD_REQUEST_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::USER_DATA_LOAD_REQUEST) {}
};

struct USER_DATA_LOAD_RESPONSE_PACKET : public PACKET_HEADER {

	char Data[MAX_USER_DATA_MSG_SIZE + 1] = { 0, };

	USER_DATA_LOAD_RESPONSE_PACKET() : PACKET_HEADER(sizeof(*this), PACKET_ID::USER_DATA_LOAD_RESPONSE) {}
};

#pragma pack(pop) //위에 설정된 패킹설정이 사라짐
