
#include "stdafx.h"
#include <iostream>
#include <string>

class Cat {
public:
  std::string name;
  Cat() : name("") {                                       //  constructor
    std::cout << "ctor0: " << __FUNCTION__ << std::endl;
  }

  Cat( const Cat & arg ) {                                // copy constructor
    name = arg.name;
    std::cout << "ctor0 &: " << __FUNCTION__ << std::endl;
  }

  void operator = ( const Cat & arg ) {                                // assign operator
    std::cout << "ctor0 &: " << __FUNCTION__ << std::endl;
    name = arg.name;
  }

//  Cat( const Cat && arg ) {                                // move constructor C++14
//    this->name = arg.name;
//    std::cout << "ctor0 &: " << __FUNCTION__ << std::endl;
//  }
//
//  Cat operator = ( const Cat && arg ) {                                // move assign operator  C++14
//    std::cout << "ctor0 &: " << __FUNCTION__ << std::endl;
//    Cat retVal;
//    retVal.name = arg.name;
//    return retVal;
//  }

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

  pimpo3 = pimpo1;


  return 0;
}

