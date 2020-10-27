#include "Time.h"

Time::~Time()
{
}

Time::Time(int hours, int minutes, int seconds)
{
	if (hours >= 0 && hours <= 23 && minutes>=0 && minutes <= 59 && seconds>=0 && seconds <= 59) {
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}
}

int Time::compareTo(IComparable* obj) const
{
	int timeA = hours * 3600 + minutes * 60 + seconds;
	int timeB = ((Time*)obj)->hours * 3600 + ((Time*)obj)->minutes * 60 + ((Time*)obj)->seconds;
		
	if (timeA > timeB) {
		return 1;
	}
	else if (timeA == timeB) {
		return 0;
	}
	else if (timeA < timeB) {
		return -1;
	}
	else
	{
		return 0;
	}
}

string Time::toString() const
{
	return (to_string(this->hours) + ":" + to_string(this->minutes) + ":" + to_string(this->seconds));
}
