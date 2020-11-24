#include "Date.h"
#include <stdexcept>

Date::Date()
{
	this->day = 00;
	this->month = 0;
	this->year = 2000;
}

Date::Date(int day, int month, int year)
{
	if (0 <= day <= 31 && 0 <= month <= 12 && 1900 <= year <= 2100)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else {
		throw std::out_of_range("date out of range");
	}
}

Date::~Date()
{
}

std::ostream& operator<<(std::ostream& os, const Date& obj)
{
	os << obj.day << "." << obj.month << "." << obj.year;
	return os;
}

std::istream& operator>>(std::istream& is, Date& obj)
{
	is >> obj.day >> obj.month >> obj.year;
	return is;
}
