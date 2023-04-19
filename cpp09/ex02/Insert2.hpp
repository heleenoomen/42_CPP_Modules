/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Insert2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/19 17:30:32 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_HPP
#define INSERT_HPP

#include <string>
#include <vector>
#include <utility>
// #include <iostream>

class Insert2 {
  typedef std::vector<int>::iterator vecIt;
  typedef std::vector<std::pair<int, int> > pairVec;
  typedef pairVec::iterator pairsIt;

 private:
  static int const jacobsThalStartAt = 2;
  int n_; /* nth element of Jacobsthal Sequence */
  int previousJacobsthalNb_; /* previous Jacobsthal Number */
  int JacobsthalNb_; /* current Jacobsthal Number */
  int nbPending_; /* number of elements pending */
  std::vector<int>* mainChain_;
  pairVec* pairs_; /* vector of a-b pairs; a >= b for every pair & pairs are sorted based on a */
  int AShift_;

  void insertNextJacobsthal();
  void insertSkipped();

 public:
  /* default constructor */
  Insert2();
  /* constructor */
  Insert2(std::vector<int>* mainChain, pairVec* pairs);
  // Insert2();
  vecIt binSearch(int i, vecIt begin, vecIt end);
  void insertPending();
  void insertInMainChain(int elementNbr);
  void printMainChain();
  void printPairs();

  /* copy constructor */
  Insert2(Insert2 const& src);

  /* copy assignment operator */
  Insert2& operator=(Insert2 const& rhs);

  /* default destructor */
  ~Insert2();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
  void printClass();
};

/* insertion operator */
std::ostream& operator<<(std::ostream& o, Insert2 const& cname);

#endif