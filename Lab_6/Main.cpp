// Var 20

#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
	Tree tree;

	int n, v;
	cout << "Enter amount of elements you want to add: "; cin >> n;
	cout << "\nEnter your elements:\n";
	
	for (int i = 0; i < n; i++) {
		cin >> v;
		tree.add(i);
	}

	cout << "\n\nYour tree:\n\n";
	tree.show();

	cout << "\n\nEnter element to find: "; cin >> v;
	tree.find(v);

	cout << "\n\nEnter element to delete: "; cin >> v;
	tree.remove(v);

	cout << "\n\nResult\n\n";
	tree.show();

	cout << "\n\nBreadth first search\n\n";
	tree.bfs();

	cout << "\n\nFunction process\n\n";
	tree.func();
}