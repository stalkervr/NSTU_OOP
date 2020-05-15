#pragma once
#include <string>

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
	void addition(const Complex&, const Complex&);
	void subtraction(const Complex&, const Complex&);
	void multiplication(const Complex&, const Complex&);
	void division(const Complex&, const Complex&);
	void print();
	char* toSring(double, double);
	static void Numobject();
};

