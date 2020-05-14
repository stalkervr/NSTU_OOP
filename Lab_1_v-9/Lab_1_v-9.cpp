#include <iostream>
#include "Complex.h"
#include <locale>


int main()
{
    setlocale(LC_ALL, "Russian");

    Complex a1(10.2, 6.2);
    Complex a2(5.1, 3.1);
    Complex a3 = a1;

    a1.print();
    a2.print();
    a3.print();

    Complex x;
    x = x.addition(a1, a2);
    std::cout << "Сложение  ";
    x.print();

    x = x.subtraction(a1, a2);
    std::cout << "Вычитание  ";
    x.print();

    x = x.multiplication(a1, a2);
    std::cout << "Умножение  ";
    x.print();

    x = x.division(a1, a2);
    std::cout << "Деление  ";
    x.print();

    _getwch();

}
