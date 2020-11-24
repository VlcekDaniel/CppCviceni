#include "Date.h"

Date::Date()
{
	this->day = 00;
	this->month = 0;
	this->year = 2000;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
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
