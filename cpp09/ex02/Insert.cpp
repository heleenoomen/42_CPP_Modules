
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
      rangeBegin_(mainChain.begin()),
      rangeEnd_(mainChain.begin() + 1) {}

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
  rangeBegin_ = rhs.rangeBegin_;
  rangeEnd_ = rhs.rangeEnd_;
  return *this;
}

/* Destructor */
Insert::~Insert() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Insert::insertInMainChain(int elementNbr) {
  int elemIndex = elementNbr - 1;
  Insert::vecIt pos = binSearch(elemIndex, rangeBegin_, rangeEnd_);
  mainChain_.insert(pos, elementNbr);
  nbPending_--;
}

void Insert::insertNonJacobsthal(int element) {
  if (static_cast<size_t>(elementNbr) > pairs_.size()) return;
  insertInMainChain(element);
  ++addedNonJacobsthal_;
}

void Insert::insertJacobsthal(int element) {
  if (static_cast<size_t>(elementNbr) > pairs_.size()) return;
  insertInMainChain(element);
  ++rangeEnd_;
}

/*
1) insert the pending element with the the next Jacobsthal number.
2) Add the pending elements between the Jacobsthal and the previous Jacobsthal
in descending order.
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>> The pending elements will thus be inserted as follows:        <<<
>>> *1, *3, 2, *5, 4, *11, 10, 9, 8, 7, 6, *21, 20, 19, 18, etc.  <<<
>>> (The nbrs marked with asterisk belong to Jacobsthal sequence) <<<
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
3) Move the pointer to the next a-nbr accordingly after every insertion
*/
void Insert::insertPending() {
  while (nbPending_) {
    JacobsthalNb_ = tools::Jacobsthal(n_);
    n_++;
    insertInMainChain(JacobsthalNb_);
    for (int i = JacobsthalNb_ - 1; i > previousJacobsthalNb_ && nbPending_; --i)
      insertInMainChain(i);
    rangeEnd_ += addedNonJacobsthal_;
    addedNonJacobsthal_ = 0;
  }
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// std::ostream& operator<<(std::ostream& o, Insert const& cname) {
//   o << "\033[0;32m"
//     // << some info here
//     << "\033[0m";
//   return o;
// }
