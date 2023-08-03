#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

struct Initials {
	std::string name, surname, patronymic;
};
struct Date {
	int day, month, year;
};
struct Address {
	std::string city;
	int home;
};

class Data {
private:
	Initials initials;
	Date date;
	Address address;
public:
	Data();
	Data(Initials initials_, Date date_, Address address_);
	~Data();

	void Print();
	void DataEntry(Initials initials_, Date date_, Address address_);

	Initials GetInitials() { return initials; }
	Date GetDate() { return date; }
	Address GetAddress() { return address; }

	Data& operator= (Data d);
};
