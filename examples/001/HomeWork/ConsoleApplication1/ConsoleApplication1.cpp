
#include "stdafx.h"

#include <iostream>

#include "Lib1.h"
#include "Lib2.h" 

#if defined _MSC_VER

#elif defined __GNUC__
#error "GCC sucks"
#else 
#error
#endif


int main() {
  std::cout << __FUNCTION__ << std::endl;
  moje::sth = 1;
  std::cout << moje::mult( 2.F, 3.F );
  moje::any();
  return 0;
}
