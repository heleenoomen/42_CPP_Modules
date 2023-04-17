#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <sstream>
#include <string>

namespace tools {
  int strToInt(std::string& token);

  class invalidInputException : public std::exception {
   public:
    invalidInputException();
    ~invalidInputException() throw();
    virtual char const* what() const throw();
  };
};

#endif