
#include "IntConverter.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
IntConverter::IntConverter(int i) : intValue_(i) {}

/* Copy constructor */
IntConverter::IntConverter(IntConverter const& src) { *this = src; }

/* Copy assignment operator */
IntConverter& IntConverter::operator=(IntConverter const& rhs) {
  if (this == &rhs) return *this;
  intValue_ = rhs.intValue_;
  return *this;
}

/* Destructor */
IntConverter::~IntConverter() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void IntConverter::printChar_() const {
  if (intValue_ < static_cast<int>(CHAR_MIN) ||
      intValue_ > static_cast<int>(CHAR_MAX))
    std::cout << "char: impossible\n";
  else if (!isprint(intValue_))
    std::cout << "char: non displayble\n";
  else
    std::cout << "char: " << static_cast<char>(intValue_);
}

void IntConverter::printInt_() const {
  std::cout << "int: " << intValue_ << '\n';
}

void IntConverter::printFloat_() const {
  std::cout << "float: " << static_cast<float>(intValue_) << ".0f\n";
}

void IntConverter::printDouble_() const {
  std::cout << "double: " << static_cast<double>(intValue_) << ".0\n";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void IntConverter::printConversions() const {
  printChar_();
  printInt_();
  printFloat_();
  printDouble_();
}
