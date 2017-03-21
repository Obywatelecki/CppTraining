
#include "stdafx.h"
#include<iostream>

template <typename T, typename S>
auto mult3( T lhs, S rhs ) -> decltype( lhs * rhs ) {
  std::cout << __FUNCTION__ << std::endl;

  std::cout << "lhs: " << typeid( lhs ).name() << std::endl;
  std::cout << "rhs: " << typeid( rhs ).name() << std::endl;

  return lhs * ( rhs + 1 );
}


int main() {
  mult3( 1, 5. );
  return 0;
}
