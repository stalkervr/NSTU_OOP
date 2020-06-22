#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

class Complex
{
	static int count;

protected:
	double re;
	double im;
	char* number;

public:
	// Конструкторы
	Complex();
	Complex(double _re, double _im);
	Complex(const Complex& object);

	// Деструктор
	virtual ~Complex();

	// Методы доступа к полям
	double getRe();
	double getIm();
	char* getNumberComplex();

	// виртуальные методы
	virtual void Show(ostream& os);
	virtual void Input(istream& is);

	// Методы
	void addition(const Complex&);
	void subtraction(const Complex&);
	void multiplication(const Complex&);
	void division(const Complex&);
	void print();
	char* toSring(double, double);
	static void Numobject();

	// Переопределение операторов методы класса
	Complex& operator= (const Complex&);
	Complex operator+ (const Complex&);
	Complex operator- (const Complex&);
	Complex operator* (const Complex&);
	Complex operator/ (const Complex&);
	void operator() (const char*);
	char* operator() ();

	// Переопределение операторов дружеств. ф-ми.
	friend bool operator== (const Complex&, const Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
};

