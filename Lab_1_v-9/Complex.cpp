#include "Complex.h"

// Конструктор с параметрами 
Complex::Complex(double _re = 0, double _im = 0) {
	std::cout << "Конструктор с параметрами  " << this << std::endl;
	re = _re;
	im = _im;
	char* _number = toSring(re, im);
	number = new char[strlen(_number) + 1];
	strcpy(number, _number);
	delete[] _number;
	count++;
}

// Конструктор без параметров
Complex::Complex() {
	std::cout << "Конструктор без параметров  " << this << std::endl;
	re = im = 0.0;
	char* _number = toSring(re, im);
	number = new char[strlen(_number) + 1];
	strcpy(number, _number);
	delete[] _number;
	count++;
}

 //Конструктор копирования
Complex::Complex(const Complex& object)
{
	std::cout << "Конструктор копирования  " << this << std::endl;
	re = object.re;
	im = object.im;
	number = _strdup(object.number);
	count++;
}
;
// Деструктор
Complex::~Complex()
{
	std::cout << "Вызов деструктора  " << this << std::endl;
	if (number) 
		delete[] number;
	number = nullptr;
	count--;
}


// Методы
 void Complex::addition(const Complex& a2)
{
	 re = re + a2.re;
	 im = im + a2.im;
	 number = toSring(re, im);
}

void Complex::subtraction(const Complex& a2)
{
	re = re - a2.re;
	im = im - a2.im;
	number = toSring(re, im);
}

void Complex::multiplication(const Complex& a2)
{
	re = (re * a2.re - im * a2.im);
	im =	(re * a2.im + a2.re * im);
	number = toSring(re, im);
}

void Complex::division(const Complex& a2)
{
	re = (re * a2.re + im * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	im = (a2.re * im - re * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	number = toSring(re, im);
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