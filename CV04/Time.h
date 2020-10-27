#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"
struct Time : public IComparable,IObject
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	~Time();
	Time(int hours, int minutes, int seconds);
	int CompareTo(IComparable* obj) const override;
	string ToString() const override;
};

#endif // TIME_H
