#pragma once

//#include "Protobuf/User.pb.h"

class User {
private:
	

public:
	User() {
		//GOOGLE_PROTOBUF_VERIFY_VERSION;
	}
	~User() {}

	void Write();
	void Read();
};