#pragma once

#include <iostream>

using namespace std;

struct Struct {
	int value;
	int height = 1;

	Struct* parent = nullptr;
	Struct* left = nullptr;
	Struct* right = nullptr;
};

struct Trunk {
	Trunk* prev;
	string str;

	Trunk(Trunk* prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

class Tree {
	Struct* head = nullptr;

	void bfs_func();
	int bfactor(Struct* node);
	int getHeight(Struct* node);
	void showTrunks(Trunk* p);
	void fixHeight(Struct* node);
	void printTree(Struct* root, Trunk* prev, bool isLeft);
	Struct* insert(Struct* node, Struct* parent, int val);
	Struct* rotateRight(Struct* node, Struct* parent);
	Struct* rotateLeft(Struct* node, Struct* parent);
	Struct* balance(Struct* node, Struct* parent);
	Struct* findmin(Struct* node);
	Struct* removemin(Struct* node, Struct* parent);
	Struct* del(Struct* node, Struct* parent, int val);
	Struct* del(Struct* node, Struct* parent);
	Struct* get(Struct* node, int val, int step);

public:
	Struct* find(int val);
	Struct* getHead();
	void remove(int val);
	void add(int val);
	void show();
	void func();
	void bfs();
};