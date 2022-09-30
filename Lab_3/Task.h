#pragma once
#include <string>

struct Task {
	int priority = 1000;
	int execution_time;
	std::string arrival_time = "-1";
};