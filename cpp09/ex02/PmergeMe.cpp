
#include "PmergeMe.hpp"
#include "PmergeVec.hpp"
#include "PmergeList.hpp"
#include "tools.hpp"

#include <iostream>
#include <utility>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
PmergeMe::PmergeMe() {}

/* Parametric constructor */
PmergeMe::PmergeMe(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    std::string arg(argv[i]);
    int nbr = tools::strToInt(arg);
    v_.push_back(nbr);
    l_.push_back(nbr);
  }
}

/* Copy constructor */
PmergeMe::PmergeMe(PmergeMe const& src) { *this = src; }

/* Copy assignment operator */
PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
PmergeMe::~PmergeMe() {}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void PmergeMe::run() {
  PmergeVec pmv(v_);
  pmv.sort();
  // PmergeList pml(l_);
  // pml.sort();
}
