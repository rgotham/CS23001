#include "string.hpp"
#include "stack.hpp"

int main() {
  {    
    stack<int> intStack;
    intStack.push(1);
    intStack.push(25667);
    intStack.push(3);

    stack<int> result = intStack;

    int third = result.pop();
    int second = result.pop();
    int first = result.pop();

    assert(third == 3);
    assert(second == 25667);
    assert(first == 1);
    assert(result.empty());
    assert(intStack.empty() == false);
  }

  {
    stack<bool> boolStack;
    boolStack.push(true);
    boolStack.push(false);
    boolStack.push(true);

    stack<bool> result = boolStack;

    bool third = result.pop();
    bool second = result.pop();
    bool first = result.pop();

    assert(third == true);
    assert(second == false);
    assert(first == true);
    assert(result.empty());
    assert(boolStack.empty() == false);
  }

  {
    stack<double> doubStack;
    doubStack.push(1.0);
    doubStack.push(256.67);
    doubStack.push(3.0);

    stack<double> result = doubStack;

    double third = result.pop();
    double second = result.pop();
    double first = result.pop();

    assert(third == 3.0);
    assert(second == 256.67);
    assert(first == 1.0);
    assert(result.empty());
    assert(doubStack.empty() == false);
  }
  {
    stack<String> strStack;
    strStack.push("abc");
    strStack.push("def");
    strStack.push("ghi");

    stack<String> result = strStack;

    String third = result.pop();
    String second = result.pop();
    String first = result.pop();

    assert(third == "ghi");
    assert(second == "def");
    assert(first == "abc");
    assert(result.empty());
    assert(strStack.empty() == false);
  }

  std::cout << "Done testing assignemnt" << std::endl;
}
