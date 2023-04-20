/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeChains.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/19 17:38:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGECHAINS_HPP
#define MERGECHAINS_HPP

#include "tools.hpp"

/* We have two containers of integers:
    AChain_ -> contains all A numbers, sorted
    BChain_ -> contains all B numbers, unsorted 
    
    At the start, for every index i, AChain_[i] forms a pair with BChain[i] so
    that AChain_[i] >= BChain[i]

    We merge the two chains by inserting elements from BChain into AChain.
    We know that every B is smaller or equal than its corresponding A, so that
    BChain[i] should be inserted somewhere in the range AChain_[0] - AChain_[i]

    However, as we go inserting, the index where the corresponding A is, shifts 
    to the right, so that for the nth element we insert:
      BChain_[i] corresponds to AChain_[i + n]
    We store n in the parameter AShift_.

    We insert in the following order:
      * insert nth element of BChain, where n is the next number in the
        Jacobsthal sequenc
      * insert the skipped elements in descending order.
    The order of insertion will thus look like this:
      *1, *3, 2, *5, 4, *11, 10, 9, 8, 7, 6, *21, 20, 19, 18, 17, etc.
    (the numbers marked with a * are part of the Jacobsthal sequence) 
*/

template<typename Container>
class MergeChains {
  typedef typename Container::iterator iterator;
  typedef struct range {
    iterator min;
    iterator max;
  } range;

 private:
  /* nth element of Jacobsthal Sequence */
  int n_;

  /* previous Jacobsthal Number */
  int prevJacobsthNb_;

  /* current Jacobsthal Number */
  int JacobsthalNb_;

  /* number of elements pending */
  int nbPend_;

  /* Chains of integers */
  Container* AChain_;
  Container* BChain;
  
  /* Keep track of difference in index of each B in BChain and the
  corresponding A in AChain */
  int AShift_;

  /* Range in AChain where we perform binary search */
  range range_;

  /* default constructor (inaccessible) */
  MergeChains() : AChain_(NULL), BChain(NULL) {}

  /* insert the nth element of BChain in AChain, where n is the next Jacobsthal
  number */
  void insertNextJacobsthal() {
    prevJacobsthNb_ = JacobsthalNb_;
    JacobsthalNb_ = tools::Jacobsthal(++n_);
    insertInMainChain(JacobsthalNb_);
  }

  /* insert the skipped elements in BChain, i.e. the elements n ... m, where
  n is the current Jacobsthal number and m the previous Jacobsthal number */
  void insertSkipped() {
    for (int i = JacobsthalNb_ - 1; i > prevJacobsthNb_ && nbPend_; --i)
      insertInMainChain(i);
  }

  /* find the B Number for the nth element in BChain, where n is the next
  Jacobsthal number*/
  int findNb(int elemNb) {
    int indexB = elemNb - 1;
    return (*BChain)[indexB];
  }

  /* set the Range for binary search in AChain for inserting the next element
  from B */
  void setRange(int elemNb) {
    int indexB = elemNb - 1;
    int indexA = indexB + AShift_;
    range_.min = AChain_->begin();
    range_.max = AChain_->begin() + indexA;
  }

  void insertInMainChain(int elemNb) {
    if (static_cast<size_t>(elemNb) > BChain->size()) return;
    int bNb = findNb(elemNb);
    setRange(elemNb);
    iterator pos = tools::binSearch<iterator>(bNb, range_.min, range_.max);
    AChain_->insert(pos, bNb);
    --nbPend_;
    ++AShift_;
  }

 public:
  /* constructor */
  MergeChains(Container* mainChain, Container* pend)
    : n_(1),
      prevJacobsthNb_(0),
      JacobsthalNb_(0),
      nbPend_(mainChain->size()),
      AChain_(mainChain),
      BChain(pend),
      AShift_(0) {}

  /* copy constructor */
  MergeChains(MergeChains const& src)
      : AChain_(src.AChain_), BChain(src.BChain) {
    *this = src;
  }
  /* copy assignment operator */
  MergeChains& operator=(MergeChains const& rhs) {
    if (this == &rhs) return *this;
    n_ = rhs.n_;
    prevJacobsthNb_ = rhs.prevJacobsthNb_;
    JacobsthalNb_ = rhs.JacobsthalNb_;
    nbPend_ = rhs.nbPend_;
    AShift_ = rhs.AShift_;
    return *this;
  }
  /* default destructor */
  ~MergeChains() {}

  /* public methods */
  void insertPending() {
    while (nbPend_) {
      insertNextJacobsthal();
      insertSkipped();
    }
  }
};

#endif