#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <memory>

bool copy_file(const std::string plik1, const std::string plik2) {
	auto const n = 100;
	//	auto buf = new char[n];
	std::unique_ptr <char[]> buf(new char[n]); // unique_ptr sam siê niszczy!
	std::ifstream src;
	src.exceptions(std::ifstream::badbit);
	std::ofstream dst;
	dst.exceptions(std::ofstream::badbit);
	try {
		src.open(plik1, std::ios::binary);
		dst.open(plik2, std::ios::binary);
		while (!src.eof()) {
			src.read(buf.get(), n);
			std::streamsize nbytes = src.gcount();
			dst.write(buf.get(), nbytes);
		}
		src.close();
		dst.close();
	}
	catch (...) {
		std::cout << "Nie bangla" << std::endl;
		return false;
	};
	//	delete[] buf;
	std::cout << "Kopiowanie zawartosci pliku zakonczone" << std::endl;
	return true;
};

int main()
{
	copy_file("T:\\sou.txt", "T:\\dst.txt");

	//	std::ofstream o("C:\\Users\\Ada\\Desktop\\Hello.txt");
	//
	//	o << "Hello, World\n" << std::endl;



	return 0;
}