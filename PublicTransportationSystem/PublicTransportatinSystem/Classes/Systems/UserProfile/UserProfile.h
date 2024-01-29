#pragma once

#include <string>

using namespace std;

class UserProfile {
	public:
		UserProfile();
		
		string getName() const;
		void setName(const string& newName);

		string getGender() const;
		void setGender(const string& newGender);

		string getUserType() const;
		void setUserType(const string& newUserType);

		double getBalance() const;
		void setBalance(double newBalance);

	private:
		string name;
		string gender;
		string userType;
		double balance;
};
