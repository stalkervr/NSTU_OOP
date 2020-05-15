#pragma warning(disable : 4996)
#include <iostream>
#include "Complex.h"
#include <string>

// ����������� � ����������� 
Complex::Complex(double _re = 0, double _im = 0) {
	std::cout << "����������� � �����������  " << this << std::endl;
	re = _re;
	im = _im;
	number = new char[50];
	char* _number = toSring(re, im);
	strcpy(number, _number);
	delete[]_number;
	count++;
}

// ����������� ��� ����������
Complex::Complex() {
	std::cout << "����������� ��� ����������  " << this << std::endl;
	re = im = 0.0;
	number = new char[50];
	char* _number = toSring(re, im);
	strcpy(number, _number);
	delete[]_number;
	count++;
}

 //����������� �����������
Complex::Complex(const Complex& object)
{
	std::cout << "����������� �����������  " << this << std::endl;
	re = object.re;
	im = object.im;
	number = _strdup(object.number);
	count++;
}
;
// ����������
Complex::~Complex()
{
	std::cout << "����� �����������  " << this << std::endl;
	if (number) 
		delete[] number;
	number = nullptr;
	count--;
}


// ������
 void Complex::addition(const Complex& a1, const Complex& a2)
{
	 this->re = a1.re + a2.re;
	 this->im = a1.im + a2.im;
	 this->number = toSring(re, im);
}

void Complex::subtraction(const Complex& a1, const Complex& a2)
{
	this->re = a1.re - a2.re;
	this->re = a1.im - a2.im;
	this->number = toSring(re, im);
}

void Complex::multiplication(const Complex& a1, const Complex& a2)
{
	this->re = (a1.re * a2.re - a1.im * a2.im);
	this->im =	(a1.re * a2.im + a2.re * a1.im);
	this->number = toSring(re, im);
}

void Complex::division(const Complex& a1, const Complex& a2)
{
	this->re = (a1.re * a2.re + a1.im * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	this->im = (a2.re * a1.im - a1.re * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	this->number = toSring(re, im);
}

void Complex::print()
{
	std::cout << "( " << number << " )\n\n";
}

char* Complex::toSring(double _re, double _im)
{
	char* _number = new char[50];
	char buf[20];
	_gcvt_s(buf, _re, 5);
	strcpy(_number, buf);
	_number = strcat(_number, " + ");
	_gcvt_s(buf, _im, 5);
	_number = strcat(_number, buf);
	_number = strcat(_number, "*i");
	return _number;
}

int Complex::count = 0;

void Complex::Numobject() 
{
	std::cout << count << std::endl;
}