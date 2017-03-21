
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
public:
  int legs;
  int age;
  void * data;
  Insider thing;
  Cat() : legs( 4 ), age( 0 ) {
    std::cout << "ctor0: " << __FUNCTION__ << std::endl;
    data = malloc( 1000 );
  }

  Cat( int legs, int age ) :legs( legs ), age( age ), data( nullptr ) {
    std::cout << "ctor2: " << __FUNCTION__ << std::endl;
    legs = 0;
  }

  Cat( int age ) :legs( 4 ), age( age ), data( nullptr ) {
    std::cout << "ctor2: " << __FUNCTION__ << std::endl;
    legs = 0;
  }

  ~Cat() {
    if ( data != nullptr )
      free( data );
    std::cout << "dtor: " << __FUNCTION__ << std::endl;
  };

public:
  int m1;
protected:
  int m2;
private:
  int m3;
public:
  void setM3( int m3_ ) {
    m3 = m3_;
    if ( m3_ == 0 )
      m2 = -1500;
  }
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
  FlyingCat pimpo{ };
  return 0;
}

