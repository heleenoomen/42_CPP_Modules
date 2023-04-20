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
// #include <iostream>

class Insert {
  typedef std::vector<int>::iterator vecIt;
  typedef std::vector<std::pair<int, int> > pairVec;
  typedef pairVec::iterator pairsIt;

 private:
  int n_; /* nth element of Jacobsthal Sequence */
  int previousJacobsthalNb_; /* previous Jacobsthal Number */
  int JacobsthalNb_; /* current Jacobsthal Number */
  int nbPending_; /* number of elements pending */
  std::vector<int>* mainChain_;
  std::vector<int>* pend_;
  // pairVec* pairs_; /* vector of a-b pairs; a >= b for every pair & pairs are sorted based on a */
  int AShift_; /* in the beginning, every a in mainChain_ is at the same index as
  every b in pairs_. Everytime we insert an element in mainChain_, the index of the corresponding a
  shifts one place to the right in relation to the index of b */

  /* default constructor (inaccessible) */
  Insert();

  /* private methods */
  void insertNextJacobsthal();
  void insertSkipped();
  void insertInMainChain(int elementNbr);

 public:
  /* constructor */
  Insert(std::vector<int>* mainChain, std::vector<int>* pend);

  /* copy constructor */
  Insert(Insert const& src);

  /* copy assignment operator */
  Insert& operator=(Insert const& rhs);

  /* default destructor */
  ~Insert();

  /* public methods */
  void insertPending();

  /* debugging*/
  void printMainChain();
  void printPairs();
  void printClass();
};

#endif