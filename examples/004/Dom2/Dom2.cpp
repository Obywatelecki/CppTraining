#include "stdafx.h" 
#include <stdlib.h>
#include <assert.h>
#include <limits>
#include <iostream>

void clrArrayInt( int *arr, size_t N ) {
  for ( size_t i = 0; i < N; ++i ) {
    arr[ i ] = 0;
  }
}

int main() {
 
  const int N = 5;

  int arr1[ N ];
  arr1[ 0 ] = 10;
  arr1[ 1 ] = 11;
  arr1[ 2 ] = 12;
  arr1[ 3 ] = 13;
  arr1[ 4 ] = 14;

  int *arr2 = (int *) malloc( N * sizeof( *arr2 ) );
  *arr2 = 20;
  *( arr2 + 1 ) = 21;
  *( arr2 + 2 ) = 22;
  *( arr2 + 3 ) = 23;
  *( arr2 + 4 ) = 24;

  clrArrayInt( arr1, sizeof( arr1 ) / sizeof( arr1[ 0 ] ) );
  clrArrayInt( arr2, N );

  assert( arr1[ 0 ] == 0 );
  assert( arr1[ 4 ] == 0 );

  assert( arr2[ 0 ] == 0 );
  assert( arr2[ 4 ] == 0 );

  free( arr2 );
  arr2 = nullptr;
  assert( arr2[ 4 ] == 0 );

  return 0;
}