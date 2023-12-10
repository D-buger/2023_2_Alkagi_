#pragma once

#include "Packet.h"
#include "Actor.h"

class Npc : public Actor {
public:
	Npc() = default;
	virtual ~Npc() = default;

	virtual void Init(const INT32 index) override
	{
		mIndex = index;
	}

	virtual void Clear() override
	{
		mRoomIndex = -1;
		mUserID = "";
	}

	virtual int SetLogin(char* userID_) override
	{
		mUserID = userID_;

		return 0;
	}

	virtual void EnterRoom(INT32 roomIndex_) override
	{
		mRoomIndex = roomIndex_;
	}
};