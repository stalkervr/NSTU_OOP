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
	char* number;
	static int count;
	friend class Data;

protected:
	double re;
	double im;

public:
	// ������������
	Complex(double _re, double _im);
	Complex();
	Complex(const Complex& object);

	// ����������
	virtual ~Complex();

	// ������ ������� � �����
	double getRe();
	double getIm();
	void setRe(double _re);
	void setIm(double _im);
	// ������
	void addition(const Complex&);
	void subtraction(const Complex&);
	void multiplication(const Complex&);
	void division(const Complex&);
	void print();
	char* toSring(double, double);
	static void Numobject();

	class Data {
		int day, mon, year, hour, min, sec;

	public:
		Data() {
			time_t t;
			struct tm* t_m;
			t = time(NULL);
			t_m = localtime(&t);
			day = t_m->tm_mday;
			mon = t_m->tm_mon + 1;
			year = t_m->tm_year + 1900;
			hour = t_m->tm_hour;
			min = t_m->tm_min;
			sec = t_m->tm_sec;
		}
		void getdate() {
			cout << day << "/" << mon << "/" << year<< " "<<hour<<"."<<min<<"."<<sec << endl;
		}
		void setdate(int hour, int min, int sec) {
			this->hour = hour;
			this->min = min;
			this->sec = sec;
		}

		friend ostream& operator<<(ostream& os, const Data& dt) {
			os << dt.hour << "." << dt.min << "." << dt.sec;
			return os;
		}

		friend istream& operator>>(istream& is, Data& dt) {
			is >> dt.day >> dt.mon >> dt.year;
			return is;
		}
	};
	Data data;

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








