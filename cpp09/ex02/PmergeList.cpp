
#include "PmergeList.hpp"

#include <iostream>
#include <utility>

#include "MergeChains.hpp"
#include "tools.hpp"
// #include "mergeSortPairs.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
PmergeList::PmergeList() {}

/* Parametric contstructor */
PmergeList::PmergeList(std::list<int> v) : sequence_(v) {}

/* Copy constructor */
PmergeList::PmergeList(PmergeList const& src) { *this = src; }

/* Copy assignment operator */
PmergeList& PmergeList::operator=(PmergeList const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
PmergeList::~PmergeList() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

/* make one dummy pair if nbr of elements in the sequence is odd */
void PmergeList::addOddElement() {
  if (sequence_.size() % 2) {
    std::pair<int, int> odd(sequence_.back(), -1);
    pairs_.push_back(odd);
  }
}

void PmergeList::makePairs() {
  for (PmergeList::listIt it = sequence_.begin(); it + 1 < sequence_.end(); it += 2) {
    std::pair<int, int> p = tools::makeSortedPair(*it, *(it + 1));
    pairs_.push_back(p);
  }
  addOddElement();
}

void PmergeList::makeChains() {
  for (PmergeList::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it) {
    AChain_.push_back(it->first);
    BChain.push_back(it->second);
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void PmergeList::sort() {
  makePairs();
  pairs_ = tools::mergeSortPairs<PmergeList::listPairs>(pairs_);
  makeChains();
  MergeChains<std::list<int> > m(&AChain_, &BChain);
  m.insertPending();
  printMainChain();
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

void PmergeList::printMainChain() {
  std::cout << "AChain_: ";
  for (PmergeList::listIt it = AChain_.begin(); it != AChain_.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeList::printPairs() {
  std::cout << "pairs_: ";
  for (PmergeList::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it)
    std::cout << it->first << "/" << it->second << " ";
  std::cout << std::endl;
}
