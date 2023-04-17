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
  if (integer > 9 || integer < 0) throw invalidInputException();
  return integer;
}

tools::invalidInputException::invalidInputException() {}

tools::invalidInputException::~invalidInputException() throw() {}

char const* tools::invalidInputException::what() const throw() {
  return "Error";
}