
#include "stdafx.h"
#include <iostream>
#include <string>

class Cat {
public:
  std::string name;
  Cat() : name( "" ) {                                       //  constructor
    std::cout << "ctor0: " << __FUNCTION__ << std::endl;
  }

  Cat( const Cat & arg ) {                                // copy constructor
    this->name = arg.name;
    std::cout << "ctor0 &: " << __FUNCTION__ << std::endl;
  }

 Cat operator = ( const Cat & arg ) = delete;

  virtual  ~Cat() {
    std::cout << "dtor: " << __FUNCTION__ << std::endl;
  };
};

int main() {

  ///////////////////////////////

  Cat pimpo1;
  pimpo1.name = "Pimput";

  Cat pimpo2 = pimpo1;

  Cat pimpo3;
//  pimpo3 = pimpo1;  // error

  return 0;
}

