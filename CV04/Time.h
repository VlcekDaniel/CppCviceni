#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"
struct Time : public IComparable
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	~Time();
	Time(int hours, int minutes, int seconds);
	int compareTo(IComparable* obj) const override;
	string toString() const override;
};

#endif // TIME_H
