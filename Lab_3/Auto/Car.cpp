#pragma once
#include "Car.h"
Car::Car() {
	passager = 1;
	condittioner = false;
}

Car::Car(const char* m, int p, int c, int pas, bool cond) : Auto(m, p, c) {
	if (pas < 0 || pas>5) throw ParamExeption(pas);
		passager = pas;
		condittioner = cond;
}

Car::Car(const Car& obj) :Auto(obj)
{
	passager = obj.passager;
	condittioner = obj.condittioner;
}

Car::~Car()
{

}

void Car:: setpass(int k) 
{
	passager = k;
}

ostream& operator<<(ostream& os, const Car& obj)
{
	os << (Auto)obj;
	os << "passager = " << obj.passager << "conditioner = "
		<< (bool)obj.condittioner << endl;
	return os;
}

istream& operator>>(istream& is, Car& obj)
{
	is >> (Auto&)obj;
	cout << "количество пассажиров, кондитционер" << endl;
	is >> obj.passager >> obj.condittioner;
	if (obj.passager < 0 || obj.passager>5)
		throw " оличество пассажиров не более 5";
	return is;
}