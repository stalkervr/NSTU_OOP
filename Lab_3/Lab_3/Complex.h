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
	//Data data_create;
	//friend class Data;

public:
	// Конструкторы
	Complex(double _re, double _im);
	Complex();
	Complex(const Complex& object);

	// Деструктор
	virtual ~Complex();

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

//class Data {
//	int day, mon, year;
//
//public:
//	Data() {
//		time_t t;
//		struct tm* t_m;
//		t = time(NULL);
//		t_m = localtime(&t);
//		day = t_m->tm_mday;
//		mon = t_m->tm_mon + 1;
//		year = t_m->tm_year + 1900;
//	}
//	void getdate() {
//		cout << day << "/" << mon << "/" << year << endl;
//	}
//	void setdate(int day, int mon, int year) {
//		this->day = day;
//		this->mon = mon;
//		this->year = year;
//	}
//
//	friend ostream& operator<<(ostream& os, const Data& dt) {
//		os << dt.day << "." << dt.mon << "." << dt.year;
//		return os;
//	}
//
//	friend istream& operator>>(istream& is, Data& dt) {
//		is >> dt.day >> dt.mon >> dt.year;
//		return is;
//	}
//};



