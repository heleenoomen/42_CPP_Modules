
#include "PmergeVec.hpp"

#include <iostream>
#include <utility>

#include "MergeChains.hpp"
#include "tools.hpp"
// #include "mergeSortPairs.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
PmergeVec::PmergeVec() {}

/* Parametric contstructor */
PmergeVec::PmergeVec(std::vector<int> v) : sequence_(v) {}

/* Copy constructor */
PmergeVec::PmergeVec(PmergeVec const& src) { *this = src; }

/* Copy assignment operator */
PmergeVec& PmergeVec::operator=(PmergeVec const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
PmergeVec::~PmergeVec() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

/* make one dummy pair if nbr of elements in the sequence is odd */
void PmergeVec::addOddElement() {
  if (sequence_.size() % 2) {
    std::pair<int, int> odd(sequence_.back(), -1);
    pairs_.push_back(odd);
  }
}

void PmergeVec::makePairs() {
  for (PmergeVec::vecIt it = sequence_.begin(); it + 1 < sequence_.end(); it += 2) {
    std::pair<int, int> p = tools::makeSortedPair(*it, *(it + 1));
    pairs_.push_back(p);
  }
  addOddElement();
}

void PmergeVec::makeChains() {
  for (PmergeVec::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it) {
    AChain_.push_back(it->first);
    BChain.push_back(it->second);
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void PmergeVec::sort() {
  makePairs();
  pairs_ = tools::mergeSortPairs<PmergeVec::vecPairs>(pairs_);
  makeChains();
  MergeChains<std::vector<int> > m(&AChain_, &BChain);
  m.insertPending();
  printMainChain();
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

void PmergeVec::printMainChain() {
  std::cout << "AChain_: ";
  for (PmergeVec::vecIt it = AChain_.begin(); it != AChain_.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeVec::printPairs() {
  std::cout << "pairs_: ";
  for (PmergeVec::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it)
    std::cout << it->first << "/" << it->second << " ";
  std::cout << std::endl;
}
