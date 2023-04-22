#include "pme.hpp"

/* convert a c-string to integer. Throw an exception if there is
no number to convert, if there are trailing characters or
- for this project - if the resulting integer is negative */
int pme::stoi(char const* s) {
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

/* return the nth number of the Jacobsthal sequence */
int pme::Jacobsthal(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

pme::invalidInputException::invalidInputException() {}

pme::invalidInputException::~invalidInputException() throw() {}

char const* pme::invalidInputException::what() const throw() { return "Error"; }
