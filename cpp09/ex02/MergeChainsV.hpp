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
  Container* BChain_;
  
  /* Keep track of difference in index of each B in BChain_ and the
  corresponding A in AChain_ */
  int AShift_;

  /* Range in AChain_ where we perform binary search */
  range range_;

  /* default constructor (inaccessible) */
  MergeChains();

  /* insert the nth element of BChain_ in AChain_, where n is the next Jacobsthal
  number */
  void insertNextJacobsthal();
  void insertSkipped();
  int findNb(int elemNb);
  void setRange(int elemNb);
  void insertInMainChain(int elemNb);

 public:
  /* constructor */
  MergeChains(Container* mainChain, Container* pend);

  /* copy constructor */
  MergeChains(MergeChains const& src);

  /* copy assignment operator */
  MergeChains& operator=(MergeChains const& rhs);

  /* default destructor */
  ~MergeChains();

  /* public methods */
  void insertPending();
};

#endif