#include "User.h"

User::User(const string& username, const string& password) 
	: username(username), password(password) {
}

string User::getUsername() const {
	return username;
}

string User::getPassword() const {
	return password;
}

string User::getUserType() const {
	return userType;
}

bool User::authenticate(const string& password) const {
	return (this -> password == password);
}
