
#include "stdafx.h"
#include <iostream>

class Figure {
public:
  float a;
  float b;
  Figure( float a, float b ) : a( a ), b( b ) { std::cout << __FUNCTION__ << " 2" <<std::endl; };
  Figure() : a( 0. ), b( 0. ) {
    std::cout << __FUNCTION__ << std::endl;
  };
};

class Rect : public Figure {
public:
//  Rect( float a, float b ) : Figure( a, b ) { 
//    std::cout << __FUNCTION__ << std::endl;
//  };

  Rect( float a, float b ) : Figure(a,b) {
    std::cout << __FUNCTION__ << std::endl;

//  this->a = a;
//    this->b = b;
  }



};


int main() {
  Rect r{ 10.,20. };
  return 0;
}

jacek.banaszczyk@gmail.com