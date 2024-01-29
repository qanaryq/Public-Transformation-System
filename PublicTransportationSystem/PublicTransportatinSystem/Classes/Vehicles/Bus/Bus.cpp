#include "Bus.h"

int Bus::totalBusCount = 0;

Bus::Bus(string vehicleCode, int capacity, double ticketPrice)
	: Vehicle(vehicleCode, capacity, ticketPrice) {
	totalBusCount++;
}

Bus::~Bus() {
	totalBusCount--;
}

int Bus::getTotalBusCount() {
	return totalBusCount;
}
