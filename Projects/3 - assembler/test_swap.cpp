#include "string.hpp"
#include "stack.hpp"

int main() {
  {
    stack<int> rhs, lhs;
    
    rhs.push(3);
    lhs.push(2);
    
    rhs.swap(lhs);

    assert(rhs.pop() == 2);
    assert(lhs.pop() == 3);
  }

  {
    stack<double> rhs, lhs;

    rhs.push(3.0);
    lhs.push(2.0);
    
    lhs.swap(rhs);

    assert(rhs.pop() == 2.0);
    assert(lhs.pop() == 3.0);
  }

  {
    stack<bool> rhs, lhs;

    rhs.push(true);
    rhs.push(false);
    lhs.push(false);
    lhs.push(true);
    
    lhs.swap(rhs);

    assert(lhs.pop() == false);
    assert(lhs.pop() == true);
    assert(rhs.pop() == true);
    assert(rhs.pop() == false);
  }

  {
    stack<String> rhs, lhs;

    rhs.push("cat");
    rhs.push("dog");
    lhs.push("fish");
    lhs.push("shark");

    rhs.swap(lhs);
    
    assert(rhs.pop() == "shark");
    assert(rhs.pop() == "fish");
    assert(lhs.pop() == "dog");
    assert(lhs.pop() == "cat");

  }

  std::cout << "Done testing swap" << std::endl;
}
