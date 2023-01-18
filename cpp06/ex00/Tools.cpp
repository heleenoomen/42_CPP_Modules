
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

bool Tools::isPseudoLiteral(std::string const& s) {
  std::string pseudoLiterals[nbrOfPseudoLiterals] = {
    "inf", "+inf", "-inf", "nan", "inff", "+inff", "-inff", "nanf"
  };
  for (int i = 0; i < nbrOfPseudoLiterals; ++i) {
    if (s == pseudoLiterals[i])
      return true;
  }
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
