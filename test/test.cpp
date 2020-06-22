
#include <string>
#include <iostream>
using namespace std;
template <typename T>
class List
{

public:

    List();
    ~List();

    // Методы
    void push_front(T data); // добавление в начало списка
    void insertAt(T data, int index); // добавление по индексу
    void removeAt(int index); // удаление по индексу
    void pop_back();

    void clear();
    void pop_front(); // удаление первого элемента
    void push_back(T data); // добавление в конец списка
    int GetSize(); // размер списка

    // Перегрузка операторов
    T& operator[](const int index);

private:

    template <typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;
};

template <typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List()
{
    cout << "Вызван деструктор List" << endl;
    clear();
}

// Методы

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);// создаем  новый head
    Size++;
}

template<typename T>
void List<T>::insertAt(T value, int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else 
    {
        Node<T>* previous = this->head;
        // находим елемент предшествующий тому элементу который мы ищем
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        // создаем новый элемент
        Node<T>* newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        // находим елемент предшествующий тому элементу который мы ищем
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
int List<T>::GetSize()
{
    return Size;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    List<int> lst;
    lst.push_back(55);
    lst.push_back(11);
    lst.push_back(2);

    lst.push_front(5);
    lst.push_front(7);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << "List element " << lst[i] << endl;
    }

    cout << endl << "InsertAt " << endl << endl;
    lst.insertAt(99, 1);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << "List element " << lst[i] << endl;
    }

    cout << endl << "removeAt " << endl << endl;
    lst.removeAt(1);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << "List element " << lst[i] << endl;
    }

    cout << endl << "pop_back " << endl << endl;
    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << "List element " << lst[i] << endl;
    }

    /*cout << endl << "Элементов в списке  " << lst.GetSize() << endl <<
        "выполняем метод clear " << endl << endl;

    lst.clear();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << "List element " << lst[i] << endl;
    }
    
    cout << endl << "Элементов в списке  " << lst.GetSize() << endl;*/

    //cout << lst.GetSize() << endl;
    //cout << lst[2] << endl;

    /*int numbersCount;
    cout << "Enter count list element -> ";
    cin >> numbersCount;

    for (size_t i = 0; i < numbersCount; i++)
    {
        lst.push_back(rand() % 10);
    }*/

    

    system("pause");
}

