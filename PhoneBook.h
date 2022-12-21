#pragma once
#include <iostream>

using namespace std;

class Abonent {
	char* name;
	char* phone;

public:
	Abonent() {
		name = new char[0];
		phone = new char[0];
	}

	Abonent(const char* name,
		const char* phone) {
		int sz1 = strlen(name) + 1;
		int sz2 = strlen(phone) + 1;
		this->name = new char[sz1];
		this->phone = new char[sz2];

		for (int k = 0; k < sz1; ++k)
			this->name[k] = name[k];
		for (int k = 0; k < sz2; ++k)
			this->phone[k] = phone[k];
	}

	Abonent(const Abonent& abon) : Abonent(abon.name, abon.phone) {	}
	
	Abonent& operator=(Abonent& abon) {
		if (this != &abon) {
			if(name) delete[] name;
			if(phone) delete[] phone;
			int sz1 = strlen(abon.name) + 1;
			int sz2 = strlen(abon.phone) + 1;
			name = new char[sz1];
			phone = new char[sz2];

			for (int k = 0; k < sz1; ++k)
				this->name[k] = abon.name[k];
			for (int k = 0; k < sz2; ++k)
				this->phone[k] = abon.phone[k];
		}
		return *this;
	}
	
	~Abonent() {
		if(phone) delete[] phone;
		if(name) delete[] name;
	}
	
	void show() const {
		cout << name << " " << phone << endl;
	}

	friend ostream& operator<<(ostream& stream,
		Abonent& abon);
	friend istream& operator>>(istream& stream,
		Abonent& abon);
};



class PhoneBook{
	Abonent* abonents;
	int size;
public:

	PhoneBook();

	~PhoneBook() {
		delete[] abonents;
	}
	PhoneBook(PhoneBook& pb) {
		if(size > 0)
			delete[] abonents;
		if (pb.size > 0) {
			abonents = new Abonent[pb.size];
			for (int k = 0; k < pb.size; ++k) {
				abonents[k] = pb.abonents[k];
			}
			size = pb.size;
		}
	}

	PhoneBook& operator=(PhoneBook& pb) {
		if (size > 0)
			delete[] abonents;
		if (pb.size > 0) {
			abonents = new Abonent[pb.size];
			for (int k = 0; k < pb.size; ++k) {
				abonents[k] = pb.abonents[k];
			}
			size = pb.size;
		}
	}

	PhoneBook& add(Abonent abon) {
		Abonent* buff = new Abonent[size + 1];
		for (int k = 0; k < size; ++k)
			buff[k] = abonents[k];
		buff[size] = abon;
		delete[] abonents;
		size++;
		abonents = buff;
		return *this;
	}

	void show() {
		for (int k = 0; k < size; ++k) {
			cout << abonents[k] << endl;
		}
	}

	friend ostream& operator<<(ostream& stream,	PhoneBook& pb);

	Abonent& operator[](int id) {		
		return abonents[id];
	}
};

