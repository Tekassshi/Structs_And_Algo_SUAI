#pragma once
#include "Task.h"
#include <chrono>
#include <string>

bool getRandom();

class TaskManager {

public:
	static Task generateTask();
	static Task createTask();
	static void show(Task task);
};