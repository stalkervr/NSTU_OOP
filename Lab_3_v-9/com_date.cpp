#include "com_date.h"

Date::Date() : Complex()
{
	time_t curent_time;
	struct tm* _time;
	curent_time = time(NULL);
	_time = localtime(&curent_time);

	day = _time->tm_mday;
	mon = _time->tm_mon + 1;
	year = _time->tm_year + 1900;
}

Date::Date(double _re, double _im, int _day, int _mon, int _year) : Complex(_re, _im)
{
	if (day < 1 || day > 31) throw ParamExeption(day,mon,year);
	day = _day;

	if (mon < 1 || mon > 12) throw ParamExeption(day,mon,year);
	mon = _mon;

	if (year < 1900 || year > 2030) throw ParamExeption(day,mon,year);
	year = _year;
}

Date::Date(const Date& object) : Complex (object)
{
	day = object.day;
	mon = object.mon;
	year = object.year;
}

Date::~Date() {	}

void Date::getdate() {
	cout<<"  " << day << "/" << mon << "/" << year << endl;
}

void Date::setdate(int day, int mon, int year) {
	this->day = day;
	this->mon = mon;
	this->year = year;
}

ostream& operator<<(ostream& os, const Date& dt) {
	os << dt.day << "." << dt.mon << "." << dt.year;
	return os;
}

istream& operator>>(istream& is, Date& dt) {
	is >> dt.day >> dt.mon >> dt.year;
	return is;
}