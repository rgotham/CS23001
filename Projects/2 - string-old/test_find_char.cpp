#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){
  
  {
    String str("findingcharacters");
    assert(str.findchar(0, 'f') == 0);
    assert(str.findchar(3, 'd') == 3);
    assert(str.findchar(6, 'g') == 6);
    assert(str.findchar(9, 'a') == 9);
    assert(str.findchar(12,'c') == 12);
    assert(str.findchar(15,'r') == 15);
  }
  std::cout << "Findchar does find characters" << '\n';
}
