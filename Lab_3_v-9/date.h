#pragma once
#include "complex.h"

class Date: public Complex {

	int day, mon, year, hour, min, sec;

public:

 //Вложенный класс
	class ParamExeption {
	public:
		int day, mon, year, hour, min, sec;

		ParamExeption(int day) {
			this->day = day;
		}
	};

	// конструкторы
	Date();
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

