// Var 18

#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

int main() {
	/*cout << getHashKey("70CK69", 2000) << "\n";
	cout << getHashKey("13ML12", 2000) << "\n";*/

	HashTable table(10);

	table.add("70CK69", "First key");
	table.add("13ML12", "Second key");

	table.show();

	table.add("13ML12", "Second key");

	table.show();

	table.remove("70CK69");
	
	table.show(table.get("13ML12"));

	// Collision allocation

	/*HashTable test_table(2000);

	for (int i = 0; i < 4000; i++) {
		string key = generateKey(getLettersAlphabet(), getNumbersList());

		test_table.add(key, "-------");
	}

	test_table.show();

	allocCollisions(test_table.getCollArr(), 2000);*/
}