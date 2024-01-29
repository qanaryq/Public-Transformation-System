#include "Marmaray.h"

int Marmaray::totalMarmarayCount = 0;

Marmaray::Marmaray(string vehicleCode, int capacity, double ticketPrice)
	: Vehicle(vehicleCode, capacity, ticketPrice) {
	totalMarmarayCount++;
}

Marmaray::~Marmaray() {
	totalMarmarayCount--;
}

int Marmaray::getTotalMarmarayCount() {
	return totalMarmarayCount;
}
