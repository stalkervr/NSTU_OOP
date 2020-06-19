#include "com_string.h"
//#include "complex.h"
// ƒл€ класса предыдущей лабораторной работы реализовать иерархию классов - наследников, 
// перегрузив в них отдельные методы и добавл€€ члены - данные и методы по заданию
// и / или усмотрению студента.¬ иерархию должно входить 2 производных класса.
// ƒобавить в классы обработку исключений при возникновении ошибок : 
// недостатка пам€ - ти, выход за пределы диапазона допустимых значений, деление на ноль и т.д.
// »зменить демонстрационную программу так, чтобы она демонстрировала создание, ко - пирование объектов родственных типов, вызов методов классов.ƒобавить в основную про - грамму демонстрацию возникновени€ и обработки исключений.

//  «адание.
//  класс, хран€щий число так же в виде строки и 
//  имеющий методы перевода строки в чис-ло и назад;
//  дополнить класс с датой создани€ объекта.


//  онструктор без параметров
ComString::ComString() :Complex()
{
	std::cout << " онструктор без параметров наследника  " << this << std::endl;
	char* _str_number_math = toSring(0, 0);
	str_number_math = new char[strlen(_str_number_math) + 1];
	strcpy(str_number_math, _str_number_math);
	delete[] _str_number_math;
}

ComString::ComString(double _re, double _im) :Complex(_re, _im)
{
	std::cout << " онструктор с параметрами наследника  " << this << std::endl;
	char* _str_number_math = toSring(_re, _im);
	str_number_math = new char[strlen(_str_number_math) + 1];
	strcpy(str_number_math, _str_number_math);
	delete[] _str_number_math;
}

//  онструктор копировани€
ComString::ComString(const ComString& object) :Complex()
{
	std::cout << " онструктор копировани€ наследника  " << this << std::endl;
	re = object.re;
	im = object.im;
	str_number_math = _strdup(object.str_number_math);
}

// ƒеструктор
ComString::~ComString()
{
	if (str_number_math)
		delete[] str_number_math;
	str_number_math = nullptr;
}

// ћетоды доступа к пол€м класса
char* ComString::getNumber() { return str_number_math; }


//ѕереопределение операторов
ComString& ComString::operator=(const ComString& object)
{
	std::cout << "= из ComString  " << this << std::endl;
	if (str_number_math != NULL) delete[]str_number_math;
	re = object.re;
	im = object.im;
	str_number_math = _strdup(object.str_number_math);
	return *this;
}

ComString ComString::operator+(const ComString& a2)
{
	std::cout << "+ из ComString  " << this << std::endl;
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