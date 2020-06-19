#include "com_string.h"
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
ComString::ComString() :Complex()
{
	std::cout << "����������� ��� ���������� ����������  " << this << std::endl;
	char* _str_number_math = toSring(0, 0);
	str_number_math = new char[strlen(_str_number_math) + 1];
	strcpy(str_number_math, _str_number_math);
	delete[] _str_number_math;
}

ComString::ComString(double _re, double _im) :Complex(_re, _im)
{
	std::cout << "����������� � ����������� ����������  " << this << std::endl;
	char* _str_number_math = toSring(_re, _im);
	str_number_math = new char[strlen(_str_number_math) + 1];
	strcpy(str_number_math, _str_number_math);
	delete[] _str_number_math;
}

// ����������� �����������
ComString::ComString(const ComString& object) :Complex()
{
	std::cout << "����������� ����������� ����������  " << this << std::endl;
	re = object.re;
	im = object.im;
	str_number_math = _strdup(object.str_number_math);
}

// ����������
ComString::~ComString()
{
	if (str_number_math)
		delete[] str_number_math;
	str_number_math = nullptr;
}

// ������ ������� � ����� ������
char* ComString::getNumber() { return str_number_math; }


//��������������� ����������
ComString& ComString::operator=(const ComString& object)
{
	std::cout << "= �� ComString  " << this << std::endl;
	if (str_number_math != NULL) delete[]str_number_math;
	re = object.re;
	im = object.im;
	str_number_math = _strdup(object.str_number_math);
	return *this;
}

ComString ComString::operator+(const ComString& a2)
{
	std::cout << "+ �� ComString  " << this << std::endl;
	ComString rez(0.0, 0.0);
	rez.re = re + a2.re;
	rez.im = im + a2.im;
	rez.str_number_math = toSring(rez.re, rez.im);
	return rez;
}

ostream& operator<<(ostream& os, const ComString& a1)
{
	os << a1.str_number_math;
	return os;
}