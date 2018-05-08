#include "utilities.hpp"
#include "string.hpp"

String infixToPostfix(String infix){
  std::vector<String> strToken = infix.split(' ');
  Stack<String> temp;

  size_t limit = strToken.size() - 1;
  if(infix.findchar(0, ';') == -1)
    limit = strToken.size();

  for(size_t i = 0; i < limit; i++){
    String token = strToken[i];
    if(token != ")"){
      if(token != "(")
	temp.push(token);
    }
    else{
      String right = temp.pop();
      String oper  = temp.pop();
      String left  = temp.pop();
      String result= left + " " + right + " " + oper;
      temp.push(result);
    } 
  }
  return temp.pop();
  
}
