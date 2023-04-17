#include "RPN.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor (private) */
RPN::RPN() : input_(NULL) { initLookupTable(); }

/* Constructor */
RPN::RPN(char const* input) : input_(input) { initLookupTable(); }

/* Copy constructor */
RPN::RPN(RPN const& src) : input_(src.input_) { *this = src; }

/* Copy assignment operator */
RPN& RPN::operator=(RPN const& rhs) {
  if (this == &rhs) return *this;
  stack_ = rhs.stack_;
  return *this;
}

/* Destructor */
RPN::~RPN() {}

/* ************************************************************************** */
/* Nested Exception Classes                                                   */
/* ************************************************************************** */

RPN::invalidInputException::invalidInputException() {}

RPN::invalidInputException::~invalidInputException() throw() {}

char const* RPN::invalidInputException::what() const throw() {
  return "Error";
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void RPN::initLookupTable() {
  operations_[0].symbol= '+';
  operations_[0].func = &RPN::add;
  operations_[1].symbol= '-';
  operations_[1].func = &RPN::subtract;
  operations_[2].symbol= '*';
  operations_[2].func = &RPN::multiplicate;
  operations_[3].symbol= '/';
  operations_[3].func = &RPN::divide;
}

bool RPN::isOperator(std::string& token) {
  if (token.size() != 1) return false;
  for (int i = 0; i < numberOfOperators_; ++i)
    if (token[0] == operations_[i].symbol) return true;
  return false;
}

int RPN::strToInt(std::string& token) const {
  int integer;
  std::stringstream tokenS(token);
  tokenS.exceptions(std::ios::badbit);
  tokenS >> integer;
  if (tokenS.fail()) throw invalidInputException();
  std::string leftOvers;
  tokenS >> leftOvers;
  if (!tokenS.fail() || !tokenS.eof()) throw invalidInputException();
  if (integer > 9 || integer < 0) throw invalidInputException();
  return integer;
}

int RPN::popNumber() {
  int number = stack_.top();
  stack_.pop();
  return number;
}

void RPN::performOperation(char symbol) {
  if (stack_.size() < 2) throw invalidInputException();
  int n1 = popNumber();
  int n2 = popNumber();
  for (int i = 0; i < numberOfOperators_; ++i) {
      if (symbol == operations_[i].symbol)
        stack_.push((this->*operations_[i].func)(n1, n2));
  }
}

int RPN::add(int n1, int n2) { return n2 + n1; }

int RPN::subtract(int n1, int n2) { return n2 - n1; }

int RPN::multiplicate(int n1, int n2) { return n2 * n1; }

int RPN::divide(int n1, int n2) { return n2 / n1; }

int RPN::processInput() {
  std::stringstream tokenStream(input_);
  tokenStream.exceptions(std::ios::badbit);
  for (std::string token; tokenStream >> token;) {
    if (isOperator(token)) performOperation(token[0]);
    else stack_.push(strToInt(token));
  }
  if (stack_.size() != 1) throw invalidInputException();
  return stack_.top();
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void RPN::calculate() {
  try {
    int result = processInput();
    std::cout << result << '\n';
  } catch (std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}
