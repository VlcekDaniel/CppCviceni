#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include "Date.h"
#include "Address.h"
struct Person
{
public:
	Person();
	Person(std::string name, std::string surname, Address permanentResidence, Date birthdate);
	~Person();
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
	friend std::istream& operator>>(std::istream& is, Person& obj);
private:
	std::string name;
	std::string surname;
	Address permanentResidence;
	Date birthdate;
};
#endif // PERSON_H
