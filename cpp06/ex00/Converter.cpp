
#include "Converter.hpp"

#include <cfloat>
#include <climits>
#include <iostream>
#include <limits>

#include "Checker.hpp"
#include "Tools.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Converter::Converter() {}

/* String constructor */
Converter::Converter(std::string const& inputString)
    : inputString_(inputString), value_(strtod(inputString.c_str(), NULL)) {}

/* Copy constructor */
Converter::Converter(Converter const& src) { *this = src; }

/* Copy assignment operator */
Converter& Converter::operator=(Converter const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
Converter::~Converter() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

bool Converter::charOverflow() const {
  if (value_ < static_cast<double>(CHAR_MIN) ||
      value_ > static_cast<double>(CHAR_MAX))
    return true;
  return false;
}

bool Converter::intOverflow() const {
  if (value_ < static_cast<double>(INT_MIN) ||
      value_ > static_cast<double>(INT_MAX))
    return true;
  return false;
}

bool Converter::charNonDisplayable() const {
  if (!isprint(static_cast<int>(value_))) return true;
  return false;
}

bool Converter::charImpossible() const {
  if (value_ == Tools::quietNaN() || value_ == Tools::signalingNaN())
    return true;
  if (charOverflow()) return true;
  return false;
}

bool Converter::intImpossible() const {
  if (value_ == Tools::quietNaN() || value_ == Tools::signalingNaN())
    return true;
  if (intOverflow()) return true;
  return false;
}

bool Converter::floatOverflow() const {
  if (strtof(inputString_.c_str(), NULL) == Tools::inff() &&
      value_ != Tools::inf())
    return true;
  if (strtof(inputString_.c_str(), NULL) == -Tools::inff() &&
      value_ != -Tools::inf())
    return true;
  return false;
}

bool Converter::floatImpossible() const {
  if (floatOverflow()) return true;
  return false;
}

void Converter::printChar_() const {
  try {
    char c = static_cast<char>(value_);
    std::cout << "char: " << c << '\n';
  } catch (std::exception& e) {
    std::cout << "char: impossible\n";
  }
  // if (charImpossible())
  //   std::cout << "char: impossible\n";
  // else if (charNonDisplayable())
  //   std::cout << "char: non displayable\n";
  // else
  //   std::cout << "char: " << static_cast<char>(value_) << '\n';
}

void Converter::printInt_() const {
  if (intImpossible())
    std::cout << "int: impossible\n";
  else
    std::cout << "int: " << static_cast<int>(value_) << '\n';
}

void Converter::printFloat_() const {
  if (floatImpossible()) {
    std::cout << "float: impossible\n";
    return;
  }
  float floatValue_ = static_cast<float>(value_);
  std::cout << "float: " << floatValue_;
  if (floatValue_ == static_cast<float>(static_cast<int>(floatValue_)))
    std::cout << ".0";
  std::cout << "f\n";
}

void Converter::printDouble_() const {
  std::cout << "double: " << value_;
  if (value_ == static_cast<double>(static_cast<int>(value_)))
    std::cout << ".0";
  std::cout << '\n';
}

void Converter::printConversions_() const {
  printChar_();
  printInt_();
  printFloat_();
  printDouble_();
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Converter::convertLiteral(std::string const& inputString) {
  try {
    Checker::checkInput(inputString);
    Converter c(inputString);
    c.printConversions_();
  } catch (std::exception& e) {
    std::cout << e.what();
  }
}