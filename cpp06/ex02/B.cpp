
#include "B.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
B::B() {
  std::cout << "\033[0;2m"
            << "B default constructor called\033[0m\n";
}

/* Copy constructor */
B::B(B const& src) {
  std::cout << "\033[0;2m"
            << "B copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
B& B::operator=(B const& rhs) {
  std::cout << "\033[0;2m"
            << "B copy assignment operator called\033[0m\n";
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
B::~B() {
  std::cout << "\033[0;2m"
            << "B destructor called\033[0m\n";
}
