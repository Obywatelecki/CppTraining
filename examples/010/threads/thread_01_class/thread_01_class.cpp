
#include "stdafx.h"
#include <iostream>

class MyTask {
	int arg;
public:
	MyTask(int arg);
	~MyTask();
	void operator() ();
};

MyTask::MyTask(int arg) : arg(arg) {};
MyTask ::~MyTask() {
	std::cout << "Sajonara: " << arg << std::endl;
};
void MyTask ::operator() (void) {
	std::cout << "BlahBlah: " << arg << std::endl;
};

int main()
{
	MyTask aTask(1500'100'900);
	aTask();
	return 0;
}
