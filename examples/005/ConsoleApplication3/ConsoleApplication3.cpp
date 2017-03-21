
#include "stdafx.h"
#include <iostream>

class sumator {
public:
  sumator() : v( 0 ) { };
  sumator( int initValue ) : v( initValue ) { };

  int operator () ( int arg ) { int retVal = arg + v;  v = arg; return retVal; };

private:
  int v;

};

int main() {

  sumator s( 11 );


  std::cout << s(1500) << std::endl;
  std::cout << s( 2000 ) << std::endl;

  return 0;
}

