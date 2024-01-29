#include "Vehicle.h"

Vehicle::Vehicle(string vehicleCode, int capacity, double ticketPrice) {
	this -> vehicleCode = vehicleCode;
	this -> capacity = capacity;
	this -> ticketPrice = ticketPrice;
	this -> totalProfit = 0;
}

Vehicle::~Vehicle() {
}

string Vehicle::getVehicleCode() {
	return vehicleCode;
}

int Vehicle::getCapacity() {
	return capacity;
}

double Vehicle::getTicketPrice() {
	return ticketPrice;
}

double Vehicle::getTotalProfit() {
	return totalProfit;
}
