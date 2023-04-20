/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertion.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERTION_HPP
#define MERGEINSERTION_HPP

#include <vector>
#include <utility>

class MergeInsertion {
  /* typedefs */
  typedef std::vector<std::pair<int, int> > vecPairs;
  typedef vecPairs::iterator pairsIt;
  typedef std::vector<int>::iterator vecIt;

 private:
  /* private attributes */
  std::vector<int> sequence_;
  std::vector<std::pair<int, int> > pairs_;
  std::vector<int> AChain_;
  std::vector<int> BChain_;

  /* default constructor (inaccessible) */
  MergeInsertion();

  /* private methods */
  void addOddElement();
  void makePairs();
  void makeChains();

  /* debugging tools */
  void printPairs();
  void printMainChain();

 public:
  /* default constructor */
  MergeInsertion(std::vector<int> v);

  /* copy constructor */
  MergeInsertion(MergeInsertion const& src);

  /* copy assignment operator */
  MergeInsertion& operator=(MergeInsertion const& rhs);

  /* default destructor */
  ~MergeInsertion();

  /* public methods */
  void sort();
};

#endif