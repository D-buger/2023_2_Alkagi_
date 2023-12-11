#pragma once

#include "Packet.h"

#include <string>

class Actor {

public:
	Actor() = default;
	~Actor() = default;

	virtual void Init(const INT32 index) = 0;

	virtual void Clear() = 0;

	virtual int SetLogin(char* userID_) = 0;

	virtual void EnterRoom(INT32 roomIndex_) = 0;

	INT32 GetCurrentRoom()
	{
		return mRoomIndex;
	}

	INT32 GetNetConnIdx()
	{
		return mIndex;
	}

	std::string GetUserId() const
	{
		return  mUserID;
	}


	const Vector3& GetPosition() const { return position; }
	const Quaternion& GetRotation() const { return rotation; }

	Vector3 UpdateMovement(float dx, float dy, Quaternion& rotation_)
	{
		const float SPEED = 20.0f;

		dx *= (dx <= 1.0f);
		dy *= (dy <= 1.0f);

		// same as the client-sided calculation
		Vector3 right = Quaternion_Multiply(rotation_, Vector3_right());
		Vector3 forward = Quaternion_Multiply(rotation_, Vector3_forward());
		Vector3 mx = Vector3_Multiply(right, dx);
		Vector3 my = Vector3_Multiply(forward, dy);
		Vector3 motion = Vector3_Addition(mx, my);
		motion = Vector3_Multiply(motion, FIXED_DELTA_TIME * SPEED);


		position = Vector3_Addition(position, motion);
		rotation = rotation_;

		return motion;
	}

	Vector3 UpdateBallPosition(Vector3 ballPos)
	{
		Vector3 v = { -1.0f, 0.0f, -1.0f };
		Vector3 result = { ballPos.x * v.z,ballPos.y,ballPos.z * v.z };
		return result;
	}

protected:
	INT32 mIndex = -1;

	INT32 mRoomIndex = -1;

	std::string mUserID;


	// position of the player
	Vector3 position;

	// rotation of the player
	Quaternion rotation;
};