#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#include "Classes/Systems/AuthService/AuthService.h"
#include "Classes/Systems/UserProfile/UserProfile.h"

#include "Classes/Vehicles/Bus/Bus.h"
#include "Classes/Vehicles/Marmaray/Marmaray.h"
#include "Classes/Vehicles/Metrobus/Metrobus.h"

using namespace std;

int main() {
	AuthService authService;
	UserProfile userProfile = UserProfile();

	bool isAdminTriedLoggedIn = false;
	bool isAdminLoggedIn = false;
	bool mustContinueRunning = true;

	cout << "\n---------------------------- Welcome To Public Transportation Management System ------------------------\n\n";

	while (mustContinueRunning) {
		if (!isAdminTriedLoggedIn) {
			cout << "1. Admin Login" << endl;
			cout << "2. Register" << endl;
			cout << "3. Exit" << endl;
		} else {
			cout << "1. Show Profile" << endl;
			cout << "2. Choose Public Transport" << endl;
			cout << "3. Exit" << endl;
		}

		cout << "Enter your choice: ";

		string choice_string;
		getline(cin, choice_string);

		if (choice_string.length() != 1 || !isdigit(choice_string[0])) {
			cout << "Invalid choice. Please enter a valid option.\n";
			this_thread::sleep_for(chrono::seconds(3));
			system("cls");
			continue;
		}

		int choice = stoi(choice_string);
	
		if (choice == 1) {
			cout << "LOGGED AS ADMIN\n";
			isAdminTriedLoggedIn = true;
			isAdminLoggedIn = true;
		} else {
			isAdminTriedLoggedIn = true;
			cout << "LOGGED AS USER\n";
		}

		if (!isAdminLoggedIn) {
			if (choice == 1) {
				system("cls");

				cout << "Name: " << userProfile.getName() << endl;
				cout << "Gender: " << userProfile.getGender() << endl;
				cout << "User Type: " << userProfile.getUserType() << endl;
				cout << "Balance: " << userProfile.getBalance() << endl;

				cout << "1. Add Balance\n";
				cout << "Press Enter to go back to the main menu...\n";
				string ch_str = "";
				getline(cin, ch_str);
				char ch = ch_str[0];
				system("cls");

				if (ch == '\r') {
					continue;
				} else if (ch == '1') {
					double amount;
					cout << "Enter the amount to add to your balance: ";
					cin >> amount;
					userProfile.setBalance(userProfile.getBalance() + amount);
					cout << "Balance updated. New balance: " << userProfile.getBalance() << endl;
					this_thread::sleep_for(chrono::seconds(3));
					system("cls");
				}
			} else if (choice == 2) {
				system("cls");

				vector<string> publicTransportOptions = { "Bus", "Subway", "Metrobus", "Marmaray", "Minibus" };

				cout << "Choose a public transport option:\n";
				for (int i = 0; i < publicTransportOptions.size(); i++) {
					cout << i + 1 << ". " << publicTransportOptions[i] << endl;
				}

				int transportChoice;
				cin >> transportChoice;

				if (transportChoice >= 1 && transportChoice <= publicTransportOptions.size()) {
					string chosenTransport = publicTransportOptions[transportChoice - 1];

					if (chosenTransport == "Bus") {
						Bus bus("15BK", 10, 7.52);
					} else if (chosenTransport == "Metrobus") {
						Metrobus metrobus("C-140", 20, 10.50);
					} else if (chosenTransport == "Marmaray") {
						Marmaray marmaray("M-140", 30, 15.00);
					}

					cout << "You have chosen " << chosenTransport << " as your public transport option.\n";
					this_thread::sleep_for(chrono::seconds(3));
					system("cls");
				} else {
					cout << "Invalid choice. Please select a valid option.\n";
					this_thread::sleep_for(chrono::seconds(3));
				}
			} else if (choice == 3) {
				system("cls");
				cout << "Goodbye!\n";
				this_thread::sleep_for(chrono::seconds(3));
				system("cls");
				mustContinueRunning = false;
			} else {
				cout << "Invalid choice. Please enter a valid option.\n";
				this_thread::sleep_for(chrono::seconds(3));
			}
		} else {
			if (choice == 2) {
				system("cls");

				string username, password, gender, userType;

				cout << "Enter username: ";
				getline(cin, username);
				cout << "Enter password: ";
				getline(cin, password);

				while (gender != "m" && gender != "f") {
					cout << "Enter gender (m for male, f for female): ";
					getline(cin, gender);

					if (gender != "m" && gender != "f") {
						cout << "Invalid gender. Please enter 'm' for male or 'f' for female.\n";
					}
				}

				bool isValidChoice = false;

				while (!isValidChoice) {

					cout << "Select user type:" << endl;
					cout << "1. Student" << endl;
					cout << "2. Adult" << endl;
					cout << "3. Teacher" << endl;
					cout << "4. Senior (65+)" << endl;

					string userTypeChoice;
					getline(cin, userTypeChoice);

					if (userTypeChoice.length() != 1 && !isdigit(userTypeChoice[0])) {
						cout << "Invalid choice. Please enter a valid option.\n";
						this_thread::sleep_for(chrono::seconds(3));
						system("cls");
						continue;
					}

					int userTypeChoiceInt = stoi(userTypeChoice);

					if (userTypeChoiceInt < 1 || userTypeChoiceInt > 4) {
						cout << "Invalid user type choice. Please select 1, 2, 3, or 4.\n";
					}
					else {
						switch (userTypeChoiceInt) {
							case 1:
								userType = "Student";
								break;
							case 2:
								userType = "Adult";
								break;
							case 3:
								userType = "Teacher";
								break;
							case 4:
								userType = "Senior";
								break;
							default:
								isValidChoice = true;
								break;

						}
					}
				}

				userProfile.setName(username);
				userProfile.setGender((gender == "m") ? "Male" : "Female");
				userProfile.setUserType(userType);

				authService.registerUser(username, password);

				cout << "User registered successfully.\n";
				this_thread::sleep_for(chrono::seconds(3));
				system("cls");
			} else if (choice == 3) {
				system("cls");
				cout << "Goodbye!\n";
				this_thread::sleep_for(chrono::seconds(3));
				system("cls");
				mustContinueRunning = false;
			} else {
				cout << "Invalid choice. Please enter a valid option.\n";
				this_thread::sleep_for(chrono::seconds(3));
			}
		}
	}
}
