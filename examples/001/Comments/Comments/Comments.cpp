#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std::string_literals;

void f1() {
  auto i = 0; // <- Ignored from this point
  auto        // j = 1; <- It is a comment, too
       j = 2; // previous line of code "auto" is continued
  std::cout << __func__ << ":\n"s 
    << "\ti: "s << i << "\n"s 
    << "\tj: "s << j << "\n"s;
}

void f2() {
  auto i =     /* 0; Everything form this point is ignored
  auto j = 0; // j = 9; Whole line is a comment
              /* This is not the beginning of a comment
       j = 1; // Whole line is a comment
                 Comment ends -> */ 2;
  auto z = /* 11 */ 9; // 11 was commented out
  std::cout << __func__ << ":\n"s
    << "\ti: "s << i << "\n"s
    << "\tz: "s << z << "\n"s;
}

void f3() {
  auto i = 0;
  #if 0
    Pseudo - comment:
    whole block ```#if 0``` ```#endif``` is ignored
    i = 2;
  #endif
  auto z = 9;
  std::cout << __func__ << ":\n"s
    << "\ti: "s << i << "\n"s
    << "\tz: "s << z << "\n"s;
}

int main() {
  f1();
  f2();
  f3();
  std::cout << "press <ENTER>"s;
  std::cin.get();
  return 0;
}
