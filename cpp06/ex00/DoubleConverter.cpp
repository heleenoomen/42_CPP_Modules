
#include "DoubleConverter.hpp"
#include "Tools.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
DoubleConverter::DoubleConverter(char c) : charValue_(c) {}

/* Copy constructor */
DoubleConverter::DoubleConverter(DoubleConverter const& src) { *this = src; }

/* Copy assignment operator */
DoubleConverter& DoubleConverter::operator=(DoubleConverter const& rhs) {
  if (this == &rhs) return *this;
  charValue_ = rhs.charValue_;
  return *this;
}

/* Destructor */
DoubleConverter::~DoubleConverter() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

double DoubleConverter::NaN() const {
  return std::numeric_limits<double>::quiet_NaN();
}

bool DoubleConverter::charOverflow() const {
  if (doubleValue_ < static_cast<double>(CHAR_MIN) return true;
  if (doubleValue_ > static_cast<double>(CHAR_MAX) return true;
  return false;
}

bool DoubleConverter::charNonDisplayable() const {
  if (!isprint(static_cast<int> doubleValue_)) return true;
  return false;
}

bool DoubleConverter::intOverflow() const {
  if (doubleValue_ < static_cast<int>(INT_MIN) return true;
  if (doubleValue_ > static_cast<int>(INT_MAX) return true;
  return false;
}

/* check values that are representable in double, but convert to inff or -inff
 * when casted to float, i.e. without the bounds of float */
bool DoubleConverter::floatOverflow() const {
  float floatValue = static_cast<float>(doubleValue_);
  if (floatValue == Tools::inff() && doubleValue_ != Tools::inf())
    return true;
  if (floatValue == -Tools::inff() && doubleValue_ != -Tools::inf())
    return true;
  return false;
}

void DoubleConverter::printChar_() const {
  if (charOverflow() || NaN())
    std::cout << "char: impossible\n";
  else if (charNonDisplayable())
    std::cout << "char: non displayable\n";
  else
    std::cout << "char: " << static_cast<char>(doubleValue_) << '\n';
}

void DoubleConverter::printInt_() const {
  if (intOverflow() || NaN())
    std::cout << "int: impossible\n";
  else
    std::cout << "int: " << static_cast<int>(doubleValue_) << '\n';
}

void DoubleConverter::printFloat_() const {
  if (floatOverflow())
    std::cout << "float: impossible\n";
  else
    std::cout << "float: " << static_cast<float>(doubleValue_) << "f\n";
}

void DoubleConverter::printDouble_() const {
  std::cout << "double: " << doubleValue_ << ".0\n";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void DoubleConverter::printConversions() const {
  printChar_();
  printInt_();
  printFloat_();
  printDouble_();
}
