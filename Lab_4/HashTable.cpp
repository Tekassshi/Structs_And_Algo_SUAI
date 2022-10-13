#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

HashTable::HashTable(int size) {
	table = new HashElem[size];
	table_size = size;
	collisions = new int[size];

	for (int i = 0; i < size; i++) {
		collisions[i] = 0;
	}
}

bool HashTable::isEmpty(int ind) {
	if (table[ind].status == "empty" || table[ind].status == "deleted")
		return true;
	else
		return false;
}

bool HashTable::isExist(int ind, string key) {
	if (table[ind].status == "filled" && table[ind].key == key)
		return true;
	else
		return false;
}

void HashTable::add(string key, string value) {

	if (!checkKey(key)) {
		cout << "\nKey: " << key << " - Wrong key format!\n\n";
		return;
	}

	int ind;
	ind = getHashKey(key, table_size);

	collisions[ind] += 1;

	if (isExist(ind, key)) {
		cout << "\nKey: " << key << " - This key value is already exist!\n\n";

		return;
	}
	else if (isEmpty(ind)) {
		table[ind].value = value;
		table[ind].status = "filled";
		table[ind].key = key;
	}
	else {
		int attemp = 0;
		int c = 1;
		int attemp_ind = ind;
		bool f = 0;

		while (attemp < table_size/2) {

			// Linear sampling step
			attemp_ind += 3 * c;

			if (attemp_ind > table_size - 1) {
				attemp_ind = attemp;
				attemp += 1;
				c = attemp;
			}

			if (isExist(attemp_ind, key)) {
				cout << "\n\nKey: " << key << " - this key value is already exist!\n\n";
				return;
			}
			else if (isEmpty(attemp_ind)) {
				table[attemp_ind].value = value;
				table[attemp_ind].status = "filled";
				table[attemp_ind].key = key;

				f = 1;
				break;
			}
		}

		if (f == 0) {
			cout << "Trying key: " << key << " - ";
			cout << "Hash table overflow!\n\n";
		}
	}
}

void HashTable::remove(string key) {
	if (!checkKey(key)) {
		cout << "\nKey: " << key << " - Wrong key format!\n\n";
		return;
	}

	int ind;
	ind = getHashKey(key, table_size);

	if (table[ind].status == "filled") {
		table[ind].status = "deleted";
		table[ind].value = "empty";
		table[ind].key = "empty";

		cout << "\n'" << key << "' - was removed succesfully!\n\n";
	}
	else {
		int attemp = 0;
		int c = 1;
		int attemp_ind = ind;
		bool f = 0;

		while (attemp < table_size / 2) {

			// Linear sampling step
			attemp_ind += 3 * c;

			if (attemp_ind > table_size - 1) {
				attemp_ind = attemp;
				attemp += 1;
				c = attemp;
			}

			if (table[attemp_ind].status == "filled" && table[attemp_ind].key == key) {
				table[attemp_ind].status = "deleted";
				table[attemp_ind].value = "empty";
				table[attemp_ind].key = "empty";

				cout << "\n\n\'" << key << "' - was removed succesfully!\n\n";

				f = 1;
				break;
			}
				
		}

		if (f == 0) {
			cout << "Deleting key: " << key << " - ";
			cout << "This key value does not exist!\n\n";
		}
	}
}

HashElem HashTable::get(string key) {

	HashElem temp;

	if (!checkKey(key)) {
		cout << "\nKey: " << key << " - Wrong key format!\n\n";
		return temp;
	}

	int ind;
	ind = getHashKey(key, table_size);

	if (table[ind].status == "filled" && table[ind].key == key) {
		return table[ind];
	}
	else {
		int attemp = 0;
		int c = 1;
		int attemp_ind = ind;
		bool f = 0;

		while (attemp < table_size / 2) {

			// Linear sampling step
			attemp_ind += 3 * c;

			if (attemp_ind > table_size - 1) {
				attemp_ind = attemp;
				attemp += 1;
				c = attemp;
			}

			if (table[attemp_ind].status == "filled" && table[attemp_ind].key == key) {
				return table[attemp_ind];
				f = 1;

				break;
			}

		}
		if (f == 0) {
			cout << "Key: " << key << " - Element doesn't exist!\n\n";
		}
	}

	return temp;
}


HashElem HashTable::get(int ind) {
	return table[ind];
}

void HashTable::show() {
	for (int i = 0; i < table_size; i++) {
		HashElem temp = table[i];

		cout << "Segment: " << i << "\n";
		cout << "Key: " << temp.key << "\n";
		cout << "Value: " << temp.value << "\n";
		cout << "Status: " << temp.status << "\n\n";
	}
}

void HashTable::show(string key) {
	show(get(key));
}

void HashTable::show(int i) {
	HashElem temp = table[i];

	cout << "Segment: " << i << "\n";
	cout << "Key: " << temp.key << "\n";
	cout << "Value: " << temp.value << "\n";
	cout << "Status: " << temp.status << "\n\n";
}

void HashTable::show(HashElem elem) {

	cout << "Key: " << elem.key << "\n";
	cout << "Value: " << elem.value << "\n";
	cout << "Status: " << elem.status << "\n\n";
}

int* HashTable::getCollArr() {
	return collisions;
}

HashTable::~HashTable() {
	delete[] table;
	delete[] collisions;
}