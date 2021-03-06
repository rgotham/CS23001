#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){
  {
    String str1("ab");
    String str2("bc");

    String result = str1 + str2;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << result << std::endl;
    assert(str1 == "ab");
    assert(str2 == "bc");

    assert(result == "abbc");
  }
  {
    String str1("Why won't you work?");
    String str2(" Hey, it works now.");

    String result = str1 + str2;

    std::cout << str1 << '\n';
    assert(str1 == "Why won't you work?");
    std::cout << str2 << '\n';
    assert(str2 == " Hey, it works now.");
    std::cout << result << '\n';
    assert(result == "Why won't you work? Hey, it works now.");
  }

  {
    String str1("abcde");
    String str2("edcba");
    
    str1 += str2;
    
    assert(str1 ==  "abcdeedcba");
    std::cout << str1 << '\n';
  }

  std::cout << "Concatenation test passed" << '\n';
}


