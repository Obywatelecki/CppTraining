
#include "stdafx.h"

#include <stdlib.h>
#include <iostream>

// int values[ ] = { 0, 1, 2, 3, -1, -2, -3, 0, -5, 5, 7,-7, 6, -6, 8, -8, -9, 9, 0 };

int values[ ] = { 0, 5, 5  };

int compare( const void * a, const void * b ) {

  auto a0 = *(int*) a;
  auto b0 = *(int*) b;
  auto diff = abs( a0 - 3 ) - abs( b0 - 3 );

  if ( diff < 0 )
    return -1;

  if ( diff > 0 )
    return 1;

  return 0;
}

int main() {

  auto len = sizeof( values ) / sizeof( values[ 0 ] );
  qsort( values, len, sizeof( int ), compare );


  for ( decltype( len ) n = 0; n < len; n++ ) std::cout << values[ n ] << " ";
  return 0;
}