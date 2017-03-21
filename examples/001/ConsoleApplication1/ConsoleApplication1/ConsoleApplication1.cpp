
#include "stdafx.h"
#include <iostream>

#include <vector>
#include <algorithm>

void readIn( std::vector<int>& data) {
  for ( auto& it : data ) {
    std::cin >> it;
  }
}

void posortuj( std::vector<int>& data ) {
  std::sort( data.begin(), data.end() );
}

void writeOut( const std::vector<int>& data ) {
  std::cout << "__________\n";
  for ( const auto& it : data ) {
    std::cout << it << "\n";
  }
}

int main() {

  const int N = 4;
  std::vector<int> data;
  data.resize( N );

  readIn( data );
  posortuj( data );
  writeOut( data );

  return 0;
}

