#include <iostream>
#include "complex.h"

int main()
{
    complex a1(2.1, 3.5);
    complex a2(2.2, 2.0);
    complex x = a1 + a2;

    x.print();
    system("pause");

    //std::cout << "Hello World!\n ";
}