
#include "C.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
C::C() {
  std::cout << "\033[0;2m"
            << "C default constructor called\033[0m\n";
}

/* Copy constructor */
C::C(C const& src) {
  std::cout << "\033[0;2m"
            << "C copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
C& C::operator=(C const& rhs) {
  std::cout << "\033[0;2m"
            << "C copy assignment operator called\033[0m\n";
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
C::~C() {
  std::cout << "\033[0;2m"
            << "C destructor called\033[0m\n";
}
