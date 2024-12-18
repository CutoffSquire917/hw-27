#pragma once
#ifndef ROOMBOOKING_H
#define ROOMBOOKING_H

#include <stdexcept>
#include <iostream>
#include "Customer.h"
class Customer;

class RoomBooking {
private:
	int roomNumber;
	int* daysBooked;
	size_t daysCount;
	Customer* customer;
public:
	RoomBooking();
	RoomBooking(const int roomNumber, const size_t daysCount, Customer* customer);
	RoomBooking(const RoomBooking& other);
	RoomBooking(RoomBooking& other);
	void addDays(const size_t daysCount);
	void removeDays(const size_t daysCount);
	void printBooking() const;
	RoomBooking& operator=(RoomBooking& other);
	RoomBooking& operator=(const RoomBooking& other);
	RoomBooking operator+(const RoomBooking& other);
	friend std::ostream& operator<<(std::ostream& os, const RoomBooking& other);
	~RoomBooking();
};

#endif