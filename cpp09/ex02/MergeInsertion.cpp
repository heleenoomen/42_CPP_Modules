
#include <iostream>
#include <utility>

#include "MergeInsertion.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
MergeInsertion::MergeInsertion() {}

/* Parametric contstructor */
MergeInsertion::MergeInsertion(std::vector<int> v) : sequence_(v) {}

/* Copy constructor */
MergeInsertion::MergeInsertion(MergeInsertion const& src) { *this = src; }

/* Copy assignment operator */
MergeInsertion& MergeInsertion::operator=(MergeInsertion const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
MergeInsertion::~MergeInsertion() {}

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

void MergeInsertion::makePairs() {
  typedef std::vector<int>::iterator vectIt;
  for (vectIt it = sequence_.begin(); it + 1 != sequence_.end(); ++it) {
    std::pair<int, int> p;
    p.first = *it;
    p.second = *(it + 1);
    pairs_.push_back(p);
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// std::ostream& operator<<(std::ostream& o, MergeInsertion const& cname) {
//   o << "\033[0;32m"
//     // << some info here
//     << "\033[0m";
//   return o;
// }
