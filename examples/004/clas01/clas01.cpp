
#include "stdafx.h"
#include <iostream>

class C1 {  // takie tam, na marginesie
  C1( int yyyy ) { };
};

class Cat {
public:
  int legs;
  int age;
  void * data;
  Cat() : legs( 4 ), age( 0 ) {
    std::cout << "ctor0: " << __FUNCTION__ << std::endl;
    data = malloc( 1000 );
  }

  Cat( int legs, int age ) :legs( legs ), age( age ), data(nullptr) {
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
};

int main() {

//  C1 c;
  Cat duszek;
  Cat duszek1{ };

  {
    Cat pimpo{ 13 };
  }

//  std::cout << "Legs: " << duszek.legs << std::endl;

//  duszek.legs = 4;

  return 0;
}

