
#include "MergeInsertion.hpp"

#include <iostream>
#include <utility>

#include "Insert.hpp"
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

void MergeInsertion::sortPair(std::pair<int, int>& p) {
  if (p.first < p.second) {
    int swap = p.first;
    p.first = p.second;
    p.second = swap;
  }
}

void MergeInsertion::makePairs() {
  typedef std::vector<int>::iterator vectIt;
  std::pair<int, int> p;
  for (vectIt it = sequence_.begin(); it + 1 < sequence_.end(); it += 2) {
    p.first = *it;
    p.second = *(it + 1);
    sortPair(p);
    // std::cout << "Pair: " << p.first << " " << p.second << "\n";
    pairs_.push_back(p);
  }
  if (sequence_.size() % 2) { /* make one dummy pair if nbr of elems is odd */
    p.first = sequence_.back();
    p.second = -1;
    pairs_.push_back(p);
  }
}

MergeInsertion::vecPairs MergeInsertion::merge(vecPairs left, vecPairs right) {
  MergeInsertion::vecPairs sorted;
  while (left.size() && right.size()) {
    if (left.front().first < right.front().first) {
      sorted.push_back(left.front());
      left.erase(left.begin());
    } else {
      sorted.push_back(right.front());
      right.erase(right.begin());
    }
  }
  while (left.size()) {
    sorted.push_back(left.front());
    left.erase(left.begin());
  }
  while (right.size()) {
    sorted.push_back(right.front());
    right.erase(right.begin());
  }
  return sorted;
}

MergeInsertion::vecPairs MergeInsertion::sortPairs(vecPairs pairs) {
  if (pairs.size() == 1) return pairs;
  int mid = pairs.size() / 2;
  MergeInsertion::vecPairs left(pairs.begin(), pairs.begin() + mid);
  MergeInsertion::vecPairs right(pairs.begin() + mid, pairs.end());
  return merge(sortPairs(left), sortPairs(right));
}

void MergeInsertion::makeMainChain() {
  for (MergeInsertion::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it) {
    mainChain_.push_back((*it).first);
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void MergeInsertion::sort() {

  makePairs();
  // printPairs();
  pairs_ = sortPairs(pairs_);
  // printPairs();
  makeMainChain();
  // printMainChain();
  Insert i(&mainChain_, &pairs_);
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
