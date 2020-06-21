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
	if (_day < 1 || _day > 31) throw ParamExeption(_day,_mon,_year);
	day = _day;
	if (_mon < 1 || _mon > 12) throw ParamExeption(_day,_mon,_year);
	mon = _mon;
	if (_year < 1900 || _year > 2020) throw ParamExeption(_day,_mon,_year);
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

ostream& operator<<(ostream& os, const Date& object) {
	os << (Complex)object;
	os << "  Дата создания объекта "<< object.day << "." << object.mon << "." << object.year;
	return os;
}

istream& operator>>(istream& is, Date& object) 
{
	is >> (Complex&)object;
	cout << "  Введите дату -> день месяц год " << endl;
	is >> object.day >> object.mon >> object.year;
	if (object.day < 1 || object.day > 31) {

		throw "  День должен быть больше 1 и меньше 31. Объект не создан.";
	}
	else if (object.mon < 1 || object.mon > 12) 
	{
		throw "  Месяц должен быть больше 1 и меньше 12. Объект не создан.";
	}
	else if (object.year < 1900 || object.year > 2020) 
	{
		throw "  Год должен быть больше 1900 и меньше 2020. Объект не создан.";
	}
	else return is;
}