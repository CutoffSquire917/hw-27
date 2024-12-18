#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "Customer.h"

Customer::Customer() : name(""), customerID(false), currentBooking(nullptr) {}
Customer::Customer(const std::string& name)
	: name(name), customerID(countID++), currentBooking(nullptr) {
}
void Customer::makeBooking(RoomBooking* booking) {
	currentBooking = booking;
}
void Customer::cancelBooking() {
	currentBooking = nullptr;
}
void Customer::printCustomerInfo() const {
	if (name != "") {
		std::cout << "Name : " << name << std::endl;
		std::cout << "ID : " << customerID << std::endl;
	}
	else {
		std::cout << "Name : none" << std::endl;
		std::cout << "ID : none" << std::endl;
	}
	if (currentBooking != nullptr) {
		currentBooking->printBooking();
	}
	else {
		std::cout << "RoomNumber : none" << std::endl;
		std::cout << "DaysCount : none" << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const Customer& other) {
	if (other.name != "") {
		os << "Name : " << other.name << std::endl;
		os << "ID : " << other.customerID;
	}
	else {
		os << "Name : none" << std::endl;
		os << "ID : none";
	}
	return os;
}
Customer::~Customer() {
	delete currentBooking;
}

int Customer::countID = 1;

#endif