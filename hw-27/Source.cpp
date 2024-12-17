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

//Клас Customer
//Поля:

//std::string name — ім’я клієнта.
//int customerID — унікальний ідентифікатор клієнта.
//RoomBooking* currentBooking — вказівник на поточне бронювання (може бути nullptr, якщо бронювання немає).
//Конструктори:

//Конструктор за замовчуванням: Створює клієнта без бронювання.
//Параметризований конструктор: Приймає ім’я клієнта та його ID.
//Деструктор:

//Звільняє ресурси, пов’язані з бронюванням (за потреби).
//Методи:

//void makeBooking(RoomBooking* booking) — пов’язує клієнта з бронюванням.
//void cancelBooking() — скасовує поточне бронювання, видаляючи зв’язок із клієнтом.
//void printCustomerInfo() — виводить ім’я клієнта, ID та інформацію про бронювання.
//Перевантаження операторів:

//Оператор << для виведення інформації про клієнта.

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


	//Конструктор копіювання: Створює глибоку копію об’єкта, включаючи зв’язок із клієнтом.



	//Конструктор переміщення: Передає ресурси (масив днів і зв’язок із клієнтом).

	//void addDay(int day) — додає день у список заброньованих.
	void addDays(const int daysCount) {
		this->daysCount += daysCount;
		delete daysBooked;
		daysBooked = new int[daysCount];
		for (size_t i = 0; i < this->daysCount; i++)
		{
			daysBooked[i] = i + 1;
		}
	}
	//void removeDay(int day) — видаляє день із списку заброньованих.
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
	//void printBooking() — виводить інформацію про бронювання.
	void printBooking() const {
		cout << "roomNumber : " << roomNumber << endl;
		cout << "daysCount : " << daysCount << endl;
	}

	//Оператор = для копіювання.
	//Оператор = для переміщення.
	//Оператор + для об’єднання бронювань (з перевіркою, що клієнт той самий).
	//Оператор << для виведення інформації про об’єкт.

	~RoomBooking() {
		if (daysCount) {
			delete daysBooked;
		}
		if (customer != nullptr) {
			delete customer;
		}

	}
};

//Клас RoomBooking
//Поля:

//int roomNumber — номер кімнати.
//int* daysBooked — вказівник на масив днів, на які заброньовано номер.
//(Наприклад, масив {1, 2, 3} означає, що номер заброньовано на 1-й, 2-й і 3-й дні місяця. Якщо масив порожній, кімната вільна.)
//size_t daysCount — кількість днів, на які заброньовано номер.
//Customer* customer — вказівник на клієнта, який забронював кімнату.
//Конструктори:

//Конструктор за замовчуванням: Створює порожнє бронювання.
//Параметризований конструктор: Приймає номер кімнати, масив днів, кількість днів та вказівник на клієнта.
//Конструктор копіювання: Створює глибоку копію об’єкта, включаючи зв’язок із клієнтом.
//Конструктор переміщення: Передає ресурси (масив днів і зв’язок із клієнтом).
//Деструктор:

//Звільняє пам’ять, виділену для масиву днів.
//Методи:

//void addDay(int day) — додає день у список заброньованих.
//void removeDay(int day) — видаляє день із списку заброньованих.
//void printBooking() — виводить інформацію про бронювання.
//Перевантаження операторів:

//Оператор = для копіювання.
//Оператор = для переміщення.
//Оператор + для об’єднання бронювань (з перевіркою, що клієнт той самий).
//Оператор << для виведення інформації про об’єкт.

int main()
{


}