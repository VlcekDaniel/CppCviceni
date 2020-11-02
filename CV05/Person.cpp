#include "Person.h"
#include <string>

Entity::Person::Person(std::string name, std::string phone, int id)
{
	this->name = name;
	this->phone = phone;
	this->id = id;
}
Entity::Person::Person()
{
}
int Entity::Person::GetId() const {
	return this->id;
}
string Entity::Person::GetPhone() const {
	return this->phone;
}
string Entity::Person::GetName() const {
	return this->name;
}

