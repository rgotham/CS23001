#include <iostream>
#include <cassert>
#include "string.hpp"


int main(){

  {
    String str("fullmetal");
    assert(str.substr(0, 9) == "fullmetal");
    assert(str.substr(3, 7)  == "lmeta");
  }

  std::cout << "Substring testing completed" << '\n';
}
