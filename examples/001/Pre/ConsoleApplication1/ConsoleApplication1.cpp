
#include "stdafx.h"
#include "lib1.h"

#include <string>

#define ABC_DE 1000 

const int abc_de = 1000;

#define S1 "ala ma " \
" asa"               \
" i kota"

const std::string s1 = "ala ma "
" asa"
" i kota";


#define FF( x ) f0( x + 1 )

inline void ff( int x ) {
  f0( x + 1 );
}

#define myInt int 
typedef int myint0;

int f1_ala_ma_asa( void ) {

  std::cout << __FUNCTION__;

  f0(ABC_DE);

  FF( 9 );

  ff( 9 );
  return 1;
}

// #define MULT(a,b) (a) * (b)
// 
// aa = MULT( 10 + 1 , 11 +1 )
// 
// 10 + 1 * 11 + 1

int main()
{
  //int x = 11;
  f1_ala_ma_asa();
    return 0;
}

