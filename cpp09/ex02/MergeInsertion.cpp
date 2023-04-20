
#include "MergeInsertion.hpp"

#include <iostream>
#include <utility>

#include "Insert.hpp"
#include "tools.hpp"
// #include "mergeSortPairs.hpp"

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

/* make one dummy pair if nbr of elements in the sequence is odd */
void MergeInsertion::addOddElement() {
  if (sequence_.size() % 2) {
    std::pair<int, int> odd(sequence_.back(), -1);
    pairs_.push_back(odd);
  }
}

void MergeInsertion::makePairs() {
  for (MergeInsertion::vecIt it = sequence_.begin(); it + 1 < sequence_.end(); it += 2) {
    std::pair<int, int> p = tools::makeSortedPair(*it, *(it + 1));
    pairs_.push_back(p);
  }
  addOddElement();
}

void MergeInsertion::makeChains() {
  for (MergeInsertion::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it) {
    mainChain_.push_back(it->first);
    pend_.push_back(it->second);
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void MergeInsertion::sort() {
  makePairs();
  pairs_ = tools::mergeSortPairs<MergeInsertion::vecPairs>(pairs_);
  makeChains();
  Insert<std::vector<int> > i(&mainChain_, &pend_);
  i.insertPending();
  printMainChain();
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

void MergeInsertion::printMainChain() {
  std::cout << "mainChain_: ";
  for (MergeInsertion::vecIt it = mainChain_.begin(); it != mainChain_.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void MergeInsertion::printPairs() {
  std::cout << "pairs_: ";
  for (MergeInsertion::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it)
    std::cout << it->first << "/" << it->second << " ";
  std::cout << std::endl;
}
