#pragma once
#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <cmath>

using namespace std;

class Auto
{
private:
	char* marka;
	int power, cost;
	//Data date;
	static int count;
	friend class Data ;

public:
	Auto();
	Auto(const char* m, int p, int c);
	Auto(const Auto& o);

	virtual ~Auto();

	void Show();
	float calc(float pr);
	static void Numobject();

	class Data {
		int day, mon, year;

	public:
		Data() {
			time_t t;
			struct tm* t_m;
			t = time(NULL);
			t_m = localtime(&t);
			day = t_m->tm_mday;
			mon = t_m->tm_mon + 1;
			year = t_m->tm_year + 1900;
		}
		void getdate() {
			cout << day << "/" << mon << "/" << year << endl;
		}
		void setdate(int day, int mon, int year) {
			this->day = day;
			this->mon = mon;
			this->year = year;
		}

		friend ostream& operator<<(ostream& os, const Data& dt) {
			os << dt.day << "." << dt.mon << "." << dt.year;
			return os;
		}

		friend istream& operator>>(istream& is, Data& dt) {
			is >> dt.day >> dt.mon >> dt.year;
			return is;
		}
	};
	Data date;

	Auto operator=(const Auto& ob);
	void operator++();
	void operator()(int day, int mon, int year);
	friend Auto operator+(const Auto& ob1, int c);
	friend ostream& operator<<(ostream& os, const Auto& obj);
	friend istream& operator>>(istream& is, Auto& obj);

};



