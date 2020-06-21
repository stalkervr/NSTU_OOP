#pragma once
#include "complex.h"

class ComString : public Complex
{
	char* str_number_math;
	char* str_number_geom;

public:
	class ParamExeption {
	public:
		const char* str;
		double re;
		double im;

		ParamExeption(double _re, double _im, const char* _str) {
			this->re = _re;
			this->im = _im;
			this->str = _str;
		}
	};

	// конструкторы
	ComString();
	ComString(const char* str);
	ComString(double, double);
	ComString(const ComString&);

	// деструктор
	~ComString();

	// Методы доступа к полям
	char* getNumber();
	char* getTrigNumber();

	// Методы
	char* toTrigSring();
	char* convertToString();
	Complex convertToComplex();

	// Переопределение операторов потока
	friend ostream& operator<<(ostream&, const ComString&);
	friend istream& operator>>(istream& is, ComString& object);
};

