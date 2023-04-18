
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

void MergeInsertion::sortPair(std::pair<int, int>& p) {
    if (p.first < p.second) {
      int swap = p.first;
      p.first = p.second;
      p.second = swap;
    }
}

void MergeInsertion::makePairs() {
  typedef std::vector<int>::iterator vectIt;
  for (vectIt it = sequence_.begin(); it + 1 != sequence_.end(); ++it) {
    std::pair<int, int> p;
    p.first = *it;
    p.second = *(it + 1);
    sortPair(p);
    pairs_.push_back(p);
  }
  if (sequence_.size() % 2) {
    p.first = sequence_.back();
    p.second = -1;
    pairs_.push_back(p);
  }
}

vecPairs MergeInsertion::merge(vecPairs& left, vecPairs& right) {
  vecPairs sorted;
  while (left.size() && right.size()) {
    if (left.front().first < right.front().first) {
      sorted.push_back(left.front());
      left.erarse(left.begin());
    } else {
      sorted.push_back(right.front());
      sorted.erase(right.begin());
    }
  }
  while (left.size()) {
    sorted.push_back(left[0]);
    left.erase(left[0]);
  }
  while (right.size()) {
    sorted.push_back(right[0]);
    right.erase(right[0]);
  }
  return sorted;
}

vecPairs MergeInsertion::sortPairs(vecPairs& pairs) {
  if (vecPairs.size() == 1)
    return vecPairs;
  int mid = pairs.size / 2;
  vecPairs left(v.begin(), v.begin + mid);
  vecPairs right(v.begin() + mid, v.end());
  return merge(sortPairs(left), sortPairs(right));
}

void MergeInsertion::makeMainChain() {
  vecPairs sorted = sortPairs(pairs_);
  typedef vecPairs::iterator pairsIt;
  for (pairsIt it = sorted.begin(); it != sorted.end(); ++it) {
    
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
