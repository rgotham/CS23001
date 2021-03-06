#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){
  {
    String str1("abcd");
    String str2("abcd");
    std::cout << str1 << str2 << std::endl;
    assert(str1 == str2);
  }

  {
    String str1("cereal");
    String str2("cereal");
    
    assert(str1 == str2);
  }

  {
    String str1, str2("not equal");
    assert(!(str1 == str2));
  }

  {
    String str1, str2("also not equal");
    assert(str1 != str2);
  }

  std::cout << "Equality operator works as intended" << '\n';
}
