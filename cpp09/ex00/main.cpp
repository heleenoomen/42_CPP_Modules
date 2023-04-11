#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  try {
    BitcoinExchange btc(argv[1]);
  } catch (std::exception& e) {
    e.what();
  }
}
