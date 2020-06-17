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
	// ������������
	Complex(double _re, double _im);
	Complex();
	Complex(const Complex &object);

	// ����������
	~Complex();

	// ������
	void addition(const Complex&);
	void subtraction(const Complex&);
	void multiplication(const Complex&);
	void division(const Complex&);
	void print();
	char* toSring(double, double);
	static void Numobject();
};

