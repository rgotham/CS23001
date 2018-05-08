#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){

  {
    String str("abcdefg");
    assert(str.findstr(0, "ab")  == 0);
    assert(str.findstr(1, "cde") == 2);
  }

  std::cout << "Finding string test completed" << '\n';
}
