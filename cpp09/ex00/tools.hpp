#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>

namespace tools {
bool isValidDate(std::string& date);
float stringToFloat(std::string& s);

class invalidFloat : std::exception {
 public:
  invalidFloat();
  ~invalidFloat() throw();
  virtual char const* what() const throw();
};

class badStringStream : std::exception {
 public:
  badStringStream();
  ~badStringStream() throw();
  virtual const char* what() const throw();
};
}  // namespace tools

#endif