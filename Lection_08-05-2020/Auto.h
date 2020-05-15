#pragma once
class Auto
{
	char* marka;
	int power, year, cost;
	static int count;

public:
	Auto();
	Auto(const char* m, int p, int y, int c);
	Auto(Auto& o);

	~Auto();

	void Show();
	float calc(float pr);
	static void Numobject();
};

