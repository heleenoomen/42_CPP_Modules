
#include "Insert.hpp"

#include <iostream>

#include "tools.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
// Insert::Insert() {}

/* Parametric constructor */
Insert::Insert(std::vector<int>& mainChain, Insert::pairVec& pairs)
    : n_(jacobsThalStartAt),
      addedNonJacobsthal_(0),
      previousJacobsthalNb_(1),
      JacobsthalNb_(0),
      nbPending_(mainChain.size()),
      mainChain_(mainChain),
      pairs_(pairs),
      indexNextA(0) {}

/* Copy constructor */
Insert::Insert(Insert const& src)
    : mainChain_(src.mainChain_),
      pairs_(src.pairs_) {
  *this = src;
}

/* Copy assignment operator */
Insert& Insert::operator=(Insert const& rhs) {
  if (this == &rhs) return *this;
  n_ = rhs.n_;
  previousJacobsthalNb_ = rhs.previousJacobsthalNb_;
  JacobsthalNb_ = rhs.JacobsthalNb_;
  nbPending_ = rhs.nbPending_;
  indexNextA = rhs.indexNextA;
  return *this;
}

/* Destructor */
Insert::~Insert() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

Insert::vecIt Insert::binSearch(int i, Insert::vecIt begin, Insert::vecIt end) {
  if (end - begin == 1) {
    if (i <= *begin) return begin;
    return end;
  }
  if (end == begin) return begin;
  int mid = (end - begin) / 2;
  if (i <= *(begin + mid))
    return binSearch(i, begin, begin + mid);
  else
    return binSearch(i, begin + mid, end);
}

void Insert::insertInMainChain(int elementNbr) {
  int elemIndex = elementNbr - 1;
  // std::cout << "Insert pairs_[" << elemIndex << "] = " << pairs_[elemIndex].second << "\n";
  // std::cout << "mainChain_.begin() = " << *(mainChain_.begin()) << std::endl;
  // std::cout << "mainChain_.begin() + nextA = " << *(mainChain_.begin() + indexNextA) << std::endl;
  Insert::vecIt pos = binSearch(pairs_[elemIndex].second, mainChain_.begin(), mainChain_.begin() + indexNextA);
  // std::cout << "pos = " << pos - mainChain_.begin() << "\n";
  mainChain_.insert(pos, pairs_[elemIndex].second);
  nbPending_--;
}

void Insert::insertNonJacobsthal(int element) {
  // std::cout << "INSERT NON JT\n";
  if (static_cast<size_t>(element) > pairs_.size()) return;
  insertInMainChain(element);
  // ++addedNonJacobsthal_;
  indexNextA++;
}

void Insert::insertJacobsthal(int element) {
  // std::cout << "INSERT JT\n";
  // printClass();
  if (static_cast<size_t>(element) > pairs_.size()) return;
  insertInMainChain(element);
  ++indexNextA;
}


/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

/*
1) insert the pending element with the the next Jacobsthal number.
2) Add the pending elements between the Jacobsthal and the previous Jacobsthal
in descending order.
   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
   >>> The pending elements will thus be inserted as follows:        <<<
   >>> *1, *3, 2, *5, 4, *11, 10, 9, 8, 7, 6, *21, 20, 19, 18, etc.  <<<
   >>> (The nbrs marked with asterisk belong to Jacobsthal sequence) <<<
   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/
void Insert::insertPending() {
  while (nbPending_) {
    JacobsthalNb_ = tools::Jacobsthal(n_);
    n_++;
    insertJacobsthal(JacobsthalNb_);
    for (int i = JacobsthalNb_ - 1; i > previousJacobsthalNb_ && nbPending_; --i)
      insertNonJacobsthal(i);
    //indexNextA += addedNonJacobsthal_;
    //addedNonJacobsthal_ = 0;
    previousJacobsthalNb_ = JacobsthalNb_;
    ++indexNextA;
  }
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

void Insert::printMainChain() {
  std::cout << "mainChain =\t\t";
  for (Insert::vecIt it = mainChain_.begin(); it != mainChain_.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void Insert::printPairs() {
  std::cout << "pairs =\t\t\t";
  for (Insert::pairsIt it = pairs_.begin(); it != pairs_.end(); ++it)
    std::cout << it->first << "/" << it->second << " ";
  std::cout << std::endl;
}

void Insert::printClass() {
  std::cout << "-----------------------------------\n";
  std::cout << "n_=\t\t\t" << n_ << '\n';
  std::cout << "addedNonJacobsthal_ =\t" << addedNonJacobsthal_ << '\n';
  std::cout << "previousJacobsthal_ =\t" << previousJacobsthalNb_ << '\n';
  std::cout << "Jacobsthal=\t\t" << JacobsthalNb_ << '\n';
  std::cout << "nbPending_ =\t\t" << nbPending_ << '\n';
  printMainChain();
  printPairs();
  std::cout << "index next a =\t\t" << indexNextA << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << std::endl;
}
