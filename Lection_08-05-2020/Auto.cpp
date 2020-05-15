#pragma warning(disable : 4996)
#include "Auto.h"
#include <iostream>
#include <string>

Auto::Auto()
{
	std::cout << "Конструктор без параметров " << std::endl;
	marka = new char[strlen("Nomarka") + 1];
	strcpy(marka, "Nomarka");
	power = 0;
	year = 0;
	cost = 0;
	count++;
}

Auto::Auto(const char* m, int p, int y, int c)
{
	std::cout << "Конструктор с параметрами " << std::endl;
	marka = _strdup(m);
	power = p;
	year = y;
	cost = c;
	count++;
}

Auto::Auto(Auto& o)
{
	std::cout << "Конструктор копирования " << std::endl;
	marka = _strdup(o.marka);
	power = o.power;
	year = o.year;
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
	std::cout << marka << " " << power << " " << year << " " << cost << std::endl;
}

float Auto::calc(float pr)
{
	return cost -= cost/100 *pr;
}

int Auto::count = 0;

void Auto::Numobject()
{
	std::cout << count << std::endl;
}




