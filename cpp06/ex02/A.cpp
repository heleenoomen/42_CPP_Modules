
#include "A.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
A::A() {
  std::cout << "\033[0;2m"
            << "A default constructor called\033[0m\n";
}

/* Copy constructor */
A::A(A const& src) {
  std::cout << "\033[0;2m"
            << "A copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
A& A::operator=(A const& rhs) {
  std::cout << "\033[0;2m"
            << "A copy assignment operator called\033[0m\n";
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
A::~A() {
  std::cout << "\033[0;2m"
            << "A destructor called\033[0m\n";
}
