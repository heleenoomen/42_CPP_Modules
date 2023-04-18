#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <sstream>
#include <string>
#include <cmath>

namespace tools {
  int strToInt(std::string& token);

  int Jacobsthal(int n);

  class invalidInputException : public std::exception {
   public:
    invalidInputException();
    ~invalidInputException() throw();
    virtual char const* what() const throw();
  };
};

#endif