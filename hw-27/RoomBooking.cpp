#ifndef ROOMBOOKING_CPP
#define ROOMBOOKING_CPP

#include "RoomBooking.h"

RoomBooking::RoomBooking() : roomNumber(false), daysBooked(nullptr), daysCount(false), customer(nullptr) {}
RoomBooking::RoomBooking(const int roomNumber, const size_t daysCount, Customer* customer)
	: roomNumber(roomNumber), daysCount(daysCount), customer(customer) {
	customer->makeBooking(this);
	daysBooked = new int[daysCount];
	for (size_t i = 0; i < daysCount; i++)
	{
		daysBooked[i] = i + 1;
	}
}
RoomBooking::RoomBooking::RoomBooking(const RoomBooking& other) {
	if (&other == this) {
		roomNumber = other.roomNumber;
		daysCount = other.daysCount;
		customer = other.customer;
		delete[] daysBooked;
		daysBooked = new int[daysCount];
		for (size_t i = 0; i < daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}
}
RoomBooking::RoomBooking(RoomBooking& other) {
	if (&other != this) {
		roomNumber = other.roomNumber;
		daysCount = other.daysCount;
		customer = other.customer;
		other.customer = nullptr;
		delete[] other.daysBooked;
		delete[] daysBooked;
		daysBooked = new int[daysCount];
		for (size_t i = 0; i < daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}
}
void RoomBooking::addDays(const size_t daysCount) {
	this->daysCount += daysCount;
	if (daysBooked != nullptr) {
		delete[] daysBooked;
	}
	daysBooked = new int[this->daysCount];
	for (size_t i = 0; i < this->daysCount; i++)
	{
		daysBooked[i] = i + 1;
	}
}
void RoomBooking::removeDays(const size_t daysCount) {
	if (int(this->daysCount) - int(daysCount) <= 0) {
		delete[] daysBooked;
		customer->cancelBooking();
		customer = nullptr;
		return;
	}
	this->daysCount -= daysCount;
	delete[] daysBooked;
	daysBooked = new int[this->daysCount];
	for (size_t i = 0; i < this->daysCount; i++)
	{
		daysBooked[i] = i + 1;
	}
}
void RoomBooking::printBooking() const {
	if (roomNumber) {
		std::cout << "RoomNumber : " << roomNumber << std::endl;
		std::cout << "DaysCount : " << daysCount << std::endl;;
	}
	else {
		std::cout << "RoomNumber : none" << std::endl;
		std::cout << "DaysCount : none" << std::endl;;
	}
}
RoomBooking& RoomBooking::operator=(const RoomBooking& other) {
	if (&other == this) {
		return *this;
	}
	roomNumber = other.roomNumber;
	daysCount = other.daysCount;
	customer = other.customer;
	delete[] daysBooked;
	daysBooked = new int[daysCount];
	for (size_t i = 0; i < daysCount; i++)
	{
		daysBooked[i] = i + 1;
	}
	return *this;
}
RoomBooking& RoomBooking::operator=(RoomBooking& other) {
	if (&other == this) {
		return *this;
	}
	roomNumber = other.roomNumber;
	daysCount = other.daysCount;
	customer = other.customer;
	delete[] daysBooked;
	daysBooked = other.daysBooked;
	other.roomNumber = false;
	other.daysBooked = nullptr;
	other.daysCount = false;
	other.customer = nullptr;
	return *this;
}
RoomBooking RoomBooking::operator+(const RoomBooking& other) {
	if (other.customer != customer || other.roomNumber != roomNumber) {
		throw std::out_of_range("Customer or room is not same");
	}
	return RoomBooking(roomNumber, daysCount + other.daysCount, customer);
}
std::ostream& operator<<(std::ostream& os, const RoomBooking& other) {
	if (other.roomNumber) {
		os << "RoomNumber : " << other.roomNumber << std::endl;
		os << "DaysCount : " << other.daysCount;
	}
	else {
		os << "RoomNumber : none" << std::endl;
		os << "DaysCount : none";
	}
	
	return os;
}
RoomBooking::~RoomBooking() {
	if (daysCount) {
		delete[] daysBooked;
	}
	if (customer) {
		customer->cancelBooking();
		delete customer;
	}
}

#endif