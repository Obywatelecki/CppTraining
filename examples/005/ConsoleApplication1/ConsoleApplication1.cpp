
#include "stdafx.h"

#include <iostream>
#include <vector>

#include <algorithm>

void f( int x ) {
  std::cout << "________ " << x << "\n";
}

int main() {

//  auto x = 1;
//  auto y = 1;
//
//  if ( ( x == 1 ) && (y == 2) ){
//    x = 10;
//    y = 11;
//  } else if ( y == 1 ) {
//    x = 11;
//  }
//
//  if ( x ) { // x != 0
//    x = 20;
//  }

//____________________________________

//  auto x = 1;
//  auto y = 11;
//
//  switch ( x ) {
//    case 1:{
//      y = -5;
//      std::cout << "b;ahj";
//      break;                  // !!!!!!!!!!!!!!!
//    }
//    // case ( 10 | 11 | 12 ):    // === 13 operator binarny, nie têdy droga !
//    case 10:
//    case 11:
//    case 12: {
//      y = 17;
//      std::cout << "b;ahjasdfasfasdf";
//      // Fall Through
//    }
//    default: {
//      std::cout << "tutaj ";
//      break;
//    }
//  }

//  auto x = 1; // x : 0 - 15;
//  auto y = 2; // y : 0 - 15
//
//  auto test = ( y << 8 | x );
//
//  switch ( y << 8 | x ) {
//    case 0x000: { std::cout << "00"; break;  }
//    case 0x102: { std::cout << "12"; break;  }
//    case 0x201: { std::cout << "21"; break; }
//  }

//  auto y = 10000000000000000000L;
//  
//  // for ( auto x = 0; x < y; ++x ) {           // auto jest tu z³e
//  for ( decltype(y+1) x = 0; x < y+1; ++x ) {
//    std::cout << "x" << std::endl;  
//  }

//  auto y = 10;
//  for ( decltype(y) x = 0; x < y; ++x ) {
//    std::cout << x << std::endl;  
//    if ( x == 5 ) {
//      break;
//    }
//    if ( x == 2 ) {
//      y = 1900;
//      continue;
//      y = 1901;
//    }
//    std::cout << "_______" << std::endl;
//  }

//  std::vector<int> v = { 1,3,5,10 };
//  std::cout << *( v.end() - 1 ); //   :)

//  for ( auto it = v.begin(); it != v.end(); ++it ) {
//    std::cout << *it << "\n";
//  }

//  for ( auto it : v ) {
//    std::cout << it << "\n";
//  }

//  auto y = 10;
//  auto x = 0;
//  do {
//    std::cout << x << "\n";
//
//    if ( x == 2 ) {
//      ++x;
//      continue;
//    }
//    std::cout << "__________\n";
//    ++x;
//  } while ( x < y );

//  auto y = 10;
//  auto x = 0;
//  while ( x < y  ) {
//    std::cout << x << "\n";
//    ++x;
//  }

//  auto y = 10;
//  auto x = 0;
//  while ( true ) {
//    std::cout << x << "\n";
//    ++x;
//  }

//  auto y = 1000;
//  for ( int x = 0; x < 10; ++x, ++y ) {
//
//  }

}

