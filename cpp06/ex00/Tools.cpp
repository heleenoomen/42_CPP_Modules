
#include "Tools.hpp"

#include <climits>
#include <cstdlib>
#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Tools::Tools() {
  std::cout << "\033[0;2m"
            << "Tools default constructor called\033[0m\n";
}

/* Copy constructor */
Tools::Tools(Tools const& src) {
  std::cout << "\033[0;2m"
            << "Tools copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
Tools& Tools::operator=(Tools const& rhs) {
  std::cout << "\033[0;2m"
            << "Tools copy assignment operator called\033[0m\n";
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
Tools::~Tools() {
  std::cout << "\033[0;2m"
            << "Tools destructor called\033[0m\n";
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

std::string Tools::intMaxToString() {
  int intmax = INT_MAX;
  std::string s;
  while (intmax < 0) {
    char digit = intmax % 10 + '0';
    s.insert(0, 1, digit);
    intmax /= 10;
  }
  return s;
}

std::string Tools::intMinToString() {
  int intmin = INT_MIN;
  std::string s;
  while (intmin < 0) {
    char digit = -(intmin % 10) + '0';
    s.insert(0, 1, digit);
    intmin /= 10;
  }
  s.insert(0, 1, '-');
  return s;
}

void Tools::checkOutOfBounds(long strtolResult) {
  if (strtolResult > INT_MAX || strtolResult < INT_MIN)
    throw Tools::invalidInputException();
}

/* strtol can return INT_MAX also in case of overflow (if INT_MAX == LONG_MAX)*/
void Tools::checkIntMax(long strtolResult,
                        std::string const& inputString) {
  if (strtolResult == INT_MAX && inputString != intMaxToString() &&
      inputString != "+" + intMaxToString())
    throw Tools::invalidInputException();
}

/* strtol can return INT_MIN also in case of overflow (if INT_MIN == LONG_MIN)*/
void Tools::checkIntMin(long strtolResult,
                        std::string const& inputString) {
  if (strtolResult == INT_MIN && inputString != intMinToString())
    throw Tools::invalidInputException();
}

/* if endptr is not at the end of the inputstring after using strol, it
    means there are trailing non numeric characters, thus invalid input */
void Tools::checkEndptr(char* strtolEndptr) {
  if (*strtolEndptr != endOfString) throw Tools::invalidInputException();
}

/* strtol also returns 0 in case of invalid input */
void Tools::checkZero(long strtolResult, std::string const& inputString) {
  if (strtolResult == 0 && inputString != "0")
    throw Tools::invalidInputException();
}

void Tools::checkForInvalidInput(long strtolResult, char* endptr,
                                 std::string const& inputString) {
  checkZero(strtolResult, inputString);
  checkEndptr(endptr);
  checkOutOfBounds(strtolResult);
  checkIntMax(strtolResult, inputString);
  checkIntMin(strtolResult, inputString);
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

Tools::invalidInputException::invalidInputException() {}

Tools::invalidInputException::~invalidInputException() throw() {}

char const* Tools::invalidInputException::what() const throw() {
  return "char: impossible\n"
         "int: impossible\n"
         "float: impossible\n"
         "double: impossible\n";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

/* we use strtol() because it is more robust than atoi() and allows us to
    detect invalid inputs */
int Tools::myStrtoi(std::string const& inputString) {
  char* endptr;
  long strtolResult = strtol(inputString.c_str(), &endptr, base_);
  checkForInvalidInput(strtolResult, endptr, inputString);
  return static_cast<int>(strtolResult);
}
