// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(2468135);

        // Test 
        int digit = bi[4];

        // Verify
        assert(bi    == 2468135); 
        assert(digit == 6);
    }
    
    {
      bigint bi(13579246);

      int digit = bi[1];

      assert(bi    == 13579246);
      assert(digit == 4);
    }
   
    {
      bigint bi(22334455);

      int digit = bi[0];

      assert(bi    == 22334455);
      assert(digit == 5);
    }

    {
      bigint bi("83642971");
      
      int digit = bi[6];

      assert(bi    == "83642971");
      assert(digit == 3);
    }

    std::cout << "Done testing subscript." << std::endl;
}

