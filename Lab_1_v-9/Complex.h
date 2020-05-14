#pragma once
#include <string>

class Complex
{
	double re;
	double im;
	//std::string number;
	char* number_1;

public:
	Complex(double _re, double _im);
	Complex(double _re);
	Complex();

	~Complex();

	Complex addition(Complex, Complex);
	Complex subtraction(Complex, Complex);
	Complex multiplication(Complex, Complex);
	Complex division(Complex, Complex);
	void print();
	char* toSring(double, double);
};

