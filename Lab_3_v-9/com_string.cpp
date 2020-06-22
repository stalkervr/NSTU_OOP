#include "com_string.h"

// Конструктор без параметров
ComString::ComString() :Complex()
{
	//std::cout << "Конструктор без параметров наследника  " << this << std::endl;
	str_number_math = number;
	str_number_geom = toTrigSring();
}

// Конструктор для строки
ComString::ComString(const char* str):Complex()
{
	//std::cout << "Конструктор с строковым параметром ComString  " << this << std::endl;
	char* ptrEnd;
	double _re = strtod(str, &ptrEnd);
	double _im = strtod(ptrEnd, NULL);
	if (_re == 0.0 || _im == 0.0) throw ParamExeption(_re, _im, str);
	re = _re;
	im = _im;
	number = toSring(re, im);
	str_number_math = number;
	str_number_geom = toTrigSring();
}

// Конструктор для чисел
ComString::ComString(double _re, double _im) :Complex(_re, _im)
{
	//std::cout << "  Конструктор с числовыми параметрами ComString " << this << std::endl;
	str_number_math = number;
	str_number_geom = toTrigSring();
}

// Конструктор копирования
ComString::ComString(const ComString& object) :Complex()
{
	//std::cout << "  Конструктор копирования ComString  " << this << std::endl;
	re = object.re;
	im = object.im;
	str_number_math = object.number;
	str_number_geom = _strdup(object.str_number_geom);
}

// Деструктор
ComString::~ComString() { }

// Методы доступа к полям класса
char* ComString::getNumber() { return str_number_math; }
char* ComString::getTrigNumber() { return str_number_geom; }

// Методы класса
char* ComString::toTrigSring()
{
	char* _trig_number = new char[50];

	char buf[20];
	const char* _cos = " * ( cos( ";
	const char* _sin = "' ) + i*sin( ";
	const char* _brecet = "' ) )";
	double Pi = 3.14;
	double _abs = sqrt(pow(this->re, 2) + pow(this->im, 2));
	double _arg = (atan(this->im / this->re) * (180 / Pi));

	_gcvt_s(buf, _abs, 3);
	strcpy(_trig_number, buf);
	_trig_number = strcat(_trig_number, _cos);
	_gcvt_s(buf, _arg, 3);
	_trig_number = strcat(_trig_number, buf);
	_trig_number = strcat(_trig_number, _sin);
	_trig_number = strcat(_trig_number, buf);
	_trig_number = strcat(_trig_number, _brecet);
	return _trig_number;
}

char* ComString::convertToString()
{
	char* _string = new char[50];
	char buf[20];
	_gcvt_s(buf, re, 5);
	strcpy(_string, buf);
	if (im > 0) {
		_string = strcat(_string, "+");
	}
	_gcvt_s(buf, im, 5);
	_string = strcat(_string, buf);
	_string = strcat(_string, "*i");
	return _string;
}

Complex ComString::convertToComplex()
{
	double _re = re;
	double _im = im;
	Complex rez(_re, _im);
	return rez;
}

//Переопределение операторов потока
ostream& operator<<(ostream& os, const ComString& object)
{
	os << object.str_number_math;
	return os;
}

istream& operator>>(istream& is, ComString& object)
{
	char temp[30];
	cout << "  Введите комплексное число в виде -> ""8,1+5,2*i""  ->  " << endl;
	is >> temp;
	
	char* ptrEnd;
	double _re = strtod(temp, &ptrEnd);
	double _im = strtod(ptrEnd, NULL);
	if (_re == 0.0 || _im == 0.0) 
		throw ComString::ParamExeption(_re, _im, temp);
	
	object.re = _re;
	object.im = _im;
	object.number = object.toSring(_re, _im);
	object.str_number_math = object.number;

	return is;
}