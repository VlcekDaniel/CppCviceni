#include <iostream>
#include <fstream>
#include "Person.h"
#include <stdlib.h>

using namespace std;

void save(){
	Address adress = Address(string("Komenskeho 23"),string("Sazava"), 28532);
	Date date = Date(20, 12, 2020);
	int pocet = 3;
	Person person1 = Person(string("Daniel"),string("Novak"), adress, date);
	Person person2 = Person(string("Jan"), string("Novak"), adress, date);
	Person person3 = Person(string("Josef"), string("Novak"), adress, date);
	Person* arr = new Person[pocet];
	arr[0] = person1;
	arr[1] = person2;
	arr[2] = person3;

	ofstream out{ "output.dat", ios_base::out, ios_base::binary };
	if (out.is_open()) {
		for (int i = 0; i < 3; i++) {
			out.write((char*)&arr[i], sizeof(Person));
		}
		out.close();
	}
	else
		cerr << "Unable to open" << endl;	
	delete[] arr;
}

void load(Person* array){
	ifstream in{ "output.dat", ios_base::in, ios_base::binary};
	if (in.is_open()) {
		in.read((char *)array,3* sizeof(Person));
		in.close();
	}
	else
		cerr << "Unable to open" << endl;
}

int main(int argc, char** argv) {

	save();
	cout << "saving" << endl;
	Person* arr = new Person[3]; 
	load(arr);
	cout << "loading" << endl;

	for (size_t i = 0; i < 3; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "print" << endl;
}