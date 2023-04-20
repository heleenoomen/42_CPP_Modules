
#include "Insert.hpp"

#include <iostream>

#include "tools.hpp"
// #include "binaryInsertion.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
// template<typename Container>
// Insert::Insert() {}

// /* Parametric constructor */
// template<typename Container>
// Insert::Insert(Container* mainChain, Container* pend)
//     : n_(1),
//       previousJacobsthalNb_(0),
//       JacobsthalNb_(0),
//       nbPending_(mainChain->size()),
//       mainChain_(mainChain),
//       pend_(pend),
//       AShift_(0) {}

/* Copy constructor */
// Insert::Insert(Insert const& src)
//     : mainChain_(src.mainChain_), pend_(src.pend_) {
//   *this = src;
// }

/* Copy assignment operator */
// Insert& Insert::operator=(Insert const& rhs) {
//   if (this == &rhs) return *this;
//   n_ = rhs.n_;
//   previousJacobsthalNb_ = rhs.previousJacobsthalNb_;
//   JacobsthalNb_ = rhs.JacobsthalNb_;
//   nbPending_ = rhs.nbPending_;
//   AShift_ = rhs.AShift_;
//   return *this;
// }

/* Destructor */
// Insert::~Insert() {}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

// void Insert::insertInMainChain(int elementNbr) {
//   if (static_cast<size_t>(elementNbr) > pend_->size()) return;
//   int elemIndex = elementNbr - 1; /* get the index based of the nth element of pending_ */
//   int correspondingA = elemIndex + AShift_; /* get the corresponding element in main_ */
  
//   Container::iterator pos =
//       tools::binSearch<Container::iterator>((*pend_)[elemIndex], mainChain_->begin(),
//                 mainChain_->begin() + correspondingA);
//   mainChain_->insert(pos, (*pend_)[elemIndex]);
//   --nbPending_;
//   ++AShift_;
// }

// void Insert::insertSkipped() {
//   for (int i = JacobsthalNb_ - 1; i > previousJacobsthalNb_ && nbPending_; --i)
//     insertInMainChain(i);
// }

// void Insert::insertNextJacobsthal() {
//   previousJacobsthalNb_ = JacobsthalNb_;
//   JacobsthalNb_ = tools::Jacobsthal(++n_);
//   insertInMainChain(JacobsthalNb_);
// }

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

// void Insert::insertPending() {
//   while (nbPending_) {
//     insertNextJacobsthal();
//     insertSkipped();
//   }
// }

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// void Insert::printMainChain() {
//   std::cout << "mainChain =\t\t";
//   for (Insert::vecIt it = mainChain_->begin(); it != mainChain_->end(); ++it)
//     std::cout << *it << " ";
//   std::cout << std::endl;
// }

// void Insert::printClass() {
//   std::cout << "-----------------------------------\n";
//   std::cout << "n_=\t\t\t" << n_ << '\n';
//   std::cout << "previousJacobsthal_ =\t" << previousJacobsthalNb_ << '\n';
//   std::cout << "Jacobsthal=\t\t" << JacobsthalNb_ << '\n';
//   std::cout << "nbPending_ =\t\t" << nbPending_ << '\n';
//   printMainChain();
//   // printPairs();
//   std::cout << "AShift_ =\t\t" << AShift_ << '\n';
//   std::cout << "-----------------------------------\n";
//   std::cout << std::endl;
// }
