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
	// ������������
	Complex(double _re, double _im);
	Complex();
	Complex(const Complex& object);

	// ����������
	~Complex();

	// ������ ������� � �����
	double getRe();
	double getIm();

	// ������
	void addition(const Complex&, const Complex&);
	void subtraction(const Complex&, const Complex&);
	void multiplication(const Complex&, const Complex&);
	void division(const Complex&, const Complex&);
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


