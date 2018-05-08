//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    bigint bigintOne, bigintTwo, bigintResult;

    in >> bigintOne;
    in >> bigintTwo;

    while(!in.eof()){
      std::cout << "Bigint one: " << bigintOne << std::endl;
      std::cout << "Bigint two: " << bigintTwo << std::endl;
      bigintResult = bigintOne + bigintTwo;
      std::cout << "Bigint result: " << bigintResult << std::endl << std::endl;
      in >> bigintOne;
      in >> bigintTwo;
    }
    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results
 
    in.close();
    return 0;
}

