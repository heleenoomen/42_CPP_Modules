#include "tools.hpp"

#include <ctime>
#include <sstream>
#include <stdexcept>

/* strptime() returns NULL if the string could not be parsed correctly
strptime() places pointer at the first byte after the date string - this
should be the end of string character (the zero byte). The zero byte may
be preceded by trailing whitspaces */
bool tools::isValidDate(std::string& date) {
  struct tm time;
  const char* format = "%Y-%m-%d";
  char* endOfdate = strptime(date.c_str(), format, &time);
  if (endOfdate == NULL) return false;  // date could not be read correctly
  while (std::isspace(*endOfdate)) endOfdate++;
  if (!*endOfdate) return true;
  return false;  // trailing characters other than whitespace present
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
