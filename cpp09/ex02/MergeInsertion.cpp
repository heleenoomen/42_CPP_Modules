
#include "MergeInsertion.hpp"

#include <iostream>
#include <utility>

#include "MergeChains.hpp"
#include "tools.hpp"

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
/* Private methods                                                            */
/* ************************************************************************** */

// /* make one dummy pair if nbr of elements in the sequence is odd */
// void MergeInsertion::addOddElement() {
//   if (sequence_.size() % 2) {
//     pairs_.push_back(std::make_pair(sequence_.back(), -1));
//   }
// }

void MergeInsertion::makePairs() {
  for (MergeInsertion::vecIt it = sequence_.begin(); it + 1 < sequence_.end();
       it += 2) {
    std::pair<int, int> p = std::make_pair(*it, *(it + 1));
    if (p.first < p.second) std::swap(p.first, p.second);
    pairs_.push_back(p);
  }
  if (sequence_.size() % 2)
    pairs_.push_back(std::make_pair(sequence_.back(), -1));
}

void MergeInsertion::makeChains() {
  for (MergeInsertion::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it) {
    AChain_.push_back(it->first);
    BChain_.push_back(it->second);
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void MergeInsertion::sort() {
  makePairs();
  pairs_ = tools::mergeSortPairs<MergeInsertion::vecPairs>(pairs_);
  makeChains();
  MergeChains<std::vector<int> > m(&AChain_, &BChain_);
  m.insertPending();
  printMainChain();
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

void MergeInsertion::printMainChain() {
  std::cout << "AChain_: ";
  for (MergeInsertion::vecIt it = AChain_.begin(); it != AChain_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void MergeInsertion::printPairs() {
  std::cout << "pairs_: ";
  for (MergeInsertion::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it)
    std::cout << it->first << "/" << it->second << " ";
  std::cout << std::endl;
}
