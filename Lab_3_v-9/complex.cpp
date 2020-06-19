#include "complex.h"

// Конструктор с параметрами 
Complex::Complex(double _re = 0, double _im = 0) {
	std::cout << "Конструктор с параметрами  " << this << std::endl;
	re = _re;
	im = _im;
	char* _number = toSring(re, im);
	number = new char[strlen(_number) + 1];
	strcpy(number, _number);
	delete[] _number;
	count++;
}

// Конструктор без параметров
Complex::Complex() {
	std::cout << "Конструктор без параметров  " << this << std::endl;
	re = im = 0.0;
	char* _number = toSring(re, im);
	number = new char[strlen(_number) + 1];
	strcpy(number, _number);
	delete[] _number;
	count++;
}

//Конструктор копирования
Complex::Complex(const Complex& object)
{
	std::cout << "Конструктор копирования  " << this << std::endl;
	re = object.re;
	im = object.im;
	number = _strdup(object.number);
	count++;
}

// Деструктор
Complex::~Complex()
{
	//std::cout << "Вызов деструктора  " << this << std::endl;
	if (number)
		delete[] number;
	number = nullptr;
	count--;
}

// Методы доступа к полям
double Complex::getRe() { return re; }
double Complex::getIm() { return im; }
char* Complex::getNumberComplex() { return number; }
//void Complex::setRe(double _re) { re = _re; }
//void Complex::setIm(double _im) { im = _im; }


#pragma region // Методы
// Методы
void Complex::addition(const Complex& a2)
{
	re = re + a2.re;
	im = im + a2.im;
	number = toSring(re, im);
}

void Complex::subtraction(const Complex& a2)
{
	re = re - a2.re;
	im = im - a2.im;
	number = toSring(re, im);
}

void Complex::multiplication(const Complex& a2)
{
	re = (re * a2.re - im * a2.im);
	im = (re * a2.im + a2.re * im);
	this->number = toSring(re, im);
}

void Complex::division(const Complex& a2)
{
	re = (re * a2.re + im * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	im = (a2.re * im - re * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	this->number = toSring(re, im);
}

void Complex::print()
{
	std::cout << "( " << number << " )\n\n";
}

char* Complex::toSring(double _re, double _im)
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

int Complex::count = 0;

void Complex::Numobject()
{
	std::cout << count << std::endl;
}

#pragma endregion

#pragma region Переопределение операторов методы класса
// Переопределение операторов методы класса
Complex& Complex::operator=(const Complex& object)
{
	if (number != NULL) delete[]number;
	re = object.re;
	im = object.im;
	number = _strdup(object.number);
	return *this;
}

Complex Complex::operator+(const Complex& a2)
{
	Complex rez(0.0, 0.0);
	rez.re = re + a2.re;
	rez.im = im + a2.im;
	rez.number = toSring(rez.re, rez.im);
	return rez;
}
Complex Complex::operator-(const Complex& a2)
{
	Complex rez(0.0, 0.0);
	rez.re = re - a2.re;
	rez.im = im - a2.im;
	rez.number = toSring(rez.re, rez.im);
	return rez;
}
Complex Complex::operator*(const Complex& a2)
{
	Complex rez(0.0, 0.0);
	rez.re = (re * a2.re - im * a2.im);
	rez.im = (re * a2.im + a2.re * im);
	rez.number = toSring(rez.re, rez.im);
	return rez;

}
Complex Complex::operator/(const Complex& a2)
{
	Complex rez(0.0, 0.0);
	rez.re = (re * a2.re + im * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	rez.im = (a2.re * im - re * a2.im) / ((a2.re * a2.re) + (a2.im * a2.im));
	rez.number = toSring(rez.re, rez.im);
	return rez;
}
void Complex::operator() (const char* _string)
{
	char* ptrEnd;
	re = strtod(_string, &ptrEnd);
	im = strtod(ptrEnd, NULL);
	number = toSring(re, im);
}
char* Complex::operator()()
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
#pragma endregion

#pragma region Переопределение операторов дружеств. ф-ми.
// Переопределение операторов дружеств. ф-ми.
bool operator== (const Complex& a1, const Complex& a2)
{
	if (a1.re == a2.re && a1.im == a2.im) {
		return true;
	}
	else return false;
}
ostream& operator<<(ostream& os, const Complex& a1)
{
	os << a1.number;
	return os;
}
istream& operator>>(istream& is, Complex& a1)
{
	char temp[1024];
	is >> temp;
	if (a1.number != 0) {
		delete[]a1.number;
	}
	char* ptrEnd;
	a1.re = strtod(temp, &ptrEnd);
	a1.im = strtod(ptrEnd, NULL);
	a1.number = a1.toSring(a1.re, a1.im);
	return is;
}
#pragma endregion

