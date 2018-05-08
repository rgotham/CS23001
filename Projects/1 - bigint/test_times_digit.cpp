// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {

    {
      bigint bi(9999);
      
      bi = bi.times_digit(9);

      assert(bi == 89991);
    }
    
    {
      bigint bi("1000000000000000");

      bi = bi.times_digit(3);

      assert(bi == "3000000000000000");
    }

    {
      bigint bi("12345678987654321");

      bi = bi.times_digit(4);

      assert(bi == "49382715950617284");
    }

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;

}
