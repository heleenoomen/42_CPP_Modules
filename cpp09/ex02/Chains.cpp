
#include "Chains.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Chains::Chains() {}

/* Parametric constructor */


/* Copy constructor */
Chains::Chains(Chains const& src) { *this = src; }

/* Copy assignment operator */
Chains& Chains::operator=(Chains const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
Chains::~Chains() {}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// std::ostream& operator<<(std::ostream& o, Chains const& cname) {
//   o << "\033[0;32m"
//     // << some info here
//     << "\033[0m";
//   return o;
// }
