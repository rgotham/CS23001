
#include "utilities.hpp"
int main(){

  {
    String top = toPostfix("( AX + ( B * C ) ) ;");
    std::cout << top << std::endl;
  }

}
