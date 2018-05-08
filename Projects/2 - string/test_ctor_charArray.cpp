#include "string.hpp"

int main(){

  {
    String str("hello");
    assert(str == "hello");
  }
  std::cout << "Char-Array ctor works as intended" << '\n';
}
