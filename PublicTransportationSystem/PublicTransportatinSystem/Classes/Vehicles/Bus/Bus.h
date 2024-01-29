#pragma once

#include "../Vehicle.h"

class Bus : public Vehicle {
	public:
		Bus(string vehicleCode, int capacity, double ticketPrice);
		~Bus();

		static int getTotalBusCount();
	
	private:
		static int totalBusCount;
};
