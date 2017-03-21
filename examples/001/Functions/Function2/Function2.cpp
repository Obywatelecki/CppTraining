
#include "stdafx.h"

#include <iostream>

#include <varargs.h>

int f1( int /* arg  */ ) {
  return 0;
}

int f2( int lhs, int rhs = 7 ) {
  std::cout << lhs << " " << rhs << std::endl;
  return 0;
}

int f3( int lhs, int rhs = 7, int q = 4, int v = 6 ) {
  std::cout << lhs << " " << rhs << " " << q << " " << v << std::endl;
  return 0;
}

void f4( int lhs, int rhs, ... ) {
  std::cout << lhs << " " << rhs << std::endl;
}

void f5(  ) {
  printf( "Argumenty: %d %f cos %s jeszcze %c ", 1, 3.13, "ala", '_' );
}


int main() {
//  f1( -5 );

//  f2( 1, 2 );
//  f2( 1 );

//  f3( 1, 3, 5, 11 );
//  f3( 1, 3, 5 );
//  f3( 1, 3 );
//  f3( 1 );

//  // f4( 1 );
//  f4( 1, 2 );
//  f4( 1, 2, 4, "ala", 6.0 );


  return 0;
}
