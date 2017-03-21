
#include "stdafx.h"

#include <string>
#include <iostream>

std::string f1( const std::string s ) {
  return "G³upia " +s;
}

int main() {
  std::string s = "Ala ma Asa";

  std::string s1 = f1( s );

  return 0;
}

