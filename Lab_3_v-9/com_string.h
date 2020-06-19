#pragma once
#include "complex.h"
//  Задание.
//  класс, хранящий число так же в виде строки и 
//  имеющий методы перевода строки в чис-ло и назад;
//  дополнить класс с датой создания объекта.
class ComString : public Complex
{
	char* str_number_math;
	char* str_number_geom;

public:
	class ParamExeption {
	public:
		int day, mon, year, hour, min, sec;

		ParamExeption(int day) {
			this->day = day;
		}
	};

	// конструкторы
	ComString();
	ComString(double, double);
	ComString(const ComString&);

	// деструктор
	~ComString();

	// Методы доступа к полям
	char* getNumber();

	// Методы
   // Complex toComplex(const T_Complex&);// аргумент не нужен this ? 
	//char* toString(const T_Complex&);
	//char* toSring(double, double);

	// Переопределение операторов
	ComString& operator= (const ComString&);
	ComString operator+ (const ComString&);

	friend ostream& operator<<(ostream&, const ComString&);
	//
	//friend ostream& operator<<(ostream& os, const T_Complex& object);
	//friend istream& operator>>(istream& is, T_Complex& object);


};

