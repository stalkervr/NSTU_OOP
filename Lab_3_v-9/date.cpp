#include "date.h"

Date::Date() {
	time_t curent_time;
	struct tm* _time;
	curent_time = time(NULL);
	_time = localtime(&curent_time);
	day = _time->tm_mday;
	mon = _time->tm_mon + 1;
	year = _time->tm_year + 1900;
	hour = _time->tm_hour;
	min = _time->tm_min;
	sec = _time->tm_sec;
}

Date::Date(const Date& object)
{
	day = object.day;
	mon = object.mon;
	year = object.year;
	hour = object.hour;
	min = object.min;
	sec = object.sec;
}

Date::~Date() {	}

void Date::getdate() {
	cout << day << "/" << mon << "/" << year << " " << hour << "." << min << "." << sec << endl;
}

void Date::setdate(int hour, int min, int sec) {
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

ostream& operator<<(ostream& os, const Date& dt) {
	os << dt.hour << "." << dt.min << "." << dt.sec;
	return os;
}

istream& operator>>(istream& is, Date& dt) {
	is >> dt.day >> dt.mon >> dt.year;
	return is;
}