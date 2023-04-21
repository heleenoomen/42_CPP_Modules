#include "tools.hpp"

int tools::strToInt(std::string& s) {
  int integer;
  std::stringstream sS(s);
  sS.exceptions(std::ios::badbit);
  sS >> integer;
  if (sS.fail()) throw invalidInputException();
  std::string leftOvers;
  sS >> leftOvers;
  if (!sS.fail() || !sS.eof()) throw invalidInputException();
  if (integer < 0) throw invalidInputException();
  return integer;
}

int tools::Jacobsthal(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

std::pair<int, int> tools::sortedPair(int n1, int n2) {
  std::pair<int, int> p;
  p.first = n1 >= n2 ? n1 : n2;
  p.second = n2 <= n1 ? n2 : n1;
  return p;
}

tools::invalidInputException::invalidInputException() {}

tools::invalidInputException::~invalidInputException() throw() {}

char const* tools::invalidInputException::what() const throw() {
  return "Error";
}
