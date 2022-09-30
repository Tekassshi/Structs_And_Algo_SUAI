#include <iostream>
#include <windows.h>
#include <string>
#include "TaskManager.h"

using namespace std;

bool getRandom() {
	double i;
	i = rand() % 100;

	return (i < 70 ? true : false);
}

string get_Time() {
	SYSTEMTIME st;
	GetSystemTime(&st);

	return ((to_string(st.wHour + 3) + ":" + to_string(st.wMinute) + ":" + to_string(st.wSecond) + ":" + to_string(st.wMilliseconds)));
}

Task TaskManager::generateTask() {
	Task task;

	task.execution_time = 1 + rand() % 4;

	int i;
	i = 1 + rand() % 3;

	switch (i)
	{
	case 1:
		task.priority = 1;
		break;
	case 2:
		task.priority = 2;
		break;
	case 3:
		task.priority = 3;
		break;
	}

	task.arrival_time = get_Time();

	return task;
}

Task TaskManager::createTask() {
	Task task;

	int value;

	while (true) {
		cout << "Введите время исполнения задачи (число от 1 до 4): "; cin >> value; cout << endl;
		task.execution_time = value;

		cout << "Введите приоритет задачи (число от 1 до 3): "; cin >> value; cout << endl;
		task.priority = value;

		if ((task.execution_time > 4 || task.execution_time < 1) ||
			(task.priority > 3 || task.priority < 1)) {
			cout << "Некорректные данные, повторите ввод!" << endl;
			continue;
		}

		break;
	}

	task.arrival_time = get_Time();

	return task;
}

void TaskManager::show(Task task) {
	cout << "Время поступления задачи: " << task.arrival_time << ",  ";
	cout << "Приоритет задачи: " << task.priority << ", ";
	cout << "Такт задачи: " << task.execution_time << ", \n";
}