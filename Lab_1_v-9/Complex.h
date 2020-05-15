#pragma once
#include <string>

class Complex
{
	double re;
	double im;
	char* number;
	static int count;

public:
	// Конструкторы
	Complex(double _re, double _im);
	Complex();
	Complex(const Complex &object);

	// Деструктор
	~Complex();

	// Методы
	void addition(const Complex&, const Complex&);
	void subtraction(const Complex&, const Complex&);
	void multiplication(const Complex&, const Complex&);
	void division(const Complex&, const Complex&);
	void print();
	char* toSring(double, double);
	static void Numobject();
};

