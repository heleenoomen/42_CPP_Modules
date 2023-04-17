
#include "RPN.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
RPN::RPN() {}

/* Constructor */
RPN::RPN(char const* input) : input_(input) {}

/* Copy constructor */
RPN::RPN(RPN const& src) : input_(src.input_) { *this = src; }

/* Copy assignment operator */
RPN& RPN::operator=(RPN const& rhs) {
  if (this == &rhs) return *this;
  numbers_ = rhs.numbers_;
  result_ = rhs.result_;
  return *this;
}

/* Destructor */
RPN::~RPN() {}

/* ************************************************************************** */
/* Nested Exception Classes                                                   */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

bool RPN::isOperator() {
  if (token_.size() != 1) return false;
  for (int i = 0; i < numberOfOperators_; ++i)
    if (token_[0] == operators_[i]) {
      operator_ = token_[0];
      return true;
    }
  return false;
}

int RPN::strToInt() const {
  int integer;
  std::stringstream token(token_);
  if (!token) throw std::runtime_error("System error");
  token.exceptions(std::ios::badbit);
  token >> integer;
  if (token.fail()) throw invalidInputExecption();
  std::string leftOvers;
  token >> leftOvers;
  if (!token.fail() || !token.eof()) throw invalidInputExecption();
  return integer;
}

void RPN::putOnStack() {
  int nbr = strToInt();
  numbers_.push(nbr);
}

void RPN::performOperation() {
  for (int i = 0; i < numberOfOperators_; ++i) {
    if (token_[0] == operators_[i]) (this->*_operateOnStack[i].f)();
  }
}

void RPN::processInput() {
  std::stringstream ist(input_);
  if (!ist) throw(std::runtime_error("Unable to open input stream\n"));
  for (ist; ist >> token_;) {
    if (isOperator()) performOperation();
    putOnStack();
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void RPN::calculate() {
  try {
    processInput();
    std::cout << result_ << '\n';
  } catch (invalidInputExecption& e) {
    std::cerr << e.what() << '\n';
  }
}
/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// std::ostream& operator<<(std::ostream& o, RPN const& cname) {
//   o << "\033[0;32m"
//     // << some info here
//     << "\033[0m";
//   return o;
// }
