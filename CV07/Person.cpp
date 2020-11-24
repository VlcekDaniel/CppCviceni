#include "Person.h"

Person::Person()
{
}

Person::Person(std::string name, std::string surname, Address permanentResidence, Date birthdate)
{
	this->name = name;
	this->surname = surname;
	this->permanentResidence = permanentResidence;
	this->birthdate = birthdate;
}

Person::~Person()
{
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	os << obj.name << " " << obj.surname << " " << obj.permanentResidence<<" "<<obj.birthdate;
	return os;
}

std::istream& operator>>(std::istream& is, Person& obj)
{
	is >> obj.name >> obj.surname >> obj.permanentResidence>> obj.birthdate;
	return is;
}
