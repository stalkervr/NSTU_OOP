#pragma warning(disable : 4996)
#include <iostream>
#include "Complex.h"

// Конструктор с параметрами 
Complex::Complex(double _re = 0, double _im = 0) {
	std::cout << "Конструктор с параметрами  " << this << std::endl;
	re = _re;
	im = _im;
	number = toSring(re, im);
}

// Конструктор без параметров
Complex::Complex() {
	std::cout << "Конструктор без параметров  " << this << std::endl;
	re = im = 0.0;
	number = toSring(re, im);
}

 //Конструктор копирования
Complex::Complex(const Complex &object)
{
	std::cout << "Конструктор копирования  " << this << std::endl;
	this->re = object.re;
	this->im = object.im;
	this->number = _strdup(object.number);
}
;
// Деструктор
Complex::~Complex()
{
	/*if (number) 
		delete[] number;
	number = nullptr;*/
	std::cout << "Вызов деструктора  " << this << std::endl;
}


// Методы
Complex Complex::addition(const Complex& a1, const Complex& a2)
{
	return Complex (a1.re + a2.re, a1.im + a2.im); 
}

Complex Complex::subtraction(const Complex& a1, const Complex& a2)
{
	return Complex (a1.re - a2.re, a1.im - a2.im);
}

Complex Complex::multiplication(const Complex& a1, const Complex& a2)
{
	return Complex ((a1.re * a2.re - a1.im * a2.im) + (a1.re * a2.im + a2.re * a1.im));
}

Complex Complex::division(const Complex& a1, const Complex& a2)
{
	return Complex (((a1.re * a2.re + a1.im * a2.im) + (a2.re * a1.im - a1.re * a2.im)) / ((a2.re * a2.re) + (a2.im * a2.im)));
}

void Complex::print()

{
	//std::cout << "( " << re << " + " << im << "*i )\n";
	std::cout << "( " << number << " )\n\n";
}

char* Complex::toSring(double _re, double _im)
{
	char* rez = new char[20];

	char buf[20];
	_gcvt_s(buf, _re, 5);
	strcpy(rez, buf);
	rez = strcat(rez, " + ");
	_gcvt_s(buf, _im, 5);

	rez = strcat(rez, buf);
	rez = strcat(rez, "*i");
	return rez;
}
