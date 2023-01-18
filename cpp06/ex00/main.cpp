#include <iostream>

#include "Converter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Wrong arguments\n";
    return EXIT_FAILURE;
  }
  Converter::convertLiteral(argv[1]);

  // Converter c(argv[1]);
  // c.printConversions_();
  return 0;
}
