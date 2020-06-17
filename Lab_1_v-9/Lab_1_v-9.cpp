#include "Complex.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Количество объектов =  ";
    Complex::Numobject();
    Complex a1(10.222, 6.2);
    Complex a2(5.1, 3.111);
    Complex a3 = a1;
    std::cout << "Количество объектов =  ";
    Complex::Numobject();
    a1.print();
    a2.print();
    a3.print();

    Complex x;
    std::cout << "Количество объектов =  ";
    Complex::Numobject();

    a1.addition(a2);
    std::cout << "Сложение  ";
    a1.print();
    std::cout << "Количество объектов =  ";
    Complex::Numobject();

    a1.subtraction(a2);
    std::cout << "Вычитание  ";
    a1.print();
    std::cout << "Количество объектов =  ";
    Complex::Numobject();

    a1.multiplication(a2);
    std::cout << "Умножение  ";
    a1.print();
    std::cout << "Количество объектов =  ";
    Complex::Numobject();

    a1.division(a2);
    std::cout << "Деление  ";
    a1.print();
    std::cout << "Количество объектов =  ";
    Complex::Numobject();
    
    Complex* pm = new Complex(15.00, 10.00);
    pm->print();
    Complex::Numobject();
    delete pm;

    Complex* parr = new Complex[5];
    Complex::Numobject();
    for (int i = 0; i < 5; i++)
    {
        parr[i].print();
    }
    delete[]parr;
    Complex::Numobject();

    _getwch();
    return 0;
}