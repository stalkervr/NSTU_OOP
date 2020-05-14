#include <iostream>
#include "Complex.h"
#include <locale>


int main()
{
    setlocale(LC_ALL, "Russian");

    Complex a1(10.2, 6.2);
    Complex a2(5.1, 3.1);
    Complex x;
    x = x.addition(a1, a2);

    a1.print();
    a2.print();
    x.print();
    //a1.toSring;


    std::cout << "Hello World!\n";

    //system("pause");
    _getwch();
}
