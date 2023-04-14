#include "tools.hpp"

#include <ctime>
#include <sstream>
#include <stdexcept>

// strptime() returns NULL if the string could not be parsed correctly
// strptime() places pointer at the first byte after the date string - this
// should be the end of string character (the zero byte)
bool tools::isValidDate(std::string& date) {
  struct tm time;
  const char* format = "%Y-%m-%d";
  char* endOfdate = strptime(date.c_str(), format, &time);
  if (endOfdate != NULL && !*endOfdate) return true;
  return false;
}

float tools::stringToFloat(std::string& s) {
  std::stringstream ss(s);
  ss.exceptions(std::stringstream::badbit);
  float f;
  ss >> f;
  if (ss.fail()) throw invalidFloat();
  std::string trailingChars;
  ss >> trailingChars;
  if (!ss.fail() && !ss.eof()) throw invalidFloat();
  return f;
}

tools::invalidFloat::invalidFloat() {}
tools::invalidFloat::~invalidFloat() throw() {}
const char* tools::invalidFloat::what() const throw() { return "Bad input"; }
