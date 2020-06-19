#include "complex.h"
#include "com_date.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "  Лабораторная работа № 3  \n" << endl;

    Date test;
    cout << "  Проверка работы класса Date  " << endl;
    cout << "  создание объекта без параметров.\n" << endl;
    cout << "  " << test << endl;

    cout << "  Проверка работы класса Date  " << endl;
    cout << "  изменение даты создания объекта на 1, 1, 2012.\n" << endl;
    test.setdate(1, 1, 2012);
    cout << "  " << test << endl;

    cout << "  Проверка работы метода getdate() класса Date  " << endl;
    cout << "  вывод даты в консоль.\n" << endl;
    test.getdate();

    //cout << "  установка даты \n  вызов y()\n" << endl;
    //cout << "  " << test << endl;

    _getwch();
    return 0;
}

