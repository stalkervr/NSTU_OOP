#pragma once
#include "complex.h"

class Date: public Complex {

	int day, mon, year;

public:

 //Вложенный класс
	class ParamExeption {

		int day, mon, year;

	public:

		ParamExeption(int day, int mon, int year) {
			this->day = day;
			this->mon = mon;
			this->year = year;
		}
	};

	// конструкторы
	Date();
	Date(double _re, double _im, int _day, int _mon, int _year) throw (ParamExeption);
	//Date(double,double,int,int,int) throw (ParamExeption);
	Date(const Date& object);

	// деструктор
	~Date();

	// методы класса
	void getdate();
	void setdate(int hour, int min, int sec);

	// переоределение потоков ввода вывода
	friend ostream& operator<<(ostream& os, const Date& dt);
	friend istream& operator>>(istream& is, Date& dt);
};

