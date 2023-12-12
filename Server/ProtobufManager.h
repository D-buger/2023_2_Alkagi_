#pragma once

#include "..\Server\User.pb.h"

static class Proto {
private:
	

public:
	Proto() {}
	~Proto() {}

	static tutorial::User char2Proto(std::string data_) {
		tutorial::User user;
		user.ParseFromString(data_);
		return user;
	}
	static std::string Proto2char(tutorial::User data_) {
		return (data_.SerializeAsString());
	}
};