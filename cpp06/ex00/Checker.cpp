
#include "Checker.hpp"

#include <climits>
#include <cstdlib>
#include <iostream>
#include <limits>

#include "Converter.hpp"
#include "Tools.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Checker::Checker() {}

Checker::Checker(std::string const &inputString)
    : type_(-1), inputString_(inputString) {
  launchTypeCheckerTable_();
}

/* Copy constructor */
Checker::Checker(Checker const &src) { *this = src; }

/* Copy assignment operator */
Checker &Checker::operator=(Checker const &rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
Checker::~Checker() {}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Checker::checkEndptr_(char *endptr) const {
  if (*endptr != '\0') throw InvalidInputException();
}

void Checker::checkEndptrFloat_(std::string const &endptr) const {
  if (endptr != "f") throw InvalidInputException();
}

void Checker::intCheckOverflow_(long strtolResult) const {
  if (strtolResult < INT_MIN || strtolResult > INT_MAX)
    throw InvalidInputException();
}

void Checker::checkFalseIntMax_(long strtolResult) const {
  if (strtolResult == INT_MAX && inputString_ != Tools::intMaxString() &&
      inputString_ != '+' + Tools::intMaxString())
    throw InvalidInputException();
}

void Checker::checkFalseIntMin_(long strtolResult) const {
  if (strtolResult == INT_MIN && inputString_ != Tools::intMinString())
    throw InvalidInputException();
}

void Checker::floatCheckOverflow_(float strtofresult) const {
  if (strtofresult == Tools::inff() || strtofresult == -Tools::inff())
    throw InvalidInputException();
}

void Checker::doubleCheckOverflow_(double strtodResult) const {
  if (strtodResult == Tools::inf() || strtodResult == -Tools::inf())
    throw InvalidInputException();
}

void Checker::checkInt_() const {
  char *endptr(NULL);
  long strtolResult(strtol(inputString_.c_str(), &endptr, baseTen_));
  checkEndptr_(endptr);
  intCheckOverflow_(strtolResult);
  checkFalseIntMax_(strtolResult);
  checkFalseIntMin_(strtolResult);
}

void Checker::checkFloat_() const {
  char *endptr(NULL);
  float strtofResult(strtof(inputString_.c_str(), &endptr));
  checkEndptrFloat_(endptr);
  floatCheckOverflow_(strtofResult);
}

void Checker::checkDouble_() const {
  char *endptr(NULL);
  double strtodResult(strtod(inputString_.c_str(), &endptr));
  checkEndptr_(endptr);
  doubleCheckOverflow_(strtodResult);
}

void Checker::checkIfValid_() const {
  for (int i = 0; i < nbrOfTypes_; ++i) {
    if (i == type_) (this->*typeCheckerTable_[i])();
  }
}

void Checker::determineType_() {
  if (Tools::isPseudoLiteral(inputString_))
    type_ = pseudoLiteral;
  else if (inputString_.length() == 1 && !isdigit(inputString_[0]))
    type_ = charType;
  else if (inputString_.find('f', 0) != std::string::npos &&
           inputString_.find('.', 0) != std::string::npos)
    type_ = floatType;
  else if (inputString_.find('.', 0) != std::string::npos)
    type_ = doubleType;
  else
    type_ = intType;
}

void Checker::checkChar() const { return; }

void Checker::checkPseudoLiteral() const { return; }

void Checker::launchTypeCheckerTable_() {
  typeCheckerTable_[pseudoLiteral] = &Checker::checkPseudoLiteral;
  typeCheckerTable_[charType] = &Checker::checkChar;
  typeCheckerTable_[intType] = &Checker::checkInt_;
  typeCheckerTable_[floatType] = &Checker::checkFloat_;
  typeCheckerTable_[doubleType] = &Checker::checkDouble_;
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

Checker::InvalidInputException::InvalidInputException() {}

Checker::InvalidInputException::~InvalidInputException() throw() {}

char const *Checker::InvalidInputException::what() const throw() {
  return "Char: impossible\n"
         "Int: impossible\n"
         "Float: impossible\n"
         "Double: impossible\n";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Checker::checkInput(std::string const &inputString) {
  Checker checker(inputString);
  checker.determineType_();
  checker.checkIfValid_();
}
