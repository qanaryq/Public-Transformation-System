#pragma once

#include "../Vehicle.h"

class Metrobus : public Vehicle {
	public:
		Metrobus(string vehicleCode, int capacity, double ticketPrice);
		~Metrobus();

		static int getTotalMetrobusCount();

	private:
		static int totalMetrobusCount;
};
