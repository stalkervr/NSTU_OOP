#pragma once
#include "complex.h"

class Date : public Complex {

	int day, mon, year;

public:

	//��������� �����
	class ParamExeption {

	public:

		int day, mon, year;

		ParamExeption(int day, int mon, int year) {
			this->day = day;
			this->mon = mon;
			this->year = year;
		}
	};

	// ������������
	Date();
	Date(double _re, double _im, int _day, int _mon, int _year) throw (ParamExeption);
	Date(const Date& object);

	// ����������
	~Date();

	// ����������� ������
	virtual void Show(ostream& os);
	virtual void Input(istream& is);

	// ������ ������
	void getdate();
	void setdate(int hour, int min, int sec);

	// �������������� ������� ����� ������
	friend ostream& operator<<(ostream& os, const Date& dt);
	friend istream& operator>>(istream& is, Date& dt);
};


