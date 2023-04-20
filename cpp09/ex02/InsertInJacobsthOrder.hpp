/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Insert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/19 17:38:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_HPP
#define INSERT_HPP

#include <string>
#include <vector>
#include <utility>

#include "tools.hpp"

template<typename Container>
class Insert {
  typedef typename Container::iterator iterator;

 private:
  int n_; /* nth element of Jacobsthal Sequence */
  int prevJacobsthNb_; /* previous Jacobsthal Number */
  int JacobsthalNb_; /* current Jacobsthal Number */
  int nbPend_; /* number of elements pending */
  Container* mainChain_;
  Container* pend_;
  int AShift_; 

  /* default constructor (inaccessible) */
  Insert() : mainChain_(NULL), pend_(NULL) {}

  /* private methods */
  void insertNextJacobsthal() {
    prevJacobsthNb_ = JacobsthalNb_;
    JacobsthalNb_ = tools::Jacobsthal(++n_);
    insertInMainChain(JacobsthalNb_);
  }

  void insertSkipped() {
    for (int i = JacobsthalNb_ - 1; i > prevJacobsthNb_ && nbPend_; --i)
      insertInMainChain(i);
  }

  void insertInMainChain(int elementNbr) {
    if (static_cast<size_t>(elementNbr) > pend_->size()) return;
    int elemIndex = elementNbr - 1;
    int correspondingA = elemIndex + AShift_;
    int nbToInsert = pending_[elemIndex];
    iterator rangeBegin_ = mainChain_->begin();
    iterator rangeEnd_ = mainChain_->begin() + correspondingA;
    iterator pos = tools::binSearch<iterator>(nbToInsert, rangeBegin_, rangeEnd_);
    mainChain_->insert(pos, nbToInsert);
    --nbPend_;
    ++AShift_;
  }

 public:
  /* constructor */
  Insert(Container* mainChain, Container* pend)
    : n_(1),
      prevJacobsthNb_(0),
      JacobsthalNb_(0),
      nbPend_(mainChain->size()),
      mainChain_(mainChain),
      pend_(pend),
      AShift_(0) {}

  /* copy constructor */
  Insert(Insert const& src)
      : mainChain_(src.mainChain_), pend_(src.pend_) {
    *this = src;
  }

  /* copy assignment operator */
  Insert& operator=(Insert const& rhs) {
    if (this == &rhs) return *this;
    n_ = rhs.n_;
    prevJacobsthNb_ = rhs.prevJacobsthNb_;
    JacobsthalNb_ = rhs.JacobsthalNb_;
    nbPend_ = rhs.nbPend_;
    AShift_ = rhs.AShift_;
    return *this;
  }

  /* default destructor */
  ~Insert() {}

  /* public methods */
  void insertPending() {
    while (nbPend_) {
      insertNextJacobsthal();
      insertSkipped();
    }
  }
};

#endif