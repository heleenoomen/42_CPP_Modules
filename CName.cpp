
#include "CName.hpp"
#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
CName::CName() {
  std::cout << "\033[0;2m" << "CName default constructor called\033[0m\n";
}

/* Copy constructor */
CName::CName(CName const& src) {
  std::cout << "\033[0;2m" << "CName copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
CName& CName::operator=(CName const& rhs) {
  std::cout << "\033[0;2m" << "CName copy assignment operator called\033[0m\n";
  /* assign values here */
  return *this;
}

/* Destructor */
CName::~CName() {
  std::cout << "\033[0;2m" << "CName destructor called\033[0m\n";
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */


/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */


/* ************************************************************************** */
/* Public                                                                     */
/* ************************************************************************** */


/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, CName const& cname) {
  o << "\033[0;32m"
    // << some info here
    << "\033[0m";
  return o;
}
