#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){

  {
    String str1 = "hello";
    std::cout << str1[0] << '\n';
    assert(str1[0] == 'h');
    std::cout << str1[1] << '\n';
    assert(str1[1] == 'e');
    std::cout << str1[2] << '\n';
    assert(str1[2] == 'l');
    std::cout << str1[3] << '\n';
    assert(str1[3] == 'l');
  }

  {
    String str1("holy cow");
    assert(str1[0] == 'h');
    assert(str1[1] == 'o');
    assert(str1[2] == 'l');
    assert(str1[3] == 'y');
    assert(str1[4] == ' ');
    assert(str1[5] == 'c');
    assert(str1[6] == 'o');
    assert(str1[7] == 'w');
    assert(str1[8] == '\0');
  }

  std::cout << "Subscript operator also works" << '\n';
}
