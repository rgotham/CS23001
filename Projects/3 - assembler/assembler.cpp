#include "utilities.hpp"
int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Input file not found!" << std::endl;
    return 0;
  }

  std::ifstream in(argv[1]);

  if (!in) {
    std::cerr << "Infix file not found!" << std::endl;
    return 0;
  }

  if (argc == 2){
    String token;
    String infix;
    while(!in.eof()){
      in >> token;
      if((token != ";") && (token != ";\r") && (token != ";\n") && (token != ";\r\n")){
        infix += token + " ";
      }

      else{
	std::cout << "Infix expression: "    << infix   << std::endl;
        String postfix = toPostfix(infix);
	std::cout << "Postfix expression: "  << postfix << std::endl;
	toAssembly(postfix);
        infix = "";
      }
    }
  }

  if(argc == 3){
    std::ofstream out(argv[2]);
    String token;
    String infix;
    while(!in.eof()){
      in >> token;
      if((token != ";") && (token != ";\r") && (token != ";\n") && (token != ";\r\n")){
        infix += token + " ";
      }
      else{
        out << "Infix expression: "    << infix    << "\n";
        String postfix = toPostfix(infix);
        out << "Postfix expression: "  <<  postfix << "\n";
        toAssembly(postfix);
	infix = "";
      }
    }
    out.close();
  }


  in.close();

  return 0;
}


