#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <locale>

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
	void addition(const Complex&);
	void subtraction(const Complex&);
	void multiplication(const Complex&);
	void division(const Complex&);
	void print();
	char* toSring(double, double);
	static void Numobject();
};

