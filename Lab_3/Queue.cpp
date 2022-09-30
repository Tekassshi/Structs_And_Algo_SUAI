#include <iostream>
#include <string>

#include "Queue.h"
#include "TaskManager.h"

using namespace std;

void Queue::push(Task value) {

	if (in->previous == nullptr && (in->data).arrival_time == "-1") {
		in->data = value;
	}
	else {
		Node* obj = new Node;
		obj->data = value;
		in->next = obj;
		obj->previous = in;
		in = obj;
	}

	is_empty = 0;
}

Task Queue::read() {

	Task temp_data = out->data;
	Node* temp_obj = out;

	if (out->next == nullptr) {
		out = new Node;
		in = out;
		is_empty = 1;
	}
	else {
		out = out->next;
	}

	delete temp_obj;
	return temp_data;
}

void Queue::show() {

	Node* pointer = out;

	if ((pointer->data).arrival_time == "-1" && pointer->next == nullptr) {
		cout << "Очередь пуста!\n\n";
		return;
	}

	while (pointer != nullptr) {
		TaskManager::show(pointer->data);
		pointer = pointer->next;
	}
	cout << "\n";
}

void Queue::clear() {
	Node* pointer = out;

	while (pointer != nullptr) {
		Node* temp = pointer;
		pointer = pointer->next;

		delete temp;
	}

	in = nullptr;
	out = nullptr;

	is_empty = 1;
}

int Queue::getPriority() {
	Task temp = out->data;

	return (temp.priority);
}

bool Queue::isEmpty() {
	return is_empty;
}

Queue::~Queue() {};