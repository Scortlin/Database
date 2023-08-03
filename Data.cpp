#include "Data.h"
using namespace std;
Data::Data() {
	initials.surname = "";
	initials.name = "";
	initials.patronymic = "";

	date.day = 0;
	date.month = 0;
	date.year = 0;

	address.city = "";
	address.home = 0;
}
Data::Data(Initials initials_, Date date_, Address address_) {
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patronymic = initials_.patronymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.city = address_.city;
	address.home = address_.home;

}
Data::~Data() {
}

void Data::Print() {
	cout << "ÔÈÎ:  " << initials.surname <<" " << initials.name <<" " << initials.surname << endl;
	cout << "Äàòà:  " << date.day <<"." << date.month <<"." << date.year << endl;
	cout << "Àäğåñ:  " << address.city <<" " << address.home << endl;
}

void Data::DataEntry(Initials initials_, Date date_, Address address_) {
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patronymic = initials_.patronymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.city = address_.city;
	address.home = address_.home;
}

Data& Data::operator=(Data d) {
	this->initials.surname = d.initials.surname;
	this->initials.name = d.initials.name;
	this->initials.patronymic = d.initials.patronymic;

	this->date.day = d.date.day;
	this->date.month = d.date.month;
	this->date.year = d.date.year;
	
	this->address.city = d.address.city;
	this->address.home = d.address.home;
	return *this;
}