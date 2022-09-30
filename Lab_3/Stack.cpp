#include <iostream>
#include <string>

#include "Stack.h"
#include "TaskManager.h"

using namespace std;

void Stack::push(Task value) {
	if ((head->data).arrival_time == "-1") {
		head->data = value;
	}
	else {
		Node* obj = new Node;
		obj->data = value;
		obj->next = head;
		head = obj;
	}

	is_empty = 0;
}

Task Stack::read() {
	Task temp = head->data;
	Node* temp_pointer = head;

	if (head->next == nullptr) {
		head = nullptr;

		is_empty = 1;
	}
	else {
		head = head->next;
	}
	delete temp_pointer;
	return temp;
}

int Stack::getPriority() {
	Task temp = head->data;

	return (temp.priority);
}

void Stack::show() {
	if (is_empty) {
		cout << "Стек пуст.\n";
		return;
	}

	Node* pointer = head;

	while (pointer->next != nullptr) {
		TaskManager::show(pointer->data);

		pointer = pointer->next;
	}

	TaskManager::show(pointer->data);
	cout << "\n\n";
}

void Stack::clear() {
	Node* pointer = head;

	while (pointer != nullptr) {
		Node* temp = pointer;
		pointer = pointer->next;

		delete temp;
	}

	is_empty = 1;
	head = nullptr;
}

bool Stack::isEmpty() {
	return is_empty;
}

Stack::~Stack() {};