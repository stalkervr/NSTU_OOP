﻿// Auto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//*#pragma warning(disable : 4996)
#include <iostream>
#include "Auto.h"
#include "Car.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Car obj3, *obj4 = nullptr;
    cout << obj3;
    try {
        obj4 = new Car("Toyota", 350, 100000, 6, true);
        cout << *obj4;
    }
    catch (Car::ParamExeption e) {
        cout << "Задано количество пас = " << e.pas << endl;
        cout << "Количество пассажиров не более 5.Обьект не создан" << endl;
    }

    if (obj4)
        cout << *obj4;
    do {
        try {
            cin >> obj3;
            break;
        }
        catch (char* str)
        {
            cout << str << endl;
            cin.ignore(32767, '\n');
        }
    } while (true);
        cout << obj3;
        system("pause");
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.