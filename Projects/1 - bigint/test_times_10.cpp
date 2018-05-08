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
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times_10(0);

        // Verify
        assert(bi == 3);  //Wrong. Will FAIL, fix and add tests cases
    }

    {
      bigint bi(30);

      bi = bi.times_10(2);

      assert(bi == 3000);
    }

    {
      bigint bi(100);
     
      bi = bi.times_10(4);

      assert(bi == "1000000");
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
}

