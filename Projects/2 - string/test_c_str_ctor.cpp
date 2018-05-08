#include "string.hpp"
#include <cassert>

int main(){

  {
    String str('a');
    assert(str == 'a');
  }

  std::cout << "Single char ctor works as intended" << '\n';
}
