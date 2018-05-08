// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    {
      bigint left(14);
      bigint right(21);
      bigint result;

      result = left + right;

      assert(left   == 14);
      assert(right  == 21);
      assert(result == 35);
    }
    
    {
      bigint left(35);
      bigint right(66);
      bigint result;
      
      result = left + right;

      assert(left   == 35);
      assert(right  == 66);
      assert(result == 101);
    }
    
    {
      bigint left(101);
      bigint right(202);
      bigint result;

      result = left + right;

      assert(left   == 101);
      assert(right  == 202);
      assert(result == 303);
    }

    {
      bigint left(303);
      bigint right(708);
      bigint result;

      result = left + right;

      assert(left   == 303);
      assert(right  == 708);
      assert(result == 1011);
    }
    
    {
      bigint left(1001);
      bigint right(2002);
      bigint result;

      result = left + right;

      assert(left   == 1001);
      assert(right  == 2002);
      assert(result == 3003);
    }

    {
      bigint left(3003);
      bigint right(7008);
      bigint result;

      result = left + right;

      assert(left   == 3003);
      assert(right  == 7008);
      assert(result == 10011);
    }

    {
      bigint left(10001);
      bigint right(30003);
      bigint result;

      result = left + right;

      assert(left   == 10001);
      assert(right  == 30003);
      assert(result == 40004);
    }
    
    {
      bigint left(40004);
      bigint right(60006);
      bigint result;
      
      result = left + right;

      assert(left   == 40004);
      assert(right  == 60006);
      assert(result == 100010);

    }
    std::cout << "Done with testing addition." << std::endl;
}

