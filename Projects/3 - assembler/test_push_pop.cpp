#include "string.hpp"
#include "stack.hpp"

int main() {

  {
    stack<int> intStack;
    
    intStack.push(2334);
    int num = intStack.pop();
    
    assert(num == 2334);
    assert(intStack.empty());
  }
  {
    stack<double> doubStack;
    
    doubStack.push(23.34);
    double num = doubStack.pop();

    assert(num == 23.34);
    assert(doubStack.empty());
  }
  {
    stack<String> strStack;
    
    strStack.push("abc");
    String str = strStack.pop();

    assert(str == "abc");
    assert(strStack.empty());
  }
  std::cout << "Done testing pop() and push()" << std::endl;
}
