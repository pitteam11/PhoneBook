#include <iostream>

using namespace std;

class DA {
	int size;
	int* arr;

public:
	DA() {
		arr = new int[0];
		cout << "Default constructor " << this << endl;
	}

	explicit DA(int size) : size{ size }, arr{ new int[size] } {
		for (int k = 0; k < size; k++)
			arr[k] = k;
		cout << "Int constructor " << this << endl;
	}

	DA(const DA& object) : 
		arr{new int[size]},
		size {object.size}  {
		for (int k = 0; k < size; k++)
			arr[k] = object.arr[k];
		cout << "Copy constructor " << this << endl;
	}

	DA& operator=(const DA& object) {
		if (this != &object) {
			if (size != object.size) {
				delete[] arr;
				size = object.size;
				arr = new int[size];
			}
			for (int k = 0; k < size; k++)
				arr[k] = object.arr[k];
		}
		cout << "Copy operator " << this << endl;
		return *this;
	}

	DA(DA&& object) :
		arr{ object.arr },
		size{object.size}	{
		object.arr = nullptr;
		object.size = 0;
		cout << "Move constructor " << this << endl;
	}

	DA& operator=(DA&& object) {
		if (this != &object) {
			delete[] arr;
			size = object.size;
			arr = object.arr;
			object.arr = nullptr;
			object.size = 0;
		}
		cout << "Move operator " << this << endl;
		return *this;
	}

	~DA() {
		cout << "Destructor " << this << endl;
		delete[] arr;
	}

	DA& add(int val) {
		int* buff = new int[size + 1];
		for (int k = 0; k < size; k++)
			buff[k] = arr[k];
		buff[size] = val;
		size++;
		delete[] arr;
		arr = buff;
		return *this;
	}

	int operator[](int id){
		if(id >= 0 && id < size)
			return arr[id];
		return 0;
	}


};

void test_CC_CO_CM_OM() {
	cout << "Hello" << endl;
	DA dynArray;
	dynArray.add(4).add(5).add(7);
		
	cout << "operator[]: " << dynArray[2] << endl;

	DA dynArray2 = dynArray;

	DA dynArray3;
	dynArray3 = dynArray;

	DA dynArray4 = DA(4);

	DA dynArray5;
	dynArray5 = DA(4);

	//DA dd = 4;
}

class Wupsen {
	int x;
	int y;
	friend class Pupsen;
};

class Pupsen {
public:
	void dosmth() {
		Wupsen wup;
		wup.x = 10;
		wup.y = 11;
		cout << wup.x << " " << wup.y << endl;
	}
};

class Dad {
protected:
	int x;
	int y;
};

class Son : Dad {
public:
	void dosmth() {
		//Dad::x = 10; 
		//Dad::y = 11;
		x = 15;
		y = 17;
		cout << Dad::x << " " << Dad::y << endl;
		cout << x << " " << y << endl;
	}
};

void test_strange_copyer() {
	int size = 5;
	int* object_arr = new int[size] {1, 2, 3, 4, 5};
	int* arr = new int[size];

	int* src{ object_arr };
	int* dst{ arr };
	int* end{ arr + size };
	while (dst < end) {
		*dst++ = *src++;
	}

	for (int k = 0; k < size; k++)
		cout << arr[k] << " ";
	cout << endl;

	delete[] arr;
}


void main() {
	//test_CC_CO_CM_OM();
	Pupsen pup;
	pup.dosmth();

	Son son;
	son.dosmth();
}