
#include "Tools.hpp"

#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iostream>

std::string const Tools::floatSuffix = "f";

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
void Tools::checkIntMax(long strtolResult, std::string const& inputString) {
  if (strtolResult == INT_MAX && inputString != intMaxToString() &&
      inputString != "+" + intMaxToString())
    throw Tools::invalidInputException();
}

/* strtol can return INT_MIN also in case of overflow (if INT_MIN == LONG_MIN)*/
void Tools::checkIntMin(long strtolResult, std::string const& inputString) {
  if (strtolResult == INT_MIN && inputString != intMinToString())
    throw Tools::invalidInputException();
}

/* if endptr is not at the end of the inputstring after using strol, it
    means there are trailing non numeric characters, thus invalid input */
void Tools::checkEndptr(char* strtolEndptr) {
  if (*strtolEndptr != endOfString) throw Tools::invalidInputException();
}

void Tools::intCheckInvalidInput(long strtolResult, char* endptr,
                                 std::string const& inputString) {
  checkEndptr(endptr);
  checkOutOfBounds(strtolResult);
  checkIntMax(strtolResult, inputString);
  checkIntMin(strtolResult, inputString);
}

/* after the digits representing the float, there should be only "f". Otherwise,
 * the string contains trailing non numeric characters and input is invalid */
void Tools::floatCheckEndptr(const char* endptr) {
  if (endptr != Tools::floatSuffix) throw Tools::invalidInputException();
}

/* strtof() returns inff also for strings representing huge value (HUGE_VALF
 * does not exist in C++98) */
void Tools::floatCheckInff(float strtofResult, std::string const& inputString) {
  if (strtofResult == Tools::inf() && inputString != "inff" &&
      inputString != "+inff")
    throw Tools::invalidInputException();
}

/* strotf() returns -inff also for strings representing a huge negative value
 * (HUGE_VALF does not exist in C++98) */
void Tools::floatCheckMinusInff(float strtofResult,
                                std::string const& inputString) {
  if (strtofResult == strtof("-inff", NULL) && inputString != "-inff")
    throw Tools::invalidInputException();
}

void Tools::floatCheckInvalidInput(float strtofResult, char* endptr,
                                   std::string const& inputString) {
  floatCheckEndptr(endptr);
  floatCheckInff(strtofResult, inputString);
  floatCheckMinusInff(strtofResult, inputString);
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
void Tools::checkInt(std::string const& inputString) {
  char* endptr;
  long strtolResult = strtol(inputString.c_str(), &endptr, base_);
  intCheckInvalidInput(strtolResult, endptr, inputString);
}

void Tools::myStrtof(std::string const& inputString) {
  char* endptr;
  float strtofResult = strtof(inputString.c_str(), &endptr);
  floatCheckInvalidInput(strtofResult, endptr, inputString);
}

double Tools::inf() {
  return std::numeric_limits<double>::infinity();
}

float Tools::inff() {
  return std::numeric_limits<float>::infinity();
}
