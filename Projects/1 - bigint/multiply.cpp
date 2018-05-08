
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main(){
  std::ifstream in("data1-2.txt");
  if(!in){
    std::cerr << "Cannot open data file, exiting." << std::endl;
    exit(1);
  }

  bigint bigint1, bigint2, result;

  in >> bigint1;
  in >> bigint2;

  while(!in.eof()){
    std::cout << "Bigint one = " << bigint1 << '\n';
    std::cout << "Bigint two = " << bigint2 << '\n';
    
    result = bigint1 * bigint2;

    std::cout << "bigint one * bigint two = " << result << '\n';

    in >> bigint1;
    in >> bigint2;
  }

  in.close();
  return 0;
}
