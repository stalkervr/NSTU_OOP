#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <cmath>

using namespace std;

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
	Complex(const Complex& object);

	// Деструктор
	~Complex();

	// Методы доступа к полям
	double getRe();
	double getIm();

	// Методы
	void addition(const Complex&, const Complex&);
	void subtraction(const Complex&, const Complex&);
	void multiplication(const Complex&, const Complex&);
	void division(const Complex&, const Complex&);
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


