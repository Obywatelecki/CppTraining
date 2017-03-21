
#include "stdafx.h"

#include <string>
#include <iostream>

void fun1( std::string s ) {
  std::cout << __FUNCTION__ << " s: " << s << std::endl;
  s = "What?";
  std::cout << __FUNCTION__ << " s: " << s << std::endl;
}

void fun2( std::string *s ) {
  *s = "What?";
}

void fun3( long * arg ) {
  *arg = 13;
}

int main() {

//  std::string s = "Ala ma Asa";
//  std::cout << __FUNCTION__ << " s: " << s << std::endl;
//  fun1( s );
//  std::cout << __FUNCTION__ << " s: " << s << std::endl;

//  std::string s2 = "Ala ma Asa";
//  std::string s3 = "COs innego";
//  std::cout << __FUNCTION__ << " s2: " << s2 << std::endl;
//  std::cout << __FUNCTION__ << " s3: " << s3 << std::endl;
//  fun2( & s2 );

//  fun2( & s3 );  // s3 = "What"
//
//  std::cout << __FUNCTION__ << " s2: " << s2 << std::endl;
//  std::cout << __FUNCTION__ << " s3: " << s3 << std::endl;

  long q = 0;
  fun3( &q );

  q = 9;
  long v = 1500;

  long *ref;

  ref = &q;
  *ref = 13;

  ref = &v;
  *ref = 13;

  return 0;
}

