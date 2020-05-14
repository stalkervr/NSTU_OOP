#pragma warning(disable : 4996)
#include <iostream>
#include "Complex.h"

Complex::Complex(double _re, double _im) {
	std::cout << "Конструктор с параметрами №1\n";
	re = _re;
	im = _im;
	//number = std::to_string(re) + " , " + std::to_string(im);
	number_1 = toSring(re, im);

};
Complex::Complex(double _re) {
	std::cout << "Конструктор с параметрами №2\n";
	re = _re;
	im = 0.0f;
	//number = std::to_string(_re) + " , " + std::to_string(im);
	number_1 = toSring(re, im);
	//char* pointer;
};
Complex::Complex() {
	std::cout << "Конструктор без параметров\n";
	re = im = 0.0f;
	//number = std::to_string(re) + " , " + std::to_string(im);
	number_1 = toSring(re, im);
};
Complex::~Complex()
{
	std::cout << "Вызов деструктора\n";
	//delete re;
	//delete im;
	//delete &number;
};



Complex Complex::addition(Complex a1, Complex a2)
{
	return Complex(a1.re + a2.re, a1.im + a2.im);
}

Complex Complex::subtraction(Complex a1, Complex a2)
{
	return Complex(a1.re - a2.re, a1.im - a2.im);
}

Complex Complex::multiplication(Complex a1, Complex a2)
{
	return Complex((a1.re * a2.re - a1.im * a2.im) + (a1.re * a2.im + a2.re * a1.im));
}

Complex Complex::division(Complex a1, Complex a2)
{
	return Complex(((a1.re * a2.re + a1.im * a2.im) + (a2.re * a1.im - a1.re * a2.im)) / ((a2.re * a2.re) + (a2.im * a2.im)));
}

void Complex::print()
{
	//std::cout << "( " << re << "  " << im << " )\n";
	//std::cout << number << "\n";
	std::cout << "( " << number_1 << " )\n";
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
