// Var 22
// –еализаци€ циклического двунаправленного списка


// Memory leaks testing
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <iostream>
#include "Struct.h"
#include <string>;

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	List* list = new List();

	list = fill(list);

	show(list, "Your origin list: ");


	List* reflected = getReflected(list);
	show(reflected, "Your reflected list: ");

	List* difference = getDifference(list, reflected);
	show(difference, "List of differences: ");

	cout << endl <<  "¬ведите число дл€ удалени€ из списка: ";
	int num; cin >> num;
	list = erase(list, num);

	show(list, "Result: ");

	cout << endl << "¬ведите значение дл€ добавлени€ в список: ";
	cin >> num;
	list = add(list, num);

	show(list, "Result: ");

	// Clearing memory
	erase(list);

	erase(difference);
	erase(reflected);


	_CrtDumpMemoryLeaks();
	return 0;
}