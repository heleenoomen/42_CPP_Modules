#include <iostream>

#include "Converter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Wrong arguments\n";
    return EXIT_FAILURE;
  }
  Converter::convertLiteral(argv[1]);
  return 0;
}