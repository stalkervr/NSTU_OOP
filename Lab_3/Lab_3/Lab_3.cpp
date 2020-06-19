#include "Complex.h"
#include "T_Complex.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "  Демонстрация перегрузок операторов для класса Complex  " << endl;
    cout << endl;
    Complex a1(10.4, 6.6);
    Complex a2(5.2, 3.3);
    Complex a3, a4;
    cout << "  a1 = " << a1 << "\n  a2 = " << a2 << "\n  a3 = " << a3 << "\n  a4 = " << a4 << "\n" << endl;

    cout << "  Перегрузка оператора присваивания класса Complex  " << endl;
    a3 = a1;
    cout << "  a3 = " << a3 << endl;
    cout << endl;
    cout << "  Перегрузка оператора сложения класса Complex  " << endl;
    a3 = a1 + a2;
    cout << "  a3 = " << a3 << endl;
    cout << endl;
    cout << "  Перегрузка оператора вычитания класса Complex  " << endl;
    a3 = a1 - a2;
    cout << "  a3 = " << a3 << endl;
    cout << endl;
    cout << "  Перегрузка оператора умножения класса Complex  " << endl;
    a3 = a1 * a2;
    cout << "  a3 = " << a3 << endl;
    cout << endl;
    cout << "  Перегрузка оператора деления класса Complex  " << endl;
    a3 = a1 / a2;
    cout << "  a3 = " << a3 << endl;
    cout << endl;
    cout << "  Перегрузка оператора проверки на равенство класса Complex  " << endl;
    cout << "  a1 = " << a1 << "\n  a3 = " << a3 << "\n" << endl;
    if (a1 == a3) {
        std::cout << "  Числа равны \n";
    }
    else {
        std::cout << "  Числа не равны \n";
    }
    cout << endl;
    cout << "  Перегрузка оператора вызова функции класса Complex  " << endl;
    cout << "  как преобразование строки в комплексное число  " << endl;
    cout << "  вызов  a4(""8,1 + 5,2*i"") \n" << endl;
    a4("8,1+5,2*i");
    cout << "  " << a4 << "\n" << endl;
    cout << "  Перегрузка оператора вызова функции класса Complex  " << endl;
    cout << "  как операции получения тригенометрической формы числа \n  вызов a1()\n" << endl;
    cout << "  " << a1() << endl;
    cout << "\n  Перегрузка оператора входного потока класса Complex  \n" << endl;
    /*Complex a5;
    cout << "  Введите комплексноечисло в виде -> ""8,1+5,2*i""  ->  " << endl;
    cin >> a5;
    cout << "  Вы ввели число ->  " << a5 << endl;
    cout << "  Тригенометрическая форма числа ->  " << a5() << endl;*/

    Data data;

    cout << data << endl;

    T_Complex y(3.0,5);
    cout << "  Перегрузка оператора вызова функции класса Complex  " << endl;
    cout << "  как операции получения тригенометрической формы числа \n  вызов y()\n" << endl;
    cout << "  " << y() << endl;



    _getwch();
    return 0;
}


