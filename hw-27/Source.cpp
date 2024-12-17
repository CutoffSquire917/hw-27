#include <iostream>
using namespace std;

class Customer {
private:
	string name;
	int customerID;
	static int countID;
	RoomBooking* currentBooking;
public:
	Customer(const string name) : name(name), customerID(countID), currentBooking(nullptr) { countID++; }
	Customer(const string name, RoomBooking* currentBooking)
		: name(name), customerID(countID), currentBooking(currentBooking) {
		countID++;
	}
	void makeBooking(RoomBooking* booking) {
		currentBooking = booking;
	}
	void cancelBooking() {
		currentBooking = nullptr;
	}
	void printCustomerInfo() const {
		cout << "Name : " << name << endl;
		cout << "ID : " << customerID << endl;
	}

	~Customer() {
		delete currentBooking;
	}
};

int Customer::countID = 1;

//���� Customer
//����:

//std::string name � ��� �볺���.
//int customerID � ��������� ������������� �볺���.
//RoomBooking* currentBooking � �������� �� ������� ���������� (���� ���� nullptr, ���� ���������� ����).
//������������:

//����������� �� �������������: ������� �볺��� ��� ����������.
//���������������� �����������: ������ ��� �볺��� �� ���� ID.
//����������:

//������� �������, ������� � ����������� (�� �������).
//������:

//void makeBooking(RoomBooking* booking) � ������ �볺��� � �����������.
//void cancelBooking() � ������� ������� ����������, ��������� ������ �� �볺����.
//void printCustomerInfo() � �������� ��� �볺���, ID �� ���������� ��� ����������.
//�������������� ���������:

//�������� << ��� ��������� ���������� ��� �볺���.

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
		daysBooked = new int[daysCount];
		for (size_t i = 0; i < daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}


	//����������� ���������: ������� ������� ���� �ᒺ���, ��������� ������ �� �볺����.



	//����������� ����������: ������ ������� (����� ��� � ������ �� �볺����).

	//void addDay(int day) � ���� ���� � ������ �������������.
	void addDays(const int daysCount) {
		this->daysCount += daysCount;
		delete daysBooked;
		daysBooked = new int[daysCount];
		for (size_t i = 0; i < this->daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}
	//void removeDay(int day) � ������� ���� �� ������ �������������.
	void removeDays(const int daysCount) {
		if (this->daysCount - daysCount <= 0) {
			daysBooked = nullptr;
			this->daysCount = false;
			return;
		}
		this->daysCount -= daysCount;
		delete daysBooked;
		daysBooked = new int[this->daysCount];
		for (size_t i = 0; i < this->daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}
	//void printBooking() � �������� ���������� ��� ����������.
	void printBooking() const {
		cout << "roomNumber : " << roomNumber << endl;
		cout << "daysCount : " << daysCount << endl;
	}

	//�������� = ��� ���������.
	//�������� = ��� ����������.
	//�������� + ��� �ᒺ������ ��������� (� ���������, �� �볺�� ��� �����).
	//�������� << ��� ��������� ���������� ��� �ᒺ��.

	~RoomBooking() {
		if (daysCount) {
			delete daysBooked;
		}
		if (customer != nullptr) {
			delete customer;
		}

	}
};

//���� RoomBooking
//����:

//int roomNumber � ����� ������.
//int* daysBooked � �������� �� ����� ���, �� �� ������������ �����.
//(���������, ����� {1, 2, 3} ������, �� ����� ������������ �� 1-�, 2-� � 3-� �� �����. ���� ����� �������, ������ �����.)
//size_t daysCount � ������� ���, �� �� ������������ �����.
//Customer* customer � �������� �� �볺���, ���� ���������� ������.
//������������:

//����������� �� �������������: ������� ������ ����������.
//���������������� �����������: ������ ����� ������, ����� ���, ������� ��� �� �������� �� �볺���.
//����������� ���������: ������� ������� ���� �ᒺ���, ��������� ������ �� �볺����.
//����������� ����������: ������ ������� (����� ��� � ������ �� �볺����).
//����������:

//������� ������, ������� ��� ������ ���.
//������:

//void addDay(int day) � ���� ���� � ������ �������������.
//void removeDay(int day) � ������� ���� �� ������ �������������.
//void printBooking() � �������� ���������� ��� ����������.
//�������������� ���������:

//�������� = ��� ���������.
//�������� = ��� ����������.
//�������� + ��� �ᒺ������ ��������� (� ���������, �� �볺�� ��� �����).
//�������� << ��� ��������� ���������� ��� �ᒺ��.

int main()
{


}