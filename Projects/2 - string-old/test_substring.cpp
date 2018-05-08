#include <iostream>
#include <cassert>
#include "string.hpp"


int main(){

  {
    String str("fullmetal");
    assert(str.substring(0, 9) == "fullmetal");
    assert(str.substring(3, 7)  == "lmeta");
  }

  std::cout << "Substring testing completed" << '\n';
}
