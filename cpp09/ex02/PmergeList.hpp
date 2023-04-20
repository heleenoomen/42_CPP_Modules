/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGELIST_HPP
#define PMERGELIST_HPP

#include <list>
#include <utility>

class PmergeList {
  /* typedefs */
  typedef std::list<std::pair<int, int> > listPairs;
  typedef listPairs::iterator pairsIt;
  typedef std::list<int>::iterator listIt;

 private:
  /* private attributes */
  std::list<int> sequence_;
  std::list<std::pair<int, int> > pairs_;
  std::list<int> AChain_;
  std::list<int> BChain;

  /* default constructor (inaccessible) */
  PmergeList();

  /* private methods */
  void addOddElement();
  void makePairs();
  void makeChains();

  /* debugging tools */
  void printPairs();
  void printMainChain();

 public:
  /* default constructor */
  PmergeList(std::list<int> v);

  /* copy constructor */
  PmergeList(PmergeList const& src);

  /* copy assignment operator */
  PmergeList& operator=(PmergeList const& rhs);

  /* default destructor */
  ~PmergeList();

  /* public methods */
  void sort();
};

#endif