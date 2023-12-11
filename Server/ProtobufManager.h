#pragma once

#include "..\Server\User.pb.h"

class Proto {
private:
	

public:
	Proto() {
		//GOOGLE_PROTOBUF_VERIFY_VERSION;
	}
	~Proto() {}

	tutorial::User char2Proto(char* data_) {
		tutorial::User user;
		user.ParseFromString(data_);
		return user;
	}
	const char* Proto2char(tutorial::User data_) {
		return (data_.SerializeAsString().c_str());
	}
};