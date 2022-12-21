#include <iostream>
#include "PhoneBook.h"

using namespace std;

void main() {
	cout << "    Phone Book   " << endl;
	Abonent abon("Ron", "911");
	//abon.show();
	//cout << abon << endl;

	const char* name2{"Harry"};
	const char* phone2{ "123" };
	Abonent abon2(name2, phone2);
	
	//cout << abon2 << endl;
	//cout << abon << endl;
	//cin >> abon;
	//cout << abon << endl;

	PhoneBook pb;
	pb.add(abon).add(abon2);
	cout << pb;
	Abonent ab3 = pb[1];
	cout << ab3 << endl;


	int val = 13;
	int& refVal = val;
	const int& refVal2 = val + 9;
	cout << endl;
	int&& RrefVal = val + 6;
	val = 1;
	cout << refVal2 << " " << val << " " << refVal << " " << RrefVal << endl;
	
}