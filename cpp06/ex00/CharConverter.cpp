
#include "CharConverter.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
CharConverter::CharConverter(char c) : charValue_(c) {}

/* Copy constructor */
CharConverter::CharConverter(CharConverter const& src) { *this = src; }

/* Copy assignment operator */
CharConverter& CharConverter::operator=(CharConverter const& rhs) {
  if (this == &rhs) return *this;
  charValue_ = rhs.charValue_;
  return *this;
}

/* Destructor */
CharConverter::~CharConverter() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void CharConverter::printChar_() const {
  if (!isprint(charValue_))
    std::cout << "char: non displayable\n";
  else
    std::cout << "char: " << charValue_ << '\n';
}

void CharConverter::printInt_() const {
  std::cout << "int: " << static_cast<int>(charValue_) << '\n';
}

void CharConverter::printFloat_() const {
  std::cout << "float: " << static_cast<float>(charValue_) << ".0f\n";
}

void CharConverter::printDouble_() const {
  std::cout << "double: " << static_cast<double>(charValue_) << ".0\n";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void CharConverter::printConversions() const {
  printChar_();
  printInt_();
  printFloat_();
  printDouble_();
}
