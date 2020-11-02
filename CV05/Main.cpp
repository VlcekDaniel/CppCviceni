#include "Person.h"
#include "Phonebook.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
using namespace Entity;
using namespace Model;

int main(int argc, char** argv) {

	Phonebook* phonebook = new Model::Phonebook();
	Person* person1 = new Person("Jmeno1", "123456789", 1);
	Person* person2 = new Person("Jmeno2", "223456789", 2);
	Person* person3 = new Person("Jmeno3", "323456789", 3);
	Person* person4 = new Person("Jmeno4", "423456789", 4);
	Person* person5 = new Person("Jmeno5", "523456789", 5);

	phonebook->AddPerson(*person1);
	phonebook->AddPerson(*person2);
	phonebook->AddPerson(*person3);
	phonebook->AddPerson(*person4);
	phonebook->AddPerson(*person5);

	cout << phonebook->FindPhone(3)<< endl;
	cout << phonebook->FindPhone(5) << endl;
	cout << phonebook->FindPhone("Jmeno3") << endl;
	cout << phonebook->FindPhone("Jmeno5") << endl;

	delete person1, person2, person3, person4, person5;
	delete phonebook;
}