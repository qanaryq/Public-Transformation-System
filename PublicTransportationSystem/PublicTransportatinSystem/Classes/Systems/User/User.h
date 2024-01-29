#pragma once

#include <string>

using namespace std;

class User {
	public:
		User(const string& username, const string& password);

		string getUsername() const;
		string getPassword() const;
		string getUserType() const;
		bool authenticate(const string& password) const;

	private:
		string username;
		string password;
		string userType;
};

