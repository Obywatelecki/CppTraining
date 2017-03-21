#include "stdafx.h"

#include <iostream>


int fun7( int arg ) {
  std::cout << __FUNCTION__ << " " << arg << "\n";
  return arg + 7;
}

int fun5( int arg ) {
  std::cout << __FUNCTION__ << " " << arg << "\n";
  return arg + 5;
}

int main() {

//int fun7  (int) { ... }

  int (*ref)(int) = &fun5;  // auto jest ok

  int a = ( *ref )( 11 );
  std::cout << "Result: " << a << std::endl;

  ref = &fun7;
  a = ( *ref )( 11 );
  std::cout << "Result: " << a << std::endl;

}
