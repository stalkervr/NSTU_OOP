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
	// ������������
	Complex();
	Complex(double _re, double _im);
	Complex(const Complex& object);

	// ����������
	virtual ~Complex();

	// ������ ������� � �����
	double getRe();
	double getIm();
	char* getNumberComplex();

	// ����������� ������
	virtual void Show(ostream& os);
	virtual void Input(istream& is);

	// ������
	void addition(const Complex&);
	void subtraction(const Complex&);
	void multiplication(const Complex&);
	void division(const Complex&);
	void print();
	char* toSring(double, double);
	static void Numobject();

	// ��������������� ���������� ������ ������
	Complex& operator= (const Complex&);
	Complex operator+ (const Complex&);
	Complex operator- (const Complex&);
	Complex operator* (const Complex&);
	Complex operator/ (const Complex&);
	void operator() (const char*);
	char* operator() ();

	// ��������������� ���������� ��������. �-��.
	friend bool operator== (const Complex&, const Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
};

