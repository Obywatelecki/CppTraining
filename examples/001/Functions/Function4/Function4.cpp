#include "stdafx.h"

#include<iostream>

// int inc( int arg ) {
// 
//   std::cout << __FUNCTION__ << std::endl;
//   return arg + 1;
// }
// 
// long int inc( long int arg ) {
//   std::cout << __FUNCTION__ << std::endl;
//   return arg + 1;
// }


template <typename T>
T inc( T arg ) {
  std::cout << __FUNCTION__ << std::endl;
  return arg + 1;
}


template <typename T>
T mult( T lhs, T rhs ) {
  std::cout << __FUNCTION__ << std::endl;
  return lhs * ( rhs + 1 );
}


template <typename T, typename S>
T mult2( T lhs, S rhs ) {
  std::cout << __FUNCTION__ << std::endl;
  return static_cast<T>(lhs * ( rhs + 1 ));
}


// template <class T, class S>
template <typename T, typename S>
auto mult3( T lhs, S rhs ) -> decltype( lhs * ( rhs + 1 ) ) {
  std::cout << __FUNCTION__ << std::endl;
  return lhs * ( rhs + 1 );
}

template <typename T, int N>
int mult4( T arg )  {
  std::cout << __FUNCTION__ << std::endl;
  return arg * N;
}




int main() {
  // int i1 = inc( 1 );

//  inc( 2 );
//  inc( 2.0F );
//  inc( 2.0 );
//  long int x1 = inc( 1L );

  mult( 2, 3 ); // int
  mult( 2.0, 3.0 ); // double
  // mult( 2, 3.0 ); // nie ma takiego wo³ania

  mult2( 2, 3.0 ); // int, double -> int
  auto x3 = mult3( 2, 3.0 ); // int, double -> double

  auto x3a = mult3<float,float>( 2, 3.0 ); // float, float -> float

  auto x4 = mult4<float, 5>( 3 );

  return 0;
}

