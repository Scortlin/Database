#include "functions.h"

void DataEntry(Data* (&d), int& n) {
	Initials initials;
	Date date;
	Address address;

	cout << "������� ������ �������:  ";
	cin >> n;

	d = new Data[n];
	for (int i = 0; i < n; i++) {
		cout << "������� ���:  ";
		cin >> initials.surname >> initials.name >> initials.patronymic;

		cout << "������� ����: ";
		cin >> date.day >> date.month >> date.year;

		cout << "������� �����: ";
		cin >> address.city >> address.home;

		d[i].DataEntry(initials, date, address);
		cout << "____________________________\n";
	}
}

void DataReading(Data* (&d), int& n, string filename) {
	ifstream reading(filename);
	if (reading) {
		Initials initials;
		Date date;
		Address address;
		
		reading >> n;
		d = new Data[n];
		for (int i = 0; i < n; i++) {
			reading >> initials.surname >> initials.name >> initials.patronymic;
			reading >> date.day >> date.month >> date.year;
			reading >> address.city >> address.home;

			d[i].DataEntry(initials, date, address);

		}
		cout << "������ �������!" << endl;
	}
	else {
		cout << "������ �������� �����" << endl;
	}
	reading.close();
}

void Print(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "������ �" << i + 1 << endl;
		d[i].Print();
		cout << "_____________________________________\n";
	}
}


void DataChange(Data* d, int n) {
	Initials initials;
	Date date;
	Address address;
	int _n;

	cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		cout << "������� ����� ���:  ";
		cin >> initials.surname >> initials.name >> initials.patronymic;

		cout << "������� ����� ����: ";
		cin >> date.day >> date.month >> date.year;

		cout << "������� ����� �����: ";
		cin >> address.city >> address.home;

		d[_n].DataEntry(initials, date, address);
	}
	else {
		cout << "����� ����� �������!!!" << endl;
	}
}

void Copy(Data* d_n, Data* d_o, int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void AddData(Data* (&d), int& n) {
	Initials initials;
	Date date;
	Address address;
	Data* buf = new Data[n];
	int size = n; int new_size = ++n;
	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);
	cout << "������� ����� ���:  ";
	cin >> initials.surname >> initials.name >> initials.patronymic;

	cout << "������� ����� ����: ";
	cin >> date.day >> date.month >> date.year;

	cout << "������� ����� �����: ";
	cin >> address.city >> address.home;

	d[size].DataEntry(initials, date, address);

	cout << "������ ���������!" << endl;
	delete[] buf;
}

void DeleteData(Data* (&d), int& n) {
	int _n;
	Data* buf = new Data[n];

	cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}
		cout << "������ �������!" << endl;
	}
	else {
		cout << "����� ����� �������!!!" << endl;
	}
	delete[] buf;
}

void SortingData(Data* d, int n) {
	Data buf;
	int numOfSorted = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].GetInitials().surname > d[j].GetInitials().surname) {
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numOfSorted++;
			}
		}
	}
	cout << "������ �������������. ���������� ����������: " << numOfSorted << endl;
}

void SaveData(Data* d, int n, string filename) {
	ofstream record(filename);

	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patronymic << endl;
			record << d[i].GetDate().day << "." << d[i].GetDate().month << "." << d[i].GetDate().year<<endl;
			record << d[i].GetAddress().city << " " << d[i].GetAddress().home;

			if (i < n - 1) {
				record << endl;
			}
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	cout << "������ ��������� � ����:  " << filename<<endl;
	record.close();
}