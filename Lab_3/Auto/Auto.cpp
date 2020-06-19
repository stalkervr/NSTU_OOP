
#include "Auto.h"
#include <iostream>
#include <string>

Auto::Auto()
{
	std::cout << "Конструктор без параметров " << std::endl;
	marka = new char[strlen("Nomarka") + 1];
	strcpy(marka, "Nomarka");
	power = 0;
	cost = 0;
	count++;
}

Auto::Auto(const char* m, int p, int c)
{
	std::cout << "Конструктор с параметрами " << std::endl;
	marka = _strdup(m);
	power = p;
	cost = c;
	count++;
}

Auto::Auto(const Auto& o)
{
	std::cout << "Конструктор копирования " << std::endl;
	marka = _strdup(o.marka);
	power = o.power;
	cost = o.cost;
	count++;
}

Auto::~Auto()
{
	std::cout << "Деструктор Auto " << std::endl;
	if (marka)
		delete[]marka;
	marka = nullptr;
	count--;
}

void Auto::Show()
{
	std::cout << marka << " " << power << " "<< cost << std::endl;
}

float Auto::calc(float pr)
{
	return cost -= cost / 100 * pr;
}

int Auto::count = 0;

void Auto::Numobject()
{
	std::cout << count << std::endl;
}

Auto Auto::operator=(const Auto& ob)
{
	if (this == &ob) return *this;
	else {
		if (marka)delete[]marka;
		marka = _strdup(ob.marka);
		power = ob.power;
		date = ob.date;
		cost = ob.cost;
	}
	return *this;
}
void Auto::operator++() { power += 50; }

void Auto::operator()(int day, int mon, int year)
{
	date.setdate(day, mon, year);
}

Auto operator+(const Auto& ob1, int c) {
	Auto ob2 = ob1;
	ob2.cost += c;
	return ob2;
}

ostream& operator<<(ostream& os, const Auto& obj) {
	os << obj.marka << " " << obj.power << " " << obj.cost << endl;
	os << "Дата выпуска: ";
	os << obj.date << endl;
	return os;
}

istream& operator>>(istream& is, Auto& obj) {
	char tmp[20];
	cout << "Введите марку мощьность цену автомобиля и дату выпуска(мес день год)" << endl;
	is.getline(tmp, 20);
	if (obj.marka) delete[]obj.marka;
	obj.marka = strdup(tmp);
	is >> obj.power >> obj.cost;
	cout << "Дата выпуска";
	is >> obj.date;
	return is;

}
