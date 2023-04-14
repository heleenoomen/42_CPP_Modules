#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error: Wrong arguments\n";
    return 1;
  }
  try {
    BitcoinExchange btc(argv[1]);
    btc.run();
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 2;
  }
  return 0;
}
