#include <iostream>
#include <fstream>
#include <string>
#include "IPotrubi.h"
#include "ElementA.h"
#include "ElementB.h"
#include "ElementC.h"
#include "ElementD.h"
#include "ElementE.h"
#include "APotrubniPrvek.h"
#include "Potrubi.h"

using namespace std;



string readFile(string name,int size);
int getSize(string name);


int main(int argc, char** argv) {
	string nazev = "potrubi1.txt";
	int velikostPotrubi = getSize(nazev);
	string znaky = readFile(nazev,velikostPotrubi);
	
	Potrubi* potrubi = new Potrubi(znaky,velikostPotrubi);
	cout << "Kontrola " << nazev << endl;
	if (potrubi->JePotrubiOk())
	{	
		cout << "Potrubi je OK" << endl;
	}
	else {
		cout << "Potrubi neni Uzavreno" << endl;
	}
	delete potrubi;
}

string readFile(string name,int velikost)
{
	int i = 0;
	char ch;
	string myArray;
	string myArray2;
	string pom;
	ifstream MyReadFile(name);
	getline(MyReadFile, pom);
	while (getline(MyReadFile, myArray)) {
		myArray2 = myArray2 + myArray;
	}
	return myArray2;
}

int getSize(string name)
{
	ifstream in{};
	string slovo{};
	in.open(name);
	if (in.is_open())
	{
		in >> slovo;
	}
	in.close();
	return stoi(slovo);
}
