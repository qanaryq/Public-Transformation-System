#include "UserProfile.h"

UserProfile::UserProfile() 
	: name(""), gender(""), userType(""), balance(0.0) {
}

string UserProfile::getName() const {
    return name;
}

void UserProfile::setName(const string& newName) {
    name = newName;
}

string UserProfile::getGender() const {
    return gender;
}

void UserProfile::setGender(const string& newGender) {
    gender = newGender;
}

string UserProfile::getUserType() const {
    return userType;
}

void UserProfile::setUserType(const string& newUserType) {
    userType = newUserType;
}

double UserProfile::getBalance() const {
    return balance;
}

void UserProfile::setBalance(double newBalance) {
    balance = newBalance;
}
