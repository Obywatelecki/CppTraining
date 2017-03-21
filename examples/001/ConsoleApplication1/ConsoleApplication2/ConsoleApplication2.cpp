
#include "stdafx.h"
#include <iostream>

#include <limits>
#include <assert.h>
#include <windows.h>



void readIn( int * data, int N ) {
  for ( int i = 0; i < N; i++ ) {
    std::cin >> data[ i ];
  }
}

void posortuj (int * array, int N) { 

}

void writeOut( int * data, int N ) {
  for ( int i = 0; i < N; i++ ) {
    std::cout << data[ i ] << "\n";
  }

}


int main()
{  

  const int N = 4;
  int data[ N ];

  readIn( data, N );
  posortuj( data, N );
  writeOut( data, N );
  
  return 0;
}

