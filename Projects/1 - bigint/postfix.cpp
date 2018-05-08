/*
Reads infix expressions from file
writes infix/postfix to another file

input file requirements:
  fully parenthesized VALID infix expr
  should have single whitespace between ( ) and opers
  operands must be 1-6 char in length
  operators must be standard arithmetic opers
  only one exper per line separated by ;
  read until eof
cmd interface requirements:
  postfix input [output]
    input file is required
    output file is optional
      if no output file, outputs to screen
 */

#include "utilities.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]){
  if(argc == 1){                // makes sure there is one cli argument
    std::cout << "input file is required" << '\n';
    exit(1);
  }
  std::ifstream in(argv[1]);    // opens input file
  if (!in){
    std::cout << "Cannot open input file " << argv[1] << '\n';
    exit(1);
  }
  if(argc == 3){                // opens output file
    std::ofstream out(argv[2]); // checks output file
    if(!out){
      std::cout << "Cannot open output file " << argv[2] << '\n';
      exit(1);
    }
    String token;
    String infix;
    while(!in.eof()){
      in >> token;
      if(token != ";")          // adds token to expr
	infix += token + " ";
      else{                     // if eo line is reached
	out << infix << '\n';
	String postfix = infixToPostfix(infix);
	out << postfix << '\n';
	infix = "";             // clears out old expr
      }
    }
    out.close();
  }
  in.close();                   
  return 0;
}
