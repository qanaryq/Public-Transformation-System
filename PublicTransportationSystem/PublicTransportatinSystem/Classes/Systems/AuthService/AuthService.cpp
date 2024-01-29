#include "AuthService.h"

AuthService::AuthService () {
}

void AuthService::registerUser(const string& username, const string& password) {
	users.push_back(User(username, password));
}

User* AuthService::loginUser(const string& username, const string& password) {
	for (User& user : users) {
		if (user.getUsername() == username && user.authenticate(password)) {
			return &user;
		}
	}

	return nullptr;
}
