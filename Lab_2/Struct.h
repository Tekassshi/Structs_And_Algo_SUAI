#pragma once

#ifndef STRUCT
#define STRUCT

struct List {
	int data;

	List* previous = this;
	List* next = this;
};

List* add(List* list, int num);
void show(List* list, std::string str);
List* fill(List* list);
List* erase(List* list, int value);
void erase(List* list);
List* getReflected(List* list);
List* getDifference(List* list1, List* list2);

#endif