#pragma once

#include <string>

using namespace std;

string generateKey(string* letters, string* numbers);

int getHashKey(string s, int seg_amt);

string* getLettersAlphabet();
string* getNumbersList();

void allocCollisions(int* coll_array, int size);

bool checkKey(string key);

struct HashElem {
	string key = "empty";
	string value = "empty";

	string status = "empty";
};

class HashTable {
	HashElem* table;
	int table_size;

	bool isEmpty(int ind);
	bool isExist(int ind, string key);

	int* collisions;

public:

	HashTable(int size);

	void add(string key, string value);
	void remove(string key);
	HashElem get(string key);
	HashElem get(int ind);

	void show();
	void show(string key);
	void show(int seg);
	void show(HashElem elem);
	int* getCollArr();

	~HashTable();
};