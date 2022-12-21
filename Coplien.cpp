
#include "Coplien.hpp"
#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Coplien::Coplien() {
  std::cout << "\033[0;2m" << "Coplien default constructor called\033[0m\n";
}

/* Copy constructor */
Coplien::Coplien(Coplien const& src) {
  std::cout << "\033[0;2m" << "Coplien copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
Coplien& Coplien::operator=(Coplien const& rhs) {
  std::cout << "\033[0;2m" << "Coplien copy assignment operator called\033[0m\n";
  /* assign values here */
  return *this;
}

/* Destructor */
Coplien::~Coplien() {
  std::cout << "\033[0;2m" << "Coplien destructor called\033[0m\n";
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

std::ostream& operator<<(std::ostream& o, Coplien const& cname) {
  o << "\033[0;32m"
    // << some info here
    << "\033[0m";
  return o;
}
