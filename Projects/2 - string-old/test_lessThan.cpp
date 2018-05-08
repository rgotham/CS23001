#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){

  {
    String str1("hi");
    String str2("high");
    std::cout << str1 << '\n';
    std::cout << str2 << '\n';
    assert(str1 < str2);
  }

  {
    String str1("hotdogs from costco");
    String str2("hotdogs from wallmart");
    std::cout << str1 << '\n';
    std::cout << str2 << '\n';
    assert(str1 < str2);
  }

  {
    String str1("h");
    String str2("i");
    assert(str1 <= str2);
  }

  std::cout << "The less-than operator works" << '\n';
}
