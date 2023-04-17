#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error: Wrong arguments\n";
    return 1;
  }
  RPN rpn(argv[1]);
  rpn.calculate();
}
