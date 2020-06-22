#pragma once
#include <iostream>
using namespace std;


template <class DataT> class listob { // это узел

public:
	DataT* info; // информация объект хранения
	listob<DataT>* next; // указатель на следующий объект
	listob<DataT>* prev; // указатель на предидущий объект

	listob() {
		info = &DataT();
		next = NULL;
		prev = NULL;
	}

	listob(DataT* c) {
		info = c;
		next = NULL;
		prev = NULL;
	}
};

template <class DataT> class dllist : public listob<DataT> { // список

	listob<DataT>* start;
	listob<DataT>* end;

public:
	// Конструктор
	dllist() {
		start = NULL;
		end = NULL;
	}
	// Деструктор
	~dllist();

	// Методы
	void store(DataT* c); // добавление нового элемента

	void show(); // отображение списка с начала
	void input(int n); //ввод данных в объект списка

	// Методы доступа к полям
	listob<DataT>* begin() {
		return start; // указатель на начало списка
	}
	listob<DataT>* tail() {
		return end; // указатель на конец списка
	}
};

// Деструктор dllist
template <class DataT> dllist <DataT>::~dllist() {
	listob<DataT>* p;
	p = start;
	while (p) {
		start = start->next;
		delete p->info; // если есть динамич данные если по ссылке то не нужно
		delete p; // удалить сам узел списка
		p = start;
	}
}

// Добавление узла в конец списка
template <class DataT> void dllist<DataT>::store(DataT* c) {
	listob* o = new listob(c); // передаем в конструктор объект по указателю
	if (start == NULL) // если список пустой нет ни одного узла
		start = end = o;
	else { // если не первый узел список не пустой
		o->prev = end;
		end->next = o;
		end = o;
	}
}
// Метод show обходит весь список и распечатывает
template  <class DataT> 
void dllist <DataT>::show() {
	listob* temp = start;
	while (temp != NULL) {
		temp->info->Show(cout); // метод объектов Show info- укзатель родительского типа но будет содержать объекты всех 3х классов
		temp = temp->next; // сдвиг на следующий узел
	}
}

// специализация show
//template <> void dllist <int>::show() {
//	listob* tmp = start;
//	while (tmp != NULL) {
//		cout << *tmp->info;
//		tmp =tmp->next;
//	}
//}

// ввод данных в узел n
template <class DataT> 
void dllist <DataT>::input(int n) {
	listob* temp = start; // лок указатель присвоить start
	int i = 0;
	while (i != n) {
		temp = temp->next;
		i++;
	}
	temp->info->Input(cin); // выз метод из класса который сейчас находится по указателю info
}

// специализация input
//template <> void dllist <int> ::input(int n) {
//	listob* tmp = start;
//	int i = 0;
//	while (i != n) {
//		tmp = tmp->next;
//		i++;
//	}
//	cin >> *tmp->info;
//}

// Итератор списка
template <class DataT> class iter {

private:
	listob<DataT>* elem; // укзатель на элемент списка
	dllist<DataT>* list; // указатель на список

public:
	iter(dllist<DataT>& el) { // конструктор установка на начало
		elem = el.begin(); // указатель на начало списка start в dllist
		list = &el; // адресс списка
	}

	listob<DataT>* operator++(int) { // шаг вперёд
		if (elem != NULL) elem = elem->next;
		return elem; // возвращает указатель на узел
	}

	listob<DataT>* operator--(int) { // шаг назад
		if (elem != NULL) elem = elem->prev;
		return elem;
	}

	DataT* operator*() { // разименование получить объект кот хранится в узле
		if (elem != NULL)
			return elem->info;
	}

	iter& operator=(listob<DataT>* it) { // присваивание
		elem = it;
		return *this;
	}

	void end() { //установка на конец списка
		elem = list->tail();
	}

	void begin() { // установка на начало списка
		elem = list->begin();
	}

	bool isend() { // проверка достижения конца
		if (elem == NULL)
			return true;
		else return false;
	}

	bool isbegin() { // проверка достижения начала
		if (elem == NULL)
			return true;
		else return false;
	}
};