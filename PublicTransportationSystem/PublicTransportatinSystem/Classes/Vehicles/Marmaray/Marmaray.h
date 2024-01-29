#pragma once

#include "../Vehicle.h"

class Marmaray : public Vehicle {
	public:
		Marmaray(string vehicleCode, int capacity, double ticketPrice);
		~Marmaray();

		static int getTotalMarmarayCount();
		
	private:
		static int totalMarmarayCount;
};
