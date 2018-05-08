#include "string.hpp"
#include "stack.hpp"

int main() {
  {
    stack<int> intStack;
    assert(intStack.empty());
  }

  {
    stack<double> doubStack;
    assert(doubStack.empty());
  }

  {
    stack<bool> boolStack;
    assert(boolStack.empty());
  }

  {
    stack<String> strStack;
    assert(strStack.empty());
  }

  std::cout << "Done testing default ctor" << std::endl;
}
