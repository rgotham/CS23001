#include "stack.hpp"
#include "string.hpp"

int main(){

  {
    stack<int> intStack;
  }
  {
    stack<double> doubStack;
  }
  {
    stack<bool> boolStack;
  }
  {
    stack<String> strStack;
  }

  std::cout << "Done testing destructor" << std::endl;
}
