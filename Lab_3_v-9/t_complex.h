#pragma once

#include "complex.h"
#include <ctime>
//  �������.
//  �����, �������� ����� ��� �� � ���� ������ � 
//  ������� ������ �������� ������ � ���-�� � �����;
//  ��������� ����� � ����� �������� �������. 

class T_Complex : public Complex
{
	char* t_number;
	
public:
//	// ��������� �����
//	class ParamExeption {
//	public:
//		int pas;
//		ParamExeption(int pas) {
//			this->pas = pas;
//		}
//	};

	// ������������
	T_Complex();
	T_Complex(double, double);
	T_Complex(const T_Complex&);
	// ����������
	~T_Complex();

	// ������ ������� � �����
	char* getNumber();

	// ������
   // Complex toComplex(const T_Complex&);// �������� �� ����� this ? 
	//char* toString(const T_Complex&);
	char* toSring(double, double);

	// ��������������� ����������
	T_Complex& operator= (const T_Complex&);
	//
	//friend ostream& operator<<(ostream& os, const T_Complex& object);
	//friend istream& operator>>(istream& is, T_Complex& object);
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
//		cout << day << "/" << mon << "/" << "/" << year << endl;
//	}
//	void setdate(int day, int mon, int year) {
//		this->day = day;
//		this->mon = mon;
//		this->year = year;
//	}
//
//	friend ostream& operator<<(ostream& os, const Data& dt) {
//		os << dt.day << " " << dt.mon << " " << " " << dt.year;
//		return os;
//	}
//
//	friend istream& operator>>(istream& is, Data& dt) {
//		is >> dt.day >> dt.mon >> dt.year;
//		return is;
//	}
//};

