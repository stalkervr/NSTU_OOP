#pragma once
#include "t_complex.h"
//#include "complex.h"
// ��� ������ ���������� ������������ ������ ����������� �������� ������� - �����������, 
// ���������� � ��� ��������� ������ � �������� ����� - ������ � ������ �� �������
// � / ��� ���������� ��������.� �������� ������ ������� 2 ����������� ������.
// �������� � ������ ��������� ���������� ��� ������������� ������ : 
// ���������� ���� - ��, ����� �� ������� ��������� ���������� ��������, ������� �� ���� � �.�.
// �������� ���������������� ��������� ���, ����� ��� ��������������� ��������, �� - ��������� �������� ����������� �����, ����� ������� �������.�������� � �������� ��� - ������ ������������ ������������� � ��������� ����������.

//  �������.
//  �����, �������� ����� ��� �� � ���� ������ � 
//  ������� ������ �������� ������ � ���-�� � �����;
//  ��������� ����� � ����� �������� �������.


// ����������� ��� ����������
T_Complex::T_Complex():Complex()
{
	std::cout << "����������� ��� ���������� ����������  " << this << std::endl;
	char* _t_number = toSring(0, 0);
	t_number = new char[strlen(_t_number) + 1];
	strcpy(t_number, _t_number);
	delete[] _t_number;
}

T_Complex::T_Complex(double _re = 0, double _im = 0):Complex(_re,_im)
{
	std::cout << "����������� � ����������� ����������  " << this << std::endl;
	char* _t_number = toSring(_re, _im);
	t_number = new char[strlen(_t_number) + 1];
	strcpy(t_number, _t_number);
	delete[] _t_number;
}

// ����������� �����������
T_Complex::T_Complex(const T_Complex& object):Complex()
{
	std::cout << "����������� ����������� ����������  " << this << std::endl;
	re = object.re;
	im = object.im;
	t_number = _strdup(object.t_number);
}

// ����������
T_Complex::~T_Complex()
{
	if (t_number)
		delete[] t_number;
	t_number = nullptr;
}

// ������ ������� � ����� ������
char* T_Complex::getNumber() { return t_number; }


 //��������������� ����������
T_Complex& T_Complex::operator=(const T_Complex& object)
{
	std::cout << "= �� T_Complex  " << this << std::endl;
	if (t_number != NULL) delete[]t_number;
	re = object.re;
	im = object.im;
	t_number = _strdup(object.t_number);
	return *this;
}

T_Complex T_Complex::operator+(const T_Complex& a2)
{
	std::cout << "+ �� T_Complex  " << this << std::endl;
	T_Complex rez(0.0, 0.0);
	rez.re = re + a2.re;
	rez.im = im + a2.im;
	rez.t_number = toSring(rez.re, rez.im);
	return rez;
}

ostream& operator<<(ostream& os, const T_Complex& a1)
{
	os << a1.t_number;
	return os;
}
