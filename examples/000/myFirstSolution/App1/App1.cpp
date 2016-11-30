// App1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "myFunc.h"

#include <string>
#include <iostream>

int main() {
	using namespace std::string_literals;
	std::cout << myFunc() << "\n"s;
	return 0;
}
