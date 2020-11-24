#include "Address.h"

Address::Address()
{
	this->ZIP = 00000;
}

Address::Address(std::string street, std::string town, int ZIP)
{
	this->street = street;
	this->town = town;
	this->ZIP = ZIP;
}

Address::~Address()
{
}

std::ostream& operator<<(std::ostream& os, const Address& obj)
{
	os << obj.street << " " << obj.town << " " << obj.ZIP;
	return os;
}

std::istream& operator>>(std::istream& is, Address& obj)
{
	is >> obj.street >> obj.town >> obj.ZIP;
	return is;
}
