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

// #include <string>
// #include <iostream>
#include <vector>
#include <utility>

class MergeInsertion {
 private:
  std::vector<int> sequence_;
  std::vector<std::pair<int, int> > pairs_;
  std::vector<int> mainChain_;
  typedef std::vector<std::pair<int, int> > vecPairs;

  /* private methods*/
  MergeInsertion();
  void sortPair(std::pair<int, int>& p);
  void makePairs();
  vecPairs merge(vecPairs& p);
  vecPairs sortPairs(vecPairs& p);
  void makeMainChain();
  void insertPending();
  void insertOddElement();

 public:
  /* default constructor */
  MergeInsertion(std::vector<int> v);

  /* copy constructor */
  MergeInsertion(MergeInsertion const& src);

  /* copy assignment operator */
  MergeInsertion& operator=(MergeInsertion const& rhs);

  /* default destructor */
  ~MergeInsertion();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
  void sort();
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, MergeInsertion const& cname);

#endif