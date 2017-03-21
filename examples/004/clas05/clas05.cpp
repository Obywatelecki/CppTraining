
#include "stdafx.h"
#include <iostream>


class Cat {
public:
  Cat() {
    std::cout << "ctor0: " << __FUNCTION__ << std::endl;
    meow();
  }

  virtual  ~Cat() {
    std::cout << "dtor: " << __FUNCTION__ << std::endl;
  };

  virtual void meow( void ) {
    std::cout << "Meow!       " << __FUNCTION__ << std::endl;
  }
};

class FlyingCat : public Cat {
public:
  FlyingCat() {
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

