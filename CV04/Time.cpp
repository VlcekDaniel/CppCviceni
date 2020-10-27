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
	else {
		throw new exception("out of bounds");
	}
}

int Time::CompareTo(IComparable* obj) const
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

string Time::ToString() const
{
	string hoursStr = (to_string(this->hours));
	if (this->hours < 10) {
		hoursStr = "0" + hoursStr;
	}
	string minutesStr = (to_string(this->minutes));
	if (this->minutes < 10) {
		minutesStr = "0" + minutesStr;
	}
	string secondsStr = (to_string(this->seconds));
	if (this->seconds < 10) {
		secondsStr = "0" + secondsStr;
	}
	return (hoursStr + ":" + minutesStr + ":" + secondsStr);
}
