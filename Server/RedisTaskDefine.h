#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "ErrorCode.h"

enum class RedisTaskID : UINT16
{
	INVALID = 0,

	REQUEST_LOGIN = 1001,
	RESPONSE_LOGIN = 1002,
	REQUEST_NOTICE = 1003,
	RESPONSE_NOTICE = 1004,
	REQUEST_LOGON = 1005,
	RESPONSE_LOGON = 1006,
	REQUEST_DATA = 1007,
	RESPONSE_DATA = 1008
};



struct RedisTask
{
	UINT32 UserIndex = 0;
	RedisTaskID TaskID = RedisTaskID::INVALID;
	UINT16 DataSize = 0;
	char* pData = nullptr;	

	void Release()
	{
		if (pData != nullptr)
		{
			delete[] pData;
		}
	}
};




#pragma pack(push,1)

struct RedisLogonReq {
	char UserID[MAX_USER_ID_LEN + 1];
	char UserPW[MAX_USER_PW_LEN + 1];
};

struct RedisLogonRes {
	char UserID[MAX_USER_ID_LEN + 1];
	UINT16 Result = (UINT16)ERROR_CODE::NONE;
};

struct RedisLoginReq
{
	char UserID[MAX_USER_ID_LEN + 1];
	char UserPW[MAX_USER_PW_LEN + 1];
};

struct RedisLoginRes
{
	char UserID[MAX_USER_ID_LEN + 1];
	UINT16 Result = (UINT16)ERROR_CODE::NONE;
	UINT16 isSucess = 0;
};

struct RedisNoticeReq
{
	char UserID[MAX_USER_ID_LEN + 1];
	char Message[MAX_CHAT_MSG_SIZE + 1];
};

struct RedisNoticeRes
{
	char UserID[MAX_USER_ID_LEN + 1];
	char Message[MAX_CHAT_MSG_SIZE + 1];
};

struct RedisDataReq
{
	char UserID[MAX_USER_ID_LEN + 1];
};

struct RedisDataRes
{
	char UserID[MAX_USER_ID_LEN + 1];
	char Message[MAX_CHAT_MSG_SIZE + 1];
};
#pragma pack(pop) //위에 설정된 패킹설정이 사라짐