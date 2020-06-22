#include "complex.h"
#include "com_date.h"
#include "com_string.h"

void print_line();

int main()
{
    setlocale(LC_ALL, "Russian");
    Date obj_1, * obj_2 = nullptr, *obj_3 = nullptr;

    cout << "  Лабораторная работа № 3" << endl;

    cout << "\n  Проверка работы класса Date  " 
         << "  создание объекта без параметров.\n" << endl;
    Date test_date;
    cout << "  " << test_date << endl;

    cout << "\n  Проверка работы класса Date  "
         << "  изменение даты создания объекта на 1, 1, 2012.\n" << endl;
    test_date.setdate(1, 1, 2012);
    cout << "  " << test_date << endl;

    cout << "\n  Проверка работы метода getdate() класса Date  "
         << "  вывод даты в консоль.\n" << endl;
    test_date.getdate();

    print_line();
    cout << "  Проверка обработки исключений класса Date  \n" << endl;

    try
    {
        obj_2 = new Date(5.3, 6.4, 30, 11, 2001);
        cout << "  " << *obj_2 << endl;
    }
    catch (Date::ParamExeption e)
    {
        cout << "  Задана дата => " << e.day<<"."<<e.mon<<"."<<e.year << endl;
        cout << "  Введена не верная дата. \n  Объект не создан." << endl;
    }
    print_line();
    try
    {
        obj_3 = new Date(3.3, 6.4, 30, 13, 2005);
        cout << "  " << *obj_3 << endl;
    }
    catch (Date::ParamExeption e)
    {
        cout << "  Задана дата => " << e.day << "." << e.mon << "." << e.year << endl;
        cout << "  Введена не верная дата. \n  Объект не создан." << endl;
    }
  
    print_line();
    cout << "  Проверка работы ввода данных класса Date  \n" << endl;
    //cout << "  " << obj_1 << endl;
    do {
        try {
            cin >> obj_1;
            break;
        }
        catch (const char* str)
        {
            cout << str << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    } while (true);
    cout << "  " << obj_1<< endl;
    print_line();

    _getwch();
    system("cls");

    print_line();
    cout << "\n  Проверка работы класса ComSting  \n" << endl;

    ComString str_1, *str_2 = nullptr, * str_3 = nullptr;
 
    cout << "  Проверка обработки исключений класса ComString  \n" << endl;
    try
    {
        str_2 = new ComString("8,1+5,2*i");
        cout <<"  Создан объект типа ComString "<< *str_2 << endl;
    }
    catch (ComString::ParamExeption e)
    {
        cout << "  Введённая строка => " << e.str << endl;
        cout << "  Не соответствует формату. \n  Объект не создан." << endl;
        cout << "  Строка должна быть вида -> ""8,1+5,2*i""" << endl;
    }
    print_line();
    try
    {
        str_3 = new ComString("3,1");
        cout << "  Создан объект типа ComString " << *str_3 << endl;
    }
    catch (ComString::ParamExeption e)
    {
        cout << "  Введённая строка => " << e.str << endl;
        cout << "  Не соответствует формату. \n  Объект не создан." << endl;
        cout << "  Строка должна быть вида -> ""8,1+5,2*i""" << endl;
    }


    print_line();
    cout << "  Проверка работы ввода данных класса ComString  \n" << endl;

    do {
        try {
            cin >> str_1;
            break;
        }
        catch (ComString::ParamExeption e)
        {
            cout << "  Введённая строка => " << e.str << endl;
            cout << "  Не соответствует формату ! \n  Повторите ввод." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    } while (true);
    cout << "  Агебраическая форма числа " << str_1 << endl;


    print_line();
    cout << "  Проверка работы методов преобразования класса ComString  \n" << endl;

    ComString str_4(5.1,4.3);

    cout << "  Агебраическая форма числа " << str_4 << endl;
    cout << "  Тригенометрическая форма записи " << str_4.getTrigNumber() << endl;

    char* test = str_4.convertToString();

    int len = strlen(test);
    cout <<"  Объект типа ComString конвертирован в строку "<< test 
         <<"  Length string = "<<len<<endl;

    Complex com_1 = str_4.convertToComplex();

    cout <<"  Объект типа ComString конвертирован в тип Complex = " << com_1 << endl;
    _getwch();
    return 0;
}

void print_line()
{
    cout << "\n  ";
    for (int i = 0; i < 74; i++)
    {
        cout << "-";
    }
    cout << "\n";
}