#pragma once

#include "complex.h"
#include <ctime>
//  Задание.
//  класс, хранящий число так же в виде строки и 
//  имеющий методы перевода строки в чис-ло и назад;
//  дополнить класс с датой создания объекта. 

class T_Complex : public Complex
{
	char* t_number;
	
public:
//	// Вложенный класс
//	class ParamExeption {
//	public:
//		int pas;
//		ParamExeption(int pas) {
//			this->pas = pas;
//		}
//	};

	// Конструкторы
	T_Complex();
	T_Complex(double, double);
	T_Complex(const T_Complex&);
	// Деструктор
	~T_Complex();

	// Методы доступа к полям
	char* getNumber();

	// Методы
   // Complex toComplex(const T_Complex&);// аргумент не нужен this ? 
	//char* toString(const T_Complex&);
	//char* toSring(double, double);

	// Переопределение операторов
	T_Complex& operator= (const T_Complex&);
	//
	//friend ostream& operator<<(ostream& os, const T_Complex& object);
	//friend istream& operator>>(istream& is, T_Complex& object);
};



