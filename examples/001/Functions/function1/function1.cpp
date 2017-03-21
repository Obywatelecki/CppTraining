#include "stdafx.h"

int sth = 3;


void fun1( void ) {

}

int fun2( void ) {

  if ( false ) {
    return 3 + 1 * 2 - 17;
  }

  return (short int) 1;
}

int fun3( int arg ) {

  float sth = 1.0F;

  arg = 9;

  // int sth = 11;

  {
    int q = 8;
    int sth = 6;
  }
  // arg = q;
  return 0;

}

int fun4( int lhs, float rhs ) {
  return 0;
}

int main() {
//  fun1();
//
//  auto x1 = fun2();
//  fun2();

//  int arg = 2;
//  auto x2 = fun3( arg );

  int x4 = fun4( 3 , 3.14F );

  return 0;
}

