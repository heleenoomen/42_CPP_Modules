
#include "PmergeMe.hpp"

#include <iostream>
#include <utility>

#include "MergeInsertion.hpp"
#include "tools.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
PmergeMe::PmergeMe() {}

/* Parametric constructor */
PmergeMe::PmergeMe(int argc, char** argv) {
  for (; argv != NULL; argv += 2) {
    std::pair<int, int> p =
        std::make_pair(pme::strtoi(*argv), pme::strtoi(*(argv + 1)));
    if (p.first < p.second) std::swap(p.first, p.second);
    v_.push_back(p);
    l_.push_back(p);
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
  makeChains(v_);
  MergeInsertion merge(v_);
  merge.sort();
}
