
#include "stdafx.h"
#include <iostream>


class Cat {
public:
  int legs;
  int age;

  Cat() : legs( 4 ), age( 0 ) {
    std::cout << "ctor0: " << __FUNCTION__ << std::endl;
  }

  virtual  ~Cat() {
    std::cout << "dtor: " << __FUNCTION__ << std::endl;
  };

  virtual void meow( void ) {
    std::cout << "Meow!   " << __FUNCTION__ << std::endl;
  }

};

class FlyingCat : public Cat {
public:
  int nWings;
  FlyingCat() : nWings( 0 ) {
    std::cout << "ctor: " << __FUNCTION__ << std::endl;
  }
  ~FlyingCat() override {
    std::cout << "dtor: " << __FUNCTION__ << std::endl;
  }

  void meow( void ) override {
    std::cout << "Roar!!!!    " << __FUNCTION__ << std::endl;
  }

};

int main() {

///////////////////////////////

  bool homeCat = false;//  true;

  Cat *pimpo = homeCat ? new Cat() : new FlyingCat();
  pimpo->meow();
  delete pimpo;

  return 0;
}

