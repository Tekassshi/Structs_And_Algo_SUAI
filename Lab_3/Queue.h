#pragma once

#include <string>
#include <iostream>
#include "TaskManager.h";

using namespace std;

class Queue {

	struct Node {
		Task data;
		Node* next = nullptr;
		Node* previous = nullptr;
	};

	Node* out = new Node;
	Node* in = out;

	bool is_empty = 1;

public:
	void push(Task value);
	Task read();
	void clear();
	void show();
	bool isEmpty();
	int getPriority();

	~Queue();
};