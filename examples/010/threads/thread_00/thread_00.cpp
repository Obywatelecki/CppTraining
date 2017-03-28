
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>

void myTask(const int arg) {
	std::cout << "ThreadID: " << std::this_thread::get_id() << " arg: " << arg << std::endl;

}


int main()
{
	const int N = 32;
	std::cout << "Hardware threads: " << std::thread::hardware_concurrency() << std::endl;
	std::vector<std::thread> runners;
	std::cout << "Let's go!" << std::endl;
	for (int i = 0; i < N; ++i) {
		runners.push_back(std::thread(myTask, i));
	}

	for (auto& it:runners) {
		it.join();

	};

	return 0;
}

