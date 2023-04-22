/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainMe.hpp                                        :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/19 17:38:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINME_HPP
#define CHAINME_HPP

#include "pme.hpp"

/* We have already made two containers of integers:
    AChain_ -> contains all A numbers, sorted
    BChain_ -> contains all B numbers, unsorted

    Goal is to merge BChain_ into AChain_ so that we obtain one sorted
    container of integers, AChain_.

    Both chains are so build that, at the start, for every index i, AChain_[i]
   forms a pair with BChain_[i] so that AChain_[i] >= BChain_[i]

    We merge the two chains by inserting elements from BChain_ into AChain_.
    We know that every B is smaller than or equal to its corresponding A, so
    that BChain_[i] should be inserted somewhere in the range AChain_[0] -
   AChain_[i].

    However, as we insert, the index of all following As shift
    to the right, so that for the nth element we insert:
      BChain_[i] corresponds to AChain_[i + n]
    We store n in the parameter AShift_.

    We insert in the following order:
      * insert nth element of BChain_, where n is the next number in the
        Jacobsthal sequence
      * insert the skipped elements (between the current Jacobsthal number
   and the previous Jacobsthal number) in descending order. The order of
   insertion will thus be like this: *1, *3, 2, *5, 4, *11, 10, 9, 8, 7, 6, *21,
   20, 19, 18, 17, etc. (numbers marked with a * belong to the Jacobsthal
   sequence)
*/

template <typename Container>
class chainMe {
  typedef typename Container::iterator iterator;
  typedef struct range {
    iterator min;
    iterator max;
  } range;

 public:
  /* public methods */
  /* as long as there are elements pending, insert first the nth number of
  BChain_ where n is the next Jaconbsthal number. Then insert the skipped
  elements between the current Jacobsthal number and the previous Jacobsthal
  number, so that the order of insertion is: *1, *3, 2, *5, 4, *11, 10, 9, 8,
  etc. (As described at the top of this file)*/
  void insertPending() {
    while (nbPend_) {
      insertNextJacobsthal();
      insertSkipped();
    }
  }

  /* constructor */
  chainMe(Container* mainChain, Container* pend)
      : AChain_(mainChain),
        BChain_(pend),
        n_(1),
        prevJacobsth_(0),
        jacobsth_(0),
        nbPend_(mainChain->size()),
        AShift_(0) {}

  /* copy constructor */
  chainMe(chainMe const& src) : AChain_(src.AChain_), BChain_(src.BChain_) {
    *this = src;
  }

  /* copy assignment operator */
  chainMe& operator=(chainMe const& rhs) {
    if (this == &rhs) return *this;
    n_ = rhs.n_;
    prevJacobsth_ = rhs.prevJacobsth_;
    jacobsth_ = rhs.jacobsth_;
    nbPend_ = rhs.nbPend_;
    AShift_ = rhs.AShift_;
    return *this;
  }

  /* destructor */
  ~chainMe() {}

 private:
  /* Chains of integers */
  Container* AChain_;
  Container* BChain_;

  /* nth element of Jacobsthal Sequence */
  int n_;

  /* previous Jacobsthal Number */
  int prevJacobsth_;

  /* current Jacobsthal Number */
  int jacobsth_;

  /* number of elements pending */
  int nbPend_;

  /* Keep track of difference in index of each B in BChain_ and the
  corresponding A in AChain */
  int AShift_;

  /* Range in AChain where we perform binary search */
  range range_;

  /* default constructor (inaccessible) */
  chainMe() : AChain_(NULL), BChain_(NULL) {}

  /* insert the nth element of BChain_ in AChain, where n is the next Jacobsthal
  number */
  void insertNextJacobsthal() {
    prevJacobsth_ = jacobsth_;
    jacobsth_ = pme::Jacobsthal(++n_);
    insertInMainChain(jacobsth_);
  }

  /* insert the skipped elements in BChain_, i.e. the elements n ... m, where
  n is the current Jacobsthal number and m the previous Jacobsthal number */
  void insertSkipped() {
    for (int i = jacobsth_ - 1; i > prevJacobsth_ && nbPend_; --i)
      insertInMainChain(i);
  }

  /* find the B Number for the nth element in BChain_ */
  int findNb(int elemNb) {
    int indexB = elemNb - 1;
    iterator it = BChain_->begin();
    std::advance(it, indexB);
    return *it;
  }

  /* set the Range for binary search in AChain to insert the next element
  from B */
  void setRange(int elemNb) {
    int indexB = elemNb - 1;
    int indexA = indexB + AShift_;
    range_.min = AChain_->begin();
    range_.max = AChain_->begin();
    std::advance(range_.max, indexA);
  }

  /* insert the nth element of B into A. First find the number to insert,
  find the range where to perform binary search, perform binary search and
  insert the number. Update the number of pending elemens & the AShift_ */
  void insertInMainChain(int elemNb) {
    if (static_cast<size_t>(elemNb) > BChain_->size()) return;
    int bNb = findNb(elemNb);
    setRange(elemNb);
    iterator pos = pme::binSearch<iterator>(bNb, range_.min, range_.max);
    AChain_->insert(pos, bNb);
    --nbPend_;
    ++AShift_;
  }
};

#endif