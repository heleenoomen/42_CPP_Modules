
#include "MergeInsertion.hpp"

#include <iostream>
#include <utility>

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
    std::cout << "Pair: " << p.first << " " << p.second << "\n";
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
  // pairs_.erase(pairs_.begin());
}

MergeInsertion::vecIt MergeInsertion::binSearch(int i,
                                                MergeInsertion::vecIt begin,
                                                MergeInsertion::vecIt end) {
  if (end - begin == 1) {
    if (i <= *begin) return begin;
    return end;
  }
  int mid = (end - begin) / 2;
  if (i <= *(begin + mid))
    return binSearch(i, begin, begin + mid);
  else
    return binSearch(i, begin + mid, end);
}

int MergeInsertion::insertInMainChain(int jacobsthal, int indexShift) {
  if (static_cast<size_t>(jacobsthal) > pairs_.size()) return 0;
  int index = jacobsthal - 1;
  int nbr = pairs_[index].second;
  MergeInsertion::vecIt pos = binSearch(nbr, mainChain_.begin(), mainChain_.begin() + index + indexShift );
  mainChain_.insert(pos, nbr);
  return 1;
}

void MergeInsertion::insertPending() {
  // for (MergeInsertion::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it) {
  //   int nbr = it->second;
  //   std::vector<int>::iterator pos = binSearch(nbr, mainChain_.begin(), mainChain_.end());
  //   mainChain_.insert(pos, nbr);
  // }
  // if (mainChain_.front() == -1) mainChain_.erase(mainChain_.begin());
  // int prevJacobsthal = 1;
  // int n = 4;
  // int leftToInsert = pairs_.size();
  // int endPosMainChain = 
  // while (leftToInsert) {
  //   int jacobsthal = tools::jacobsthal(n);
  //   if (jacobsthal < pairs_.size()) {
  //     MergeInsertion::vecIt pos = binSearch(pairs_[jacobsthal - 1].second, mainChain_.begin(), mainChain_.end());
  //     mainChain_.insert(pos, nbr);
  //   }
  //   for (int i = jacobsthal - 2; i > prevJacobsthal - 1; --i) {
  //     MergeInsertion::vecIt pos = binSearch(pairs_[i].second, mainChain_.begin(), mainChain_.end());
  //     mainChain_.insert(pos, pairs_[i]);
  //   }
  // }
  mainChain_.insert(mainChain_.begin(), pairs_.front().second);
  int previousJacobsthal = 1; // the 3th element of the Jacobsthal sequence is 1
  int n = 4; // we start at the 4th. element of the Jacobsthal sequence
  int leftToInsert = pairs_.size();
  int indexShift = 1;
  while (leftToInsert) {
    int jacobsthal = tools::Jacobsthal(n);
    leftToInsert = insertInMainChain(jacobsthal); // -1 to get the index
    for (int i = jacobsthal; i > previousJacobsthal; --i)
      leftToInsert = insertInMainChain(i); // -1 to get the index
    previousJacobsthal = jacobsthal;
    ++n;
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
  insertPending();
  printMainChain();
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// std::ostream& operator<<(std::ostream& o, MergeInsertion const& cname) {
//   o << "\033[0;32m"
//     // << some info here
//     << "\033[0m";
//   return o;
// }

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
