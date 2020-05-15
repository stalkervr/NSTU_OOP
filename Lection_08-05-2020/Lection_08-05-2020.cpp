#include "Auto.h"

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");
    Auto::Numobject();
    Auto ob1("BMW", 300, 1999, 750000);
    ob1.Show();
    Auto ob2 = ob1;
    ob2.Show();
    std::cout << "Текущая стоимость "<< ob2.calc(2)<<std::endl;
    Auto* pm = new Auto("Toyota", 300, 2000, 500000);
    pm->Show();
    std::cout << "Текущая стоимость " << ob2.calc(2) << std::endl;
    Auto::Numobject();
    delete pm;
    Auto::Numobject();
    Auto* parr = new Auto[5];
    Auto::Numobject();
    for (int i = 0; i < 5; i++)
    {
        parr[i].Show();
    }
    delete[]parr;
    Auto::Numobject();
    system("pause");
}


