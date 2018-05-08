#include "string.hpp"
#include "stack.hpp"

int main(){
  {
    stack<int> intStack;
    intStack.push(2);
    intStack.push(3669);
    intStack.push(38);

    stack<int> result = intStack;
    
    int third  = result.pop();
    int second = result.pop();
    int first  = result.pop();

    assert(third  == 38);
    assert(second == 3669);
    assert(first  == 2);
    assert(result.empty());
    assert(intStack.empty() == false);
  }

  {
    stack<double> doubStack;
    doubStack.push(2.0);
    doubStack.push(36.69);
    doubStack.push(3.8);
    
    stack<double> result = doubStack;

    double third  = result.pop();
    double second = result.pop();
    double first  = result.pop();

    assert(third  = 3.8);
    assert(second = 36.69);
    assert(first  = 2.0);
    assert(result.empty());
    assert(doubStack.empty() == false);
  }

  {
    stack<bool> boolStack;
    boolStack.push(true);
    boolStack.push(true);
    boolStack.push(false);
    
    stack<bool> result = boolStack;

    bool third  = result.pop();
    bool second = result.pop();
    bool first  = result.pop();

    assert(third  == false);
    assert(second == true);
    assert(first  == true);
    assert(result.empty());
    assert(boolStack.empty() == false);
  }

  {
    stack<String> strStack;
    strStack.push("sound");
    strStack.push("of");
    strStack.push("music");

    stack<String> result = strStack;

    String third  = result.pop();
    String second = result.pop();
    String first  = result.pop();
    
    assert(third  == "music");
    assert(second == "of");
    assert(first  == "sound");
    assert(result.empty());
    assert(strStack.empty() == false);
  }

  std::cout << "Done testing copy ctor" << std::endl;
}
