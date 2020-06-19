#include "T_Complex.h"
//#include "Complex.h"

T_Complex::T_Complex(double re, double im) : Complex(re,im)
{
	/*char* _t_number = toSring(re, im);
	t_number = new char[strlen(_t_number) + 1];
	strcpy(t_number, _t_number);
	delete[] _t_number;*/
}

T_Complex::~T_Complex()
{
	/*if (t_number)
		delete[] t_number;
	t_number = nullptr;*/
}

//char* T_Complex::getTnumber()
//{
//	/*return t_number;*/
//}
