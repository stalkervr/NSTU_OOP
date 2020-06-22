#include <string>
#include <iostream>
using namespace std;
template <typename T>
class List
{

public:

    List();
    ~List();

    // ������
    void push_back(T* data); // ���������� � ����� ������
    void pop_back();// �������� ���������� ��������

    void push_front(T* data); // ���������� � ������ ������
    void pop_front(); // �������� ������� �������� ������

    void removeAt(int); // �������� �� �������
    void insertAt(T* data, int index); // ������� �� �������

    void clear(); // �������� ���� ��������� ������
    int GetSize(); // ���������� ���������

    void show(); // �������� ���� ���������
    void input(int n); // ��������� �������� �� �������

    // ���������� ����������
    //T& operator[](const int index);

private:

    template <typename T>
    class Node
    {
    public:
        Node* pNext;
        T* data;

        Node(T* data = nullptr, Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;
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
    //cout << "������ ���������� List" << endl;
    clear();
}
// ������
// ���������� � ������ ������
template<typename T>
inline void List<T>::push_front(T* data)
{
    head = new Node<T>(data, head);// �������  ����� head
    Size++;
}
// �������� ���� ��������� ������
template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}
// �������� ���������� ��������
template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}
// �������� �� �������
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
        // ������� ������� �������������� ���� �������� ������� �� ����
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
// ������� �� �������
template<typename T>
void List<T>::insertAt(T* value, int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        Node<T>* previous = this->head;
        // ������� ������� �������������� ���� �������� ������� �� ����
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        // ������� ����� �������
        Node<T>* newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}
// �������� ������� �������� ������
template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}
// ���������� � ����� ������
template<typename T>
void List<T>::push_back(T* data)
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
// ���������� ���������
template<typename T>
int List<T>::GetSize()
{
    return Size;
}
// �������� ���� ���������
template<typename T>
inline void List<T>::show()
{
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        current->data->Show(cout);
        current = current->pNext;
    }
}

// ������������� show
template <> 
void List <int>::show() {
	Node<int>* tmp = head;
	while (tmp != NULL) {
		cout << *tmp->data << "\n";
		tmp =tmp->pNext;
	}
}

// ��������� �������� �� �������
template<typename T>
inline void List<T>::input(int n)
{
    Node<T>* current = this->head;
    int i = 0;
    while (i != n) {
        current = current->pNext;
        i++;
    }
    current->data->Input(cin);
}

// ������������� input
template <> 
void List <int> ::input(int n) {
	Node<int>* tmp = head;
	int i = 0;
	while (i != n) {
		tmp = tmp->pNext;
		i++;
	}
	cin >> *tmp->data;
}

//template<typename T>
//T& List<T>::operator[](const int index)
//{
//    int counter = 0;
//    Node<T>* current = this->head;
//    while (current != nullptr)
//    {
//        if (counter == index)
//        {
//            return current->data;
//        }
//        current = current->pNext;
//        counter++;
//    }
//}
