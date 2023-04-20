/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVec.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEVEC_HPP
#define PMERGEVEC_HPP

#include <vector>
#include <utility>

class PmergeVec {
  /* typedefs */
  typedef std::vector<std::pair<int, int> > vecPairs;
  typedef vecPairs::iterator pairsIt;
  typedef std::vector<int>::iterator vecIt;

 private:
  /* private attributes */
  std::vector<int> sequence_;
  std::vector<std::pair<int, int> > pairs_;
  std::vector<int> AChain_;
  std::vector<int> BChain;

  /* default constructor (inaccessible) */
  PmergeVec();

  /* private methods */
  void addOddElement();
  void makePairs();
  void makeChains();

  /* debugging tools */
  void printPairs();
  void printMainChain();

 public:
  /* default constructor */
  PmergeVec(std::vector<int> v);

  /* copy constructor */
  PmergeVec(PmergeVec const& src);

  /* copy assignment operator */
  PmergeVec& operator=(PmergeVec const& rhs);

  /* default destructor */
  ~PmergeVec();

  /* public methods */
  void sort();
};

#endif