
#include "Conversion.hpp"
#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Conversion::Conversion() {
  std::cout << "\033[0;2m" << "Conversion default constructor called\033[0m\n";
  determineType();
  launchConversionTable();
}

Conversion::Conversion(std::string const& input) : input_(input) {
  std::cout << "\033[0;2m" << "Conversion parametric constructor called\033[0m\n";
  determineType();
  launchConversionTable();
}

/* Copy constructor */
Conversion::Conversion(Conversion const& src) {
  std::cout << "\033[0;2m" << "Conversion copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
Conversion& Conversion::operator=(Conversion const& rhs) {
  std::cout << "\033[0;2m" << "Conversion copy assignment operator called\033[0m\n";
  if (this == &rhs)
    return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
Conversion::~Conversion() {
  std::cout << "\033[0;2m" << "Conversion destructor called\033[0m\n";
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */


/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

std::string const& Conversion::getInput() const { return input_; }

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Conversion::convert() const {
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

bool Conversion::floatIsPseudoLiteral() const {
  if (input_ == "+inff" || input_ == "-inff" || input_ == "nanf")
    return true;
  return false;
}

bool Conversion::doubleIsPseudoLiteral() const {
  if (input_ == "+inf" || input_ == "-inf" || input_ == "nan")
    return true;
  return false;
}

void Conversion::determineType() {
  if (input_.length() == 1 && !isdigit(input_[0]))
    type_ = charType;
  else if (input_.find('f') || floatIsPseudoLiteral())
    type_ = floatType;
  else if (input_.find('.') || doubleIsPseudoLiteral())
    type_ = doubleType;
  else
    type_ = intType;
}

void Conversion::convertChar() const {}
void Conversion::convertInt() const {}
void Conversion::convertFloat() const {}
void Conversion::convertDouble() const {}

void Conversion::launchConversionTable() {
  conversionTable_[charType] = &Conversion::convertChar;
  conversionTable_[intType] = &Conversion::convertInt;
  conversionTable_[floatType] = &Conversion::convertFloat;
  conversionTable_[doubleType] = &Conversion::convertDouble;
}


/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Conversion const& c) {
  o << "\033[0;32m"
    << c.getInput()
    << "\033[0m";
  return o;
}
