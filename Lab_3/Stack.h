#pragma once

#include <string>
#include <iostream>
#include "Task.h"

using namespace std;

class Stack {
	
	struct Node {
		Task data;
		Node* next = nullptr;
	};

	Node* head = new Node;

	bool is_empty = 1;

public:
	void push(Task value);
	Task read();
	int getPriority();
	void clear();
	void show();
	bool isEmpty();

	~Stack();
};