#include "tools.hpp"

#include <ctime>
#include <stdexcept>

// strptime() returns NULL if the string could not be parsed correctly
// strptime() places pointer at the first byte after the date string - this
// should be the end of string character (the zero byte)
bool tools::isValidDate(std::string& date) {
  struct tm time;
  const char* format = "%Y-%m-%d";
  char* ptr;
  char* endOfdate = strptime(date.c_str(), format, &time);
  if (endOfdate != NULL && !*endOfdate) return true;
  return false;
}
