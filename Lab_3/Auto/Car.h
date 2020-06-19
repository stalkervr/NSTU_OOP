#pragma once
#include "Auto.h"
class Car : public Auto
{

	int passager;
	bool condittioner;

public:
	class ParamExeption {
	public:
		int pas;
		ParamExeption(int pas)
		{
			this->pas = pas;
		}

	};
	Car();
	Car(const char*, int, int, int, bool) throw (ParamExeption);
	Car(const Car& obj);
	~Car();
	void setpass(int);
	friend ostream& operator<<(ostream& os, const Car& obj);
	friend istream& operator>>(istream& is, Car& obj);
};