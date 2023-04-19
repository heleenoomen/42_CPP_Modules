
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
  if (static_cast<size_t>(elementNbr) > pairs_.size()) return;
  int elemIndex = elementNbr - 1;
  Insert::vecIt pos = binSearch(elemIndex, rangeBegin_, rangeEnd_);
  mainChain_.insert(pos, elementNbr);
  rangeEnd_++;
  nbPending_--;
}

/* insert the pending element with the the next Jacobsthal number. Then add the
pending elements between the Jacobsthal and the previous Jacobsthal in
descending order, so that the pending elements will be inserted as follows:
*1, *3, 2, *5, 4, *11, 10, 9, 8, 7, 6, *21, 20, 19, 18, etc. */
void Insert::insertPending() {
  while (nbPending_) {
    JacobsthalNb_ = tools::Jacobsthal(n_);
    n_++;
    insertInMainChain(JacobsthalNb_);
    for (int i = JacobsthalNb_ - 1; i > previousJacobsthalNb_; --i)
      insertInMainChain(i);
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
