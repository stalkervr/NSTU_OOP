#pragma once
#include "complex.h"
//  �������.
//  �����, �������� ����� ��� �� � ���� ������ � 
//  ������� ������ �������� ������ � ���-�� � �����;
//  ��������� ����� � ����� �������� �������.
class ComString : public Complex
{
	char* str_number_math;
	char* str_number_geom;

public:
	class ParamExeption {
	public:
		int day, mon, year, hour, min, sec;

		ParamExeption(int day) {
			this->day = day;
		}
	};

	// ������������
	ComString();
	ComString(double, double);
	ComString(const ComString&);

	// ����������
	~ComString();

	// ������ ������� � �����
	char* getNumber();

	// ������
   // Complex toComplex(const T_Complex&);// �������� �� ����� this ? 
	//char* toString(const T_Complex&);
	//char* toSring(double, double);

	// ��������������� ����������
	ComString& operator= (const ComString&);
	ComString operator+ (const ComString&);

	friend ostream& operator<<(ostream&, const ComString&);
	//
	//friend ostream& operator<<(ostream& os, const T_Complex& object);
	//friend istream& operator>>(istream& is, T_Complex& object);


};

