#pragma once
#include <string>

class Complex
{
	double re;
	double im;
	char* number;

public:
	// Конструкторы
	Complex(double _re, double _im);
	Complex();
	Complex(const Complex &object);

	// Деструктор
	~Complex();

	// Методы
	Complex addition(const Complex&, const Complex&);
	Complex subtraction(const Complex&, const Complex&);
	Complex multiplication(const Complex&, const Complex&);
	Complex division(const Complex&, const Complex&);
	void print();
	char* toSring(double, double);
};

