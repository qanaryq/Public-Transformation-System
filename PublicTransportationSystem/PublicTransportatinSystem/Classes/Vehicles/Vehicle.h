#pragma once

#include <string>

using namespace std;

class Vehicle {
	public:
		Vehicle(string vehicleCode, int capacity, double ticketPrice);
		virtual ~Vehicle() = 0;

		string getVehicleCode();
		int getCapacity();
		double getTicketPrice();
		double getTotalProfit();

	private:
		string vehicleCode;
		int capacity;
		double ticketPrice;
		double totalProfit;
};
