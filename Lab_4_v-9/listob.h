#pragma once
#include <iostream>
using namespace std;


template <class DataT> class listob { // ��� ����

public:
	DataT* info; // ���������� ������ ��������
	listob<DataT>* next; // ��������� �� ��������� ������
	listob<DataT>* prev; // ��������� �� ���������� ������

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

template <class DataT> class dllist : public listob<DataT> { // ������

	listob<DataT>* start;
	listob<DataT>* end;

public:
	// �����������
	dllist() {
		start = NULL;
		end = NULL;
	}
	// ����������
	~dllist();

	// ������
	void store(DataT* c); // ���������� ������ ��������

	void show(); // ����������� ������ � ������
	void input(int n); //���� ������ � ������ ������

	// ������ ������� � �����
	listob<DataT>* begin() {
		return start; // ��������� �� ������ ������
	}
	listob<DataT>* tail() {
		return end; // ��������� �� ����� ������
	}
};

// ���������� dllist
template <class DataT> dllist <DataT>::~dllist() {
	listob<DataT>* p;
	p = start;
	while (p) {
		start = start->next;
		delete p->info; // ���� ���� ������� ������ ���� �� ������ �� �� �����
		delete p; // ������� ��� ���� ������
		p = start;
	}
}

// ���������� ���� � ����� ������
template <class DataT> void dllist<DataT>::store(DataT* c) {
	listob* o = new listob(c); // �������� � ����������� ������ �� ���������
	if (start == NULL) // ���� ������ ������ ��� �� ������ ����
		start = end = o;
	else { // ���� �� ������ ���� ������ �� ������
		o->prev = end;
		end->next = o;
		end = o;
	}
}
// ����� show ������� ���� ������ � �������������
template  <class DataT> 
void dllist <DataT>::show() {
	listob* temp = start;
	while (temp != NULL) {
		temp->info->Show(cout); // ����� �������� Show info- �������� ������������� ���� �� ����� ��������� ������� ���� 3� �������
		temp = temp->next; // ����� �� ��������� ����
	}
}

// ������������� show
//template <> void dllist <int>::show() {
//	listob* tmp = start;
//	while (tmp != NULL) {
//		cout << *tmp->info;
//		tmp =tmp->next;
//	}
//}

// ���� ������ � ���� n
template <class DataT> 
void dllist <DataT>::input(int n) {
	listob* temp = start; // ��� ��������� ��������� start
	int i = 0;
	while (i != n) {
		temp = temp->next;
		i++;
	}
	temp->info->Input(cin); // ��� ����� �� ������ ������� ������ ��������� �� ��������� info
}

// ������������� input
//template <> void dllist <int> ::input(int n) {
//	listob* tmp = start;
//	int i = 0;
//	while (i != n) {
//		tmp = tmp->next;
//		i++;
//	}
//	cin >> *tmp->info;
//}

// �������� ������
template <class DataT> class iter {

private:
	listob<DataT>* elem; // �������� �� ������� ������
	dllist<DataT>* list; // ��������� �� ������

public:
	iter(dllist<DataT>& el) { // ����������� ��������� �� ������
		elem = el.begin(); // ��������� �� ������ ������ start � dllist
		list = &el; // ������ ������
	}

	listob<DataT>* operator++(int) { // ��� �����
		if (elem != NULL) elem = elem->next;
		return elem; // ���������� ��������� �� ����
	}

	listob<DataT>* operator--(int) { // ��� �����
		if (elem != NULL) elem = elem->prev;
		return elem;
	}

	DataT* operator*() { // ������������� �������� ������ ��� �������� � ����
		if (elem != NULL)
			return elem->info;
	}

	iter& operator=(listob<DataT>* it) { // ������������
		elem = it;
		return *this;
	}

	void end() { //��������� �� ����� ������
		elem = list->tail();
	}

	void begin() { // ��������� �� ������ ������
		elem = list->begin();
	}

	bool isend() { // �������� ���������� �����
		if (elem == NULL)
			return true;
		else return false;
	}

	bool isbegin() { // �������� ���������� ������
		if (elem == NULL)
			return true;
		else return false;
	}
};