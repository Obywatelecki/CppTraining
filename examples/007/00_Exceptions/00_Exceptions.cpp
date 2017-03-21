#include "stdafx.h"

// Throw by value, catch by const reference

#include <iostream>

int fub()
{
	try {
		int x = 10;
		int y = 0;

		if (y == 0)
			throw (19);
		std::cout << "Before exception\n";

	}
	catch (const std::overflow_error&) {
		std::cout << "In exception1\n";
	}
	catch (const std::exception&) {
		std::cout << "In exception2\n";
	}
	catch (char *) {
		std::cout << "In exception3\n";
	}
	catch (const int & e) {
		std::cout << "In exception4 " << e << "\n";
		throw (e);
	}

	//	catch (...) {
	//		std::cout << "In exception ALL\n";
	//	}

	std::cout << "After exception\n";

	return 0;
}

int main() {
	try {
		fub();
	}
	catch (const int & e) {
		std::cout << "In main exception4 " << e << "\n";
	}
	return 0;
}

