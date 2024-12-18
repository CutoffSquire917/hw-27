#include <iostream>
using namespace std;

class RoomBooking;

class Customer {
private:
	string name;
	int customerID;
	static int countID;
	RoomBooking* currentBooking;
public:
	Customer() : name(""), customerID(false), currentBooking(nullptr) {}
	Customer(const string& name)
		: name(name), customerID(countID++), currentBooking(nullptr) {}
	void makeBooking(RoomBooking* booking) {
		currentBooking = booking;
	}
	void cancelBooking() {
		currentBooking = nullptr;
	}
	void printCustomerInfo() const {
		cout << "Name : " << name << endl;
		cout << "ID : " << customerID << endl;
		if (currentBooking != nullptr) {
			//currentBooking->printBooking();
			cout << "Fuck off" << endl;
		}
		else {
			cout << "No current booking" << endl;
		}
	}
	friend ostream& operator<<(ostream& os, const Customer& other) {
		os << "Name : " << other.name << endl;
		os << "ID : " << other.customerID;
		return os;
	}
	~Customer() {
		delete currentBooking;
	}
};

int Customer::countID = 1;

class RoomBooking {
private:
	int roomNumber;
	int* daysBooked;
	size_t daysCount;
	Customer* customer;
public:
	RoomBooking() : roomNumber(false), daysBooked(nullptr), daysCount(false), customer(nullptr) {}
	RoomBooking(const int roomNumber, const size_t daysCount, Customer* customer)
		: roomNumber(roomNumber), daysCount(daysCount), customer(customer) {
		customer->makeBooking(this);
		daysBooked = new int[daysCount];
		for (size_t i = 0; i < daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}
	RoomBooking(const RoomBooking &other) {
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
	RoomBooking(RoomBooking& other) {
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
	void addDays(const size_t daysCount) {
		this->daysCount += daysCount;
		delete[] daysBooked;
		daysBooked = new int[this->daysCount];
		for (size_t i = 0; i < this->daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}
	void removeDays(const size_t daysCount) {
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
	void printBooking() const {
		cout << "roomNumber : " << roomNumber << endl;
		cout << "daysCount : " << daysCount << endl;
	}
	RoomBooking operator=(const RoomBooking& other) {
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
	RoomBooking operator=(RoomBooking& other) {
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
	RoomBooking operator+(const RoomBooking& other) {
		if (other.customer != customer || other.roomNumber != roomNumber) {
			throw std::out_of_range("Customer or room is not same");
		}
		return RoomBooking(roomNumber, daysCount + other.daysCount, customer);
	}
	friend ostream& operator<<(ostream& os, const RoomBooking& other) {
		if (!other.customer) {
			return os;
		}
		os << "roomNumber : " << other.roomNumber << endl;
		os << "daysCount : " << other.daysCount;
		return os;
	}
	~RoomBooking() {
		if (daysCount) {
			delete[] daysBooked;
		}
		if (customer) {
			customer->cancelBooking();
			delete customer;
		}
	}
};

int main()
{
	Customer* Ivan = new Customer("Ivan");
	cout << *Ivan << endl;
	RoomBooking* nomer16 = new RoomBooking(16, 7, Ivan);
	RoomBooking* nomer17 = new RoomBooking(16, 7, Ivan);
	RoomBooking nomer18 = *nomer16 + *nomer17;
	//RoomBooking* nomer17 = new RoomBooking(16, 3, Ivan);
	//nomer16 = nomer16 + nomer17;
	cout << nomer18 << endl;
	cout << endl;
	Ivan->printCustomerInfo();
}