#include <iostream>
#include <fstream>
#include <cassert>
#include "string.hpp"

int main(){
  std::ifstream file;
  file.open("data2-1.txt");
  
  String str1, str2, str3, str4, str5;

  file >> str1 >> str2 >> str3 >> str4 >> str5;

  assert(str1 == "This");
  assert(str2 == "twisted");
  assert(str3 == "wretched");
  assert(str4 == "place");
  assert(str5 == "shadowed");

  std::cout << "Extraction operator works as intended" << '\n';
}
