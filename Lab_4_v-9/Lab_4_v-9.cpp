using namespace std;

#include <iostream>
#include "complex.h"
#include "com_date.h"
#include "com_string.h"
#include "my_list.h"

void print_line();

int main()
{
    setlocale(LC_ALL, "Russian");

	Complex* a = new Complex();
    Complex* b = new  Date(1.3, 6.5, 10, 11, 2018);
    Complex* c = new ComString("5,4+8,3*i");
    Complex* d = new ComString("15,5+22,3*i");

    List<Complex> list_1;

    list_1.push_back(a);
    list_1.push_back(b);
    list_1.push_back(c);

    cout << "  Вывод всех элементов списка" << endl;
    list_1.show();
    print_line();
    cout << endl;

    cout << "  Вставка элемента 15,5+22,3*i по индексу 1 " << endl;
    list_1.insertAt(d, 1);
    list_1.show();
    print_line();
    cout << endl;

    cout << "  Удаление элемента 15,5+22,3*i по индексу 1 " << endl;
    list_1.removeAt(1);
    list_1.show();
    print_line();
    cout << endl;

    cout << "  Добавление элемента 15,5+22,3*i в конец списка " << endl;
    list_1.push_back(d);
    list_1.show();
    print_line();
    cout << endl;

    cout << "  Удаление последнего элемента списка " << endl;
    list_1.pop_back();
    list_1.show();
    print_line();
    cout << endl;

    cout << "  Добавление элемента 15,5+22,3*i в начало списка " << endl;
    list_1.push_front(d);
    list_1.show();
    print_line();
    cout << endl;

    cout << "  Удаление первого элемента списка " << endl;
    list_1.pop_front();
    list_1.show();
    print_line();
    cout << endl;

    cout << "  Ввод данных в элемент по индексу 0 " << endl;
    list_1.input(0);
    list_1.show();
    print_line();
    cout << endl;
    system("pause");
    system("cls");

    List<int> list_2;
    cout << "  Тестирование специализации " << endl;
    list_2.push_back(new int(2));
    list_2.push_back(new int(10));
    list_2.push_back(new int(15));
    list_2.push_back(new int(25));
    list_2.push_back(new int(222));
    list_2.push_back(new int(50));
    list_2.show();

    system("pause");
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




