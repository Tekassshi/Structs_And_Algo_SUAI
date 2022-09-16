#include <iostream>
#include "Struct.h"
#include <string>

using namespace std;

List* add(List* list, int num) {
	List* value = new List();
	value->data = num;

	if (list == nullptr) {
		return value;
	}
	// Элемент перед опорным
	List* previous = list->previous;

	// Вставить новый элемент перед опорным и предпоследним
	previous->next = value;
	value->previous = previous;
	value->next = list;
	list->previous = value;

	return list;
}

List* erase(List* list, int value) {

	if (list == nullptr)
		return list;

	List* pivot = list;
	List* pointer = list;

	int k = 0;

	while (pointer != pivot || k == 0) {
		if (pointer->data == value) {

			List* previous = pointer->previous;
			List* next = pointer->next;

			previous->next = next;
			next->previous = previous;


			// Удаление опорного элемента списка
			if (pointer == list) {

				if (pointer->next == list) {
					delete pointer;
					return nullptr;
				}

				delete pointer;
				return next;
			}

			delete pointer;
			return list;
		}

		pointer = pointer->next;

		k++;
	}

	return list;
}

void erase(List* list) {

	if (list == nullptr) {
		return;
	}

	List* last = list->previous;

	while (list != last) {
		List* temp = list;
		list = list->next;

		delete temp;
	}

	delete last;
}

void show(List* list, string str) {

	if (list == nullptr) {
		cout << str << "Your list is empty!" << endl;
		return;
	}

	List* pivot = list;
	List* pointer = list;

	cout << endl << str;

	while (pointer != pivot->previous) {
		List* previous = pointer->previous;
		List* next = pointer->next;

		// Вывод элемента списка, предыдущего и следующего (для проверки)
		/*cout << pointer->data << "   " << previous->data << "   " << next->data << endl;*/

		cout << pointer->data << " ";

		pointer = pointer->next;
	}

	// Последний элемент списка
	cout << pointer->data;

	// Для демонстрации работы списка
	/*List* previous = pointer->previous;
	List* next = pointer->next;
	cout << pointer->data << "   " << previous->data << "   " << next->data << endl;*/

	cout << endl << endl;
}

List* fill(List* list) {

	cout << "Введите длину списка: ";
	int a; cin >> a;

	if (a == 0) {
		return nullptr;
	}

	cout << endl << "Введите элементы списка: ";
	int num;

	for (int i = 0; i < a; i++) {
		cin >> num;

		if (i == 0) {
			list->data = num;
		}
		else {
			list = add(list, num);
		}
		
	}
	
	return list;
}

List* getReflected(List* list) {

	if (list == nullptr) {
		List* value = nullptr;
		return value;
	}

	if (list->next == list) {
		List* value = new List();
		return value;
	}

	List* pointer_origin = list->previous;
	List* pointer_out = list->previous;

	List* out = new List();

	while (pointer_origin != list) {
		if (pointer_origin == list->previous) {
			out->data = pointer_origin->data;
		}
		else {
			add(out, pointer_origin->data);
		}

		pointer_origin = pointer_origin->previous;
	}

	// Добавление опорного элемента
	add(out, pointer_origin->data);

	return out;
}

List* getDifference(List* list1, List* list2) {

	if (list1 == nullptr) {
		return list1;
	}

	List* out = new List();

	List* list1_pointer = list1;
	List* list2_pointer = list2;

	out->data = list1_pointer->data - list2_pointer->data;
	
	list1_pointer = list1_pointer->next;
	list2_pointer = list2_pointer->next;

	while (list1_pointer != list1) {
		add(out, list1_pointer->data - list2_pointer->data);

		list1_pointer = list1_pointer->next;
		list2_pointer = list2_pointer->next;
	}

	return out;
}