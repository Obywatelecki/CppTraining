
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {


  int x = 8;

  auto myLambda = [=]( int arg ) ->int { return arg + x; };

  x = 1000;
  int y = myLambda( 10 );  

  int z = [ ]( int arg ) ->int { return arg * 2; }(100);

  std::cout << y << std::endl;
  std::cout << x << std::endl;

  std::vector<int> v = { 1,3,5,20 };

  std::for_each( 
    v.begin(), 
    v.end(), 
    [ ]( int arg ) { std::cout << arg << std::endl; } );  

  return 0;
}

