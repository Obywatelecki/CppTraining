#include "stdafx.h"

#include <vector>
#include <iostream>


void size2( int *arr ) {

  size_t s = sizeof( arr ) / sizeof( arr[ 0 ] );



}

int main( int argc, char *argv[ ] )

{

#if 0
//  char * arg0 = argv[ 0 ];
//  char * arg1 = argv[ 1 ];
//  char * arg2 = argv[ 2 ];
//  char * arg3 = argv[ 3 ];

  std::vector<int> v;

  std::cout << v.size() << std::endl;



  v.push_back( 11 );
  v.push_back( 12 );
  v.push_back( 13 );
  std::cout << v.size() << std::endl;

  v.erase( v.begin() + 1, v.end() );
  std::cout << v.size() << std::endl;

//  v[ 13 ] = 1500;
//  std::cout << v.size() << std::endl;

#endif

//  int t[ 10 ];
//  t[ 13 ] = 1500;

#if  0
  char *a0 = "ala ma asa i kota tez";
  int q1 = 11;
  char a1[ 20 ];
  int q2 = 12;
  char *dest = a1;

  for ( char *sou = a0; *sou != '\0'; ++sou ) {
    std::cout << "____" << *sou << std::endl;
    *dest = *sou;
    ++dest;    
  }

  
#endif

#if 0 
 int arr[ 10][ 3 ];


  std::vector<int> sou;
  std::vector<int> dest;

  auto& cel = dest.begin();

  for ( auto& it = sou.begin(); it != sou.end(); ++it, ++cel ) {
    *cel = *it;
  }

#endif


#if 0 
  std::cout << sizeof( int * ) << std::endl;
  std::cout << sizeof( long int * ) << std::endl;
  std::cout << sizeof( float * ) << std::endl;
  std::cout << sizeof( void * ) << std::endl;
  std::cout << sizeof( int ) << std::endl;



  int *napis = (int *)malloc( 1000  * sizeof(napis[0]) );

//  int q = sizeof( napis[ 0 ] );
//  int q1 = sizeof( *napis );

  napis[ 999 ] = 'a';

  free( napis );

#endif
#if 0

  int qq[ 1200 ];
  size_t s = sizeof( qq ) / sizeof( qq[ 0 ] );
  size2( qq );
#endif



  return 0;
}

 