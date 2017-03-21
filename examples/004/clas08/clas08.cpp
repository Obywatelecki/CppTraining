// clas08.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <typename T>
class Rational {
  
  T up;
  T down;
public:
  Rational() {
    up = 0;
    down = 1;
  }

  
};

template <typename T>
class Sum {
  T data;
public:
  Sum() {
    data = 0;    
  }
  T sum0( void ) {
    return data;
  }
  T sum2( void ) {
    return data + data;
  }
};


int main() {


//  Rational<int> r1;
//  Rational<long int> r2;

  Sum<int> s{ };
  s.sum0();
  s.sum2();

  Sum<int *> s1;
  s1.sum0();
//  s1.sum2(); // error




  return 0;
}

