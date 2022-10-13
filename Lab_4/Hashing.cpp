#include <iostream>
#include <fstream>
#include <string>

#include "HashTable.h"

using namespace std;

// Generating random key
string generateKey(string* letters, string* numbers) {

	string temp_str = "";

	for (int k = 0; k < 6; k++) {
		if (k < 2 || k > 3) {
			temp_str += numbers[std::rand() % 10];
		}
		else {
			temp_str += letters[std::rand() % 26];
		}
	}

	return temp_str;
}

// Get hash key from string and amount of segments
int getHashKey(string s, int seg_amt) {
	int temp = 0;

	for (int i = 0; i < s.length(); i++) {
		temp += s[i] * s[i];
	}
	temp %= seg_amt;

	return temp;
}

string* getLettersAlphabet() {
	string* letters = new string[26];

	char temp = 'A';

	for (int i = 0; i < 26; i++) {
		letters[i] = temp++;
	}

	return letters;
}

string* getNumbersList() {
	string* numbers = new string[10];

	char temp = '0';

	for (int i = 0; i < 10; i++) {
		numbers[i] = temp++;
	}

	return numbers;
}

// Allocating collisions for 2x amount of keys to segments and output to Excel
void allocCollisions(int* coll_array, int size) {
	ofstream out;
	out.open("D:\\Other\\C++ Scripts\\Structs_And_Algo_SUAI\\Lab_4\\Kollision_Allocation.csv");

	for (int i = 0; i < size; i++) {
		out << coll_array[i] << "\t";
	}

	out.close();
}

bool checkKey(string key) {
	if (key.length() != 6)
		return false;

	if (key[0] >= '0' && key[0] <= '9' &&
		key[1] >= '0' && key[1] <= '9' &&
		key[2] >= 'A' && key[2] <= 'Z' &&
		key[3] >= 'A' && key[3] <= 'Z' &&
		key[4] >= '0' && key[4] <= '9' &&
		key[5] >= '0' && key[5] <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//while (true) {
//	cout << "Enter command ('help' - to get reference, 'exit' - to terminate): ";
//	string command;
//
//	cin >> command;
//
//	if (command == "exit")
//		break;
//	else if (command == "help") {
//		cout << "\n\n--- Command list ---\n" <<
//			"help - get reference,\n" <<
//			"create - create new hash table\n" <<
//			"add - add element to hash table\n" <<
//			"remove - remove element from hash table,\n" <<
//			"show - show hash table (index, key, all table)\n";
//
//	}
//	else if (command == "create") {
//	}
//}