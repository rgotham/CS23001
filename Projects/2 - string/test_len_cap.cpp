#include <cassert>
#include <iostream>
#include "string.hpp"

int main(){

  {
    String str1("hello");
    assert(str1.length() == 5);
  }

  {
    String str1;
    assert(str1.length() == 0);
  }

  {
    String str1("jingleheimerschmidt");
    assert(str1.length() == 19);
  }
  std::cout << "Length test passed" << '\n';
}
