#pragma once
#include "complex.h"

class Date: public Complex {

	int day, mon, year, hour, min, sec;

public:

 //��������� �����
	class ParamExeption {
	public:
		int day, mon, year, hour, min, sec;

		ParamExeption(int day) {
			this->day = day;
		}
	};

	// ������������
	Date();
	Date(const Date& object);

	// ����������
	~Date();

	// ������ ������
	void getdate();
	void setdate(int hour, int min, int sec);

	// �������������� ������� ����� ������
	friend ostream& operator<<(ostream& os, const Date& dt);
	friend istream& operator>>(istream& is, Date& dt);
};

