/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:02:08 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/25 13:41:19 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <cfloat>
#include <climits>
#include <iostream>
#include <limits>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Converter::Converter()
    : inputString_(""),
      value_(0),
      hasDot_(false),
      hasF_(false),
      type_(intType) {
  launchCheckTable_();
}

/* String constructor */
Converter::Converter(std::string const& inputString)
    : inputString_(inputString),
      value_(strtod(inputString_.c_str(), &endptrStrtod_)),
      hasDot_(inputString_.find('.', 0) != std::string::npos),
      hasF_(inputString_.find('f', 0) != std::string::npos) {
  determineType_();
  determineValue_();
  launchCheckTable_();
}

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

/* LAUNCH INPUT CHECKER TABLE */

void Converter::launchCheckTable_() {
  checkTable_[pseudoLiteral] = &Converter::empty_;
  checkTable_[charType] = &Converter::empty_;
  checkTable_[intType] = &Converter::checkInt_;
  checkTable_[floatType] = &Converter::checkFloat_;
  checkTable_[doubleType] = &Converter::checkDouble_;
}

/* CHECK INPUT */

void Converter::empty_() const { return; }

void Converter::checkInt_() const {
  if (intOverflow_()) throw InvalidInputException();
  if (*endptrStrtod_ != '\0') throw InvalidInputException();
}

void Converter::checkFloat_() const {
  if (floatOverflow_()) throw InvalidInputException();
  if (std::string(endptrStrtod_) != "f") throw InvalidInputException();
}

void Converter::checkDouble_() const {
  if (value_ == std::numeric_limits<double>::infinity() ||
      value_ == -std::numeric_limits<double>::infinity())
    throw InvalidInputException();
  if (*endptrStrtod_ != '\0') throw InvalidInputException();
}

void Converter::checkInput_() const {
  for (int i = 0; i < nbrOfTypes_; ++i)
    if (i == type_) (this->*checkTable_[i])();
}

/* DETERMINE TYPE & VALUE */

bool Converter::isPseudoliteral() const {
  const char* pseudoliterals[nbrOfPseudoliterals_] = {
      "+inf", "inf", "-inf", "nan", "+inff", "inff", "-inff", "nanf"};
  for (int i = 0; i < nbrOfPseudoliterals_; ++i) {
    if (inputString_ == pseudoliterals[i]) return true;
  }
  return false;
}

void Converter::determineType_() {
  if (inputString_ == "")
    throw InvalidInputException();
  else if (isPseudoliteral())
    type_ = pseudoLiteral;
  else if (inputString_.length() == 1 && isprint(inputString_[0]) &&
           !isdigit(inputString_[0]))
    type_ = charType;
  else if (hasDot_ && hasF_)
    type_ = floatType;
  else if (hasDot_)
    type_ = doubleType;
  else
    type_ = intType;
}

void Converter::determineValue_() {
  if (type_ == charType)
    value_ = static_cast<int>(inputString_[0]);
  else
    value_ = strtod(inputString_.c_str(), &endptrStrtod_);
}

/* OVERFLOW & NON DISPLAYABLE */

bool Converter::charNonDisplayable_() const {
  if (!isprint(static_cast<int>(value_))) return true;
  return false;
}

bool Converter::charOverflow_() const {
  if (value_ < static_cast<double>(CHAR_MIN) ||
      value_ > static_cast<double>(CHAR_MAX))
    return true;
  return false;
}

bool Converter::intOverflow_() const {
  if (value_ < static_cast<double>(INT_MIN) ||
      value_ > static_cast<double>(INT_MAX))
    return true;
  return false;
}

/* floats use a sign bit rather than two's complement. Therefore, it is (with
    most compilers) safe to use -FLT_MAX to define the greatest negative
    number)*/
bool Converter::floatOverflow_() const {
  if (value_ > static_cast<double>(FLT_MAX) ||
      value_ < static_cast<double>(-FLT_MAX)) {
    return true;
  }
  return false;
}

/* PRINTING */

void Converter::printChar_() const {
  if (charOverflow_() || type_ == pseudoLiteral)
    std::cout << "char: impossible\n";
  else if (charNonDisplayable_())
    std::cout << "char: non displayable\n";
  else
    std::cout << "char: " << static_cast<char>(value_) << '\n';
}

void Converter::printInt_() const {
  if (intOverflow_() || type_ == pseudoLiteral)
    std::cout << "int: impossible\n";
  else
    std::cout << "int: " << static_cast<int>(value_) << '\n';
}

void Converter::printFloat_() const {
  if (floatOverflow_() && type_ != pseudoLiteral)
    std::cout << "float: impossible\n";
  else {
    std::cout << "float: " << static_cast<float>(value_);
    if (value_ == static_cast<double>(static_cast<int>(value_)))
      std::cout << ".0";
    std::cout << "f\n";
  }
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
/* Exceptions                                                                 */
/* ************************************************************************** */

Converter::InvalidInputException::InvalidInputException() {}

Converter::InvalidInputException::~InvalidInputException() throw() {}

char const* Converter::InvalidInputException::what() const throw() {
  return "Char: impossible\n"
         "Int: impossible\n"
         "Float: impossible\n"
         "Double: impossible\n";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Converter::convertLiteral(std::string const& inputString) {
  try {
    Converter c(inputString);
    c.checkInput_();
    c.printConversions_();
  } catch (std::exception& e) {
    std::cout << e.what();
  }
}
