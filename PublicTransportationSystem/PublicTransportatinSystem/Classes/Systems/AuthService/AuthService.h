#pragma once

#include <iostream>
#include <vector>

#include "../User/User.h"

using namespace std;

class AuthService {
	public:
		AuthService();

		void registerUser(const string& username, const string& password);
		User* loginUser(const string& username, const string& password);

	private:
		vector<User> users;
};

