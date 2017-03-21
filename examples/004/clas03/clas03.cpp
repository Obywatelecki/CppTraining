
#include "stdafx.h"
#include <iostream>

class Insider {
public:
  Insider() {
    std::cout << "ctor: " << __FUNCTION__ << std::endl;

  };
  ~Insider() {
    std::cout << "dtor: " << __FUNCTION__ << std::endl;

  };
};

class Cat {
  int m1;
public:
  int legs;
  int age;
  void * data;
  Insider thing;
  Cat() : legs( 4 ), age( 0 ), data( nullptr ), m1( 0 ) {
    std::cout << "ctor0: " << __FUNCTION__ << std::endl;
  }

  Cat( int legs, int age = -1 ) :Cat() {
    ( *this ).legs = legs;
    this->age = age;
    std::cout << "ctor2: " << __FUNCTION__ << std::endl;
    data = malloc( 1000 );
  }

  ~Cat() {
    if ( data != nullptr )
      free( data );
    std::cout << "dtor: " << __FUNCTION__ << std::endl;
  };
};

class FlyingCat : public Cat {
public:
  int nWings;
  FlyingCat() : nWings( 0 ) {
    std::cout << "ctor: " << __FUNCTION__ << std::endl;
  }
  ~FlyingCat() {
    std::cout << "dtor: " << __FUNCTION__ << std::endl;
  }
};

int main() {
  Cat pimpo{ 4 };
  return 0;
}

