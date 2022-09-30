#pragma once
#include <iostream>
#include <windows.h>
#include "TaskManager.h"

class Processor {
	Task task;
	bool isProcessing = false;

public:
	bool isEmpty() {
		return (isProcessing == 0 ? true : false);
	}

	void show() {
		if (isProcessing) {
			TaskManager::show(task);
		}
		else
			cout << "Процессор свободен.\n";
	}

	Task getTask() {
		return task;
	}

	void setTask(Task obj) {
		SYSTEMTIME st;
		GetSystemTime(&st);

		obj.arrival_time = (to_string(st.wHour + 3) + ":" + to_string(st.wMinute) + 
			":" + to_string(st.wSecond) + ":" + to_string(st.wMilliseconds));

		task = obj;
		isProcessing = true;
	}

	void process() {
		if (task.execution_time > 0) {
			task.execution_time -= 1;

			if (task.execution_time == 0)
				isProcessing = false;
		}
		else {
			isProcessing = false;
			task.priority = 1000;
		}
	}
};