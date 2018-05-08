#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){
  
  {
    String str("findingcharacters");
    assert(str.findch(0, 'f') == 0);
    assert(str.findch(3, 'd') == 3);
    assert(str.findch(6, 'g') == 6);
    assert(str.findch(9, 'a') == 9);
    assert(str.findch(12,'c') == 12);
    assert(str.findch(15,'r') == 15);
  }
  std::cout << "Findchar does find characters" << '\n';
}
