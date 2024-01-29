#include "Metrobus.h"

int Metrobus::totalMetrobusCount = 0;

Metrobus::Metrobus(string vehicleCode, int capacity, double ticketPrice)
	: Vehicle(vehicleCode, capacity, ticketPrice) {
	totalMetrobusCount++;
}

Metrobus::~Metrobus() {
	totalMetrobusCount--;
}

int Metrobus::getTotalMetrobusCount() {
	return totalMetrobusCount;
}
