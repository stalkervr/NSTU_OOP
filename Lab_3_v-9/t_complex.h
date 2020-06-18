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
	//char* toSring(double, double);

	// ��������������� ����������
	T_Complex& operator= (const T_Complex&);
	//
	//friend ostream& operator<<(ostream& os, const T_Complex& object);
	//friend istream& operator>>(istream& is, T_Complex& object);
};



