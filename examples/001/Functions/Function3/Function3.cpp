#include "stdafx.h"

auto f1( long arg ) {

//  for ( auto i = 0; i < arg; ++i ) {
//
//
//  }

//  for ( auto i = arg; i != 0; --i ) {
//
//
//  }


  int w = 3;

  decltype( arg ) x;


  auto a = 3;
  decltype( a ) b; // b = 6;
    
  float f = 3.14F;

  // auto s = a + f;
  decltype( a + f )  s;


  

  for ( auto i = 0; i < arg; ++i ) {


  }


  if ( arg < 1 ) {

    return 5 + arg;

  } 

  // return (short int) arg;
  return arg;
}











auto f3( long arg ) -> int {

  return 0;
}

auto f4( long arg ) -> decltype(arg + 5.0F) {

//  sizeof arg;
//  sizeof (long int);

  if ( arg < 0  )  
    return 0;

//  decltype ( arg );
//  decltype (( arg ));

  typedef decltype ( arg ) mojTyp;
  mojTyp v1 = 3;

  return arg + 5.0F;

}





int main() {
  auto x1 = f1( 3 );

  return 0;
}

