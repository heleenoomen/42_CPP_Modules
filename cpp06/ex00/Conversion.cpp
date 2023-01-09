
#include "Conversion.hpp"
#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Conversion::Conversion() {
  std::cout << "\033[0;2m" << "Conversion default constructor called\033[0m\n";
}

Conversion::Conversion(std::string const& input) : input_(input) {
  std::cout << "\033[0;2m" << "Conversion parametric constructor called\033[0m\n";
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


/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Conversion::displayChar() 

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Conversion const& c) {
  o << "\033[0;32m"
    << c.getInput()
    << "\033[0m";
  return o;
}
