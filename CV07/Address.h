#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
struct Address
{
public:
	Address();
	Address(std::string street, std::string town, int ZIP);
	~Address();
	friend std::ostream& operator<<(std::ostream& os, const Address& obj);
	friend std::istream& operator>>(std::istream& is, Address& obj);
private:
	std::string street;
	std::string town;
	int ZIP;
};
#endif // !ADDRESS_H
