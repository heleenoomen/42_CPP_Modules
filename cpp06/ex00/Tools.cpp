
#include "Tools.hpp"

#include <climits>
#include <iostream>
#include <limits>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Tools::Tools() {}

/* Copy constructor */
Tools::Tools(Tools const& src) { *this = src; }

/* Copy assignment operator */
Tools& Tools::operator=(Tools const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
Tools::~Tools() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

bool Tools::isPseudoLiteralDouble(std::string const& s) {
  if (s == "inf" || s == "+inf" || s == "-inf" || s == "nan") return true;
  return false;
}

bool Tools::isPseudoLiteralFloat(std::string const& s) {
  if (s == "inff" || s == "+inff" || s == "-inff" || s == "nanf") return true;
  return false;
}

float Tools::inff() { return std::numeric_limits<float>::infinity(); }

double Tools::inf() { return std::numeric_limits<double>::infinity(); }

std::string Tools::intMaxString() {
  std::string s;
  int intmax = INT_MAX;
  while (intmax) {
    char c = intmax % 10 + '0';
    s = c + s;
    intmax /= 10;
  }
  return s;
}

std::string Tools::intMinString() {
  std::string s;
  int intmin = INT_MIN;
  while (intmin) {
    char c = -(intmin % 10) + '0';
    s = c + s;
    intmin /= 10;
  }
  return '-' + s;
}
