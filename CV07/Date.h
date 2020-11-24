#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
struct Date
{
public:
	Date();
	Date(int day, int month, int year);
	~Date();
	friend std::ostream& operator<<(std::ostream& os, const Date& obj);
	friend std::istream& operator>>(std::istream& is, Date& obj);
private:
	int day;
	int month;
	int year;
};
#endif // DATE_H
