#include "utilities.hpp"

void toPostfix(std::ifstream& in, std::ofstream& out){

  stack<String> result;
  String left, right, oper, currToken;
  
  while(!in.eof()){
    in >> currToken;
    
    while(currToken != ";"){
      if(currToken == ")"){
	right = result.pop();
	oper = result.pop();
	left = result.pop();
	result.push(left + right + oper);
      }else if(currToken != "(")
	result.push(currToken);
      in >> currToken;
    }
    out << result.pop() << std::endl;
  }
}
