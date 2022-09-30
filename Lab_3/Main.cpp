// Var 4

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <chrono>
#include <iostream>
#include <string>

#include "Stack.h"
#include "Queue.h"
#include "Task.h"
#include "TaskManager.h"
#include "Processor.h"

using namespace std;

string get_time();

int main() {
	setlocale(LC_ALL, "rus");

	Processor processor;
	Stack stack;

	Queue F0;
	Queue F1;
	Queue F2;

	Queue task_list;
	
	int checker;

	// Время поступления и последний вывод
	while (true) {
		cout << "Введите способ поступления задач (0 - вручную, 1 - генератор): ";
		cin >> checker;

		if (checker != 1 && checker != 0) {
			cout << "\nНекорректные данные, повторите ввод.\n";
			continue;
		}
		break;
	}

	if (checker == 0) {
		int r;
		cout << "Введите количество задач: "; cin >> r;

		for (int i = 0; i < r; i++) {
			Task task;
			task = TaskManager::createTask();
			task_list.push(task);
		}
	}
	else {
		int r;
		cout << "Введите количество задач: "; cin >> r;

		for (int i = 0; i < r; i++) {
			Task task;
			task = TaskManager::generateTask();
			task_list.push(task);
		}
	}
	
	int iterator = 1;

	// Start processing
	while (true) {

		cout << "\nТакт " + to_string(iterator) + ":\n";

		// Pushing random amount if new task from task list by 50% chance
		
		int changer = 1 + (std::rand() % 4);

		for (int k = 0; k < changer; k++) {
			if (task_list.isEmpty())
				break;

			if (getRandom()) {
				Task task = task_list.read();

				task.arrival_time = get_time();

				switch (task.priority)
				{
				case 1:
					F0.push(task);
					break;
				case 2:
					F1.push(task);
					break;
				case 3:
					F2.push(task);
					break;
				}
			}
		}

		int stack_active_priority;

		if (!stack.isEmpty()) {
			stack_active_priority = stack.getPriority();
		}
		else {
			stack_active_priority = 1000;
		}

		// Task distribution
		Task active_task = processor.getTask();
		
		if (stack_active_priority == 1 && stack_active_priority < active_task.priority) {
			processor.setTask(stack.read());

			if (active_task.priority != 1000)
				stack.push(active_task);
		}
		else if (!F0.isEmpty() && (F0.getPriority() < active_task.priority)) {
			processor.setTask(F0.read());

			if (active_task.priority != 1000)
				stack.push(active_task);
		}
		else if (stack_active_priority == 2 && stack_active_priority < active_task.priority) {
			processor.setTask(stack.read());

			if (active_task.priority != 1000)
				stack.push(active_task);
		}
		else if (!F1.isEmpty() && (F1.getPriority() < active_task.priority)) {
			processor.setTask(F1.read());

			if (active_task.priority != 1000)
				stack.push(active_task);
		}
		else if (stack_active_priority == 3 && stack_active_priority < active_task.priority) {
			processor.setTask(stack.read());

			if (active_task.priority != 1000)
				stack.push(active_task);
		}
		else if (!F2.isEmpty() && (F2.getPriority() < active_task.priority)) {
			processor.setTask(F2.read());

			if (active_task.priority != 1000)
				stack.push(active_task);
		}

		cout << "Процессор: "; processor.show(); cout << "\n";

		cout << "Стэк: \n"; 
		stack.show();

		cout << "\nОчередь F0: \n";
		F0.show();
		cout << "Очередь F1: \n";
		F1.show();
		cout << "Очередь F2: \n";
		F2.show();

		processor.process();
		iterator += 1;

		if (processor.isEmpty() && F0.isEmpty() && F1.isEmpty() && F2.isEmpty() &&
			stack.isEmpty() && task_list.isEmpty()) {

			cout << "\nТакт " + to_string(iterator) + ":\n";
			cout << "Процессор: "; processor.show(); cout << "\n";

			cout << "Стэк: \n";
			stack.show();

			cout << "\nОчередь F0: \n";
			F0.show();
			cout << "Очередь F1: \n";
			F1.show();
			cout << "Очередь F2: \n";
			F2.show();

			break;
		}

	}

	stack.clear();
	F0.clear();
	F1.clear();
	F2.clear();
	task_list.clear();

	_CrtDumpMemoryLeaks();
	return 0;
}

string get_time() {
	SYSTEMTIME st;
	GetSystemTime(&st);

	return ((to_string(st.wHour + 3) + ":" + to_string(st.wMinute) + ":" + to_string(st.wSecond) + ":" + to_string(st.wMilliseconds)));
}