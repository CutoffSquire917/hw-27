#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdexcept>
#include <iostream>
#include "RoomBooking.h"
class RoomBooking;

class Customer {
private:
	std::string name;
	int customerID;
	static int countID;
	RoomBooking* currentBooking;
public:
	Customer();
	Customer(const std::string& name);
	void makeBooking(RoomBooking* booking);
	void cancelBooking();
	void printCustomerInfo() const;
	friend std::ostream& operator<<(std::ostream& os, const Customer& other);
	~Customer();
};

#endif