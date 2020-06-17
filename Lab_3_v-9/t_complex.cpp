#pragma once
#include "t_complex.h"
//#include "complex.h"
// Для класса предыдущей лабораторной работы реализовать иерархию классов - наследников, 
// перегрузив в них отдельные методы и добавляя члены - данные и методы по заданию
// и / или усмотрению студента.В иерархию должно входить 2 производных класса.
// Добавить в классы обработку исключений при возникновении ошибок : 
// недостатка памя - ти, выход за пределы диапазона допустимых значений, деление на ноль и т.д.
// Изменить демонстрационную программу так, чтобы она демонстрировала создание, ко - пирование объектов родственных типов, вызов методов классов.Добавить в основную про - грамму демонстрацию возникновения и обработки исключений.

//  Задание.
//  класс, хранящий число так же в виде строки и 
//  имеющий методы перевода строки в чис-ло и назад;
//  дополнить класс с датой создания объекта.




// Конструктор без параметров
T_Complex::T_Complex():Complex()
{
	char* _t_number = toSring(re, im);
	t_number = new char[strlen(_t_number) + 1];
	strcpy(t_number, _t_number);
	delete[] _t_number;
}

T_Complex::T_Complex(double _re = 0, double _im = 0):Complex(_re,_im)
{
	char* _t_number = toSring(_re, _im);
	t_number = new char[strlen(_t_number) + 1];
	strcpy(t_number, _t_number);
	delete[] _t_number;
}

// Конструктор копирования
T_Complex::T_Complex(const T_Complex& object):Complex(object)
{
	t_number = _strdup(object.t_number);
}

// Деструктор
T_Complex::~T_Complex()
{
	if (t_number)
		delete[] t_number;
	t_number = nullptr;
}

// Методы доступа к полям класса
char* T_Complex::getNumber() { return t_number; }

// Методы класса
//Complex T_Complex::toComplex(const T_Complex&)
//{
//	return Complex();
//}


char* T_Complex::toSring(double _re, double _im)
{
	char* _number = new char[50];
	char buf[20];
	_gcvt_s(buf, _re, 5);
	strcpy(_number, buf);
	if (_im > 0) {
		_number = strcat(_number, "+");
	}
	_gcvt_s(buf, _im, 5);
	_number = strcat(_number, buf);
	_number = strcat(_number, "*i");
	return _number;
}

// Переопределение операторов
T_Complex& T_Complex::operator=(const T_Complex& object)
{
	if (t_number) delete[]t_number;
	t_number = _strdup(object.t_number);
	return *this;
}
