/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <utility>
#include <vector>

#include "mergeAB.hpp"
#include "pme.hpp"

/* PmergeMe template
 * Carry out Merge Insertion Sort / Ford-Johnson Algorithm on a list of
 * unsorted, positive integers. To do this, carry out the following steps:
 *  1) Group arguments into pairs of integers:
 *      {argv[1], argv[2]}, {argv[3],argv[4]}, etc.
 *  2) For every pair, make sure that first >= second.
 *  3) Store the pairs in a container of pairs of integers.
 *  4) Sort the pairs in this container based on the first element, using merge
 *    sort.
 *  5) Split the container into two containers of integers:
 *        AChain_ will contain all first elements and will thus be sorted.
 *        BChain_ will contain all second elements and will be unsorted.
 *  6) Merge BChain_ into AChain_, using the Jacobsthal sequence to decide which
 *    of the Bs in BChain_ to insert next.
 */

template <typename Cont, typename ContPairs>
class PmergeMe {
 private:
  ContPairs pairs_;
  Cont AChain_;
  Cont BChain_;
  int argc_;
  char** argv_;

  /* Group the input arguments into pairs of integers:
      {argv[1], argv[2]}, {argv[3], argv[4]}, etc.
  Sort each pair so that first >= second.
  Store the pairs in the pairs_ container.
  If the number of arguments is odd, add a dummy pair consisting of the last
  argument and -1.
  Use pme::stoi to convert c-strings to integers. It will throw
  an exception if the input is not a positive integer. */
  void groupIntoPairs() {
    for (int i = 1; i + 1 < argc_; i += 2) {
      std::pair<int, int> p =
          std::make_pair(pme::stoi(argv_[i]), pme::stoi(argv_[i + 1]));
      if (p.first < p.second) std::swap(p.first, p.second);
      pairs_.push_back(p);
    }
    if (!(argc_ % 2))
      pairs_.push_back(std::make_pair(pme::stoi(argv_[argc_ - 1]), -1));
  }

  /* sort all pairs in the container based on the first element of each pair.
   * Call pme::sortPairs() to carry out a recursive merge sort with iterators.
   * Preallocate a big enough temporary container for the sorting. */
  void sortPairsByFirstElem() {
    ContPairs tmp(pairs_.size());
    pme::sortPairs(pairs_.begin(), pairs_.end(), tmp.begin());
  }

  /* Split the sorted container of pairs into two seperate containers of
  integers: AChain_, which will contain the first (biggest) element of each pair
  and will be fully sorted, and BChain_, which will contain the second
  (smallest) element of each pair and will not be sorted. The pairs will now
  exist at the same index of their respective chains, so
  that for every index i, BChain[i] <= AChain[i] */
  void makeChains() {
    for (typename ContPairs::iterator it = pairs_.begin(); it != pairs_.end();
         ++it) {
      AChain_.push_back(it->first);
      BChain_.push_back(it->second);
    }
  }

  /* merge BChain into AChain with the help of MergeAB */
  void mergeChains() {
    MergeAB<Cont> m(&AChain_, &BChain_);
    m.insertPending();
  }

  /* After BChain_ is merged into AChain_, check for the -1 dummy at the front
   * of AChain_ and remove it if existing. */
  void rmDummy() {
    if (AChain_.front() == -1) AChain_.erase(AChain_.begin());
  }

  /* Default constructor (inaccessible) */
  PmergeMe() {}

 public:
  PmergeMe(int argc, char** argv) : argc_(argc), argv_(argv) {}

  PmergeMe(PmergeMe const& src) { *this = src; }

  PmergeMe& operator=(PmergeMe const& rhs) {
    if (this == &rhs) return *this;
    pairs_ = rhs.pairs_;
    AChain_ = rhs.AChain_;
    BChain_ = rhs.BChain_;
    argc_ = rhs.argc_;
    argv_ = rhs.argv_;
    return *this;
  }

  ~PmergeMe() {}

  void run() {
    groupIntoPairs();
    sortPairsByFirstElem();
    makeChains();
    mergeChains();
    rmDummy();
    // printAChain();
  }

  void printAChain() {
    for (typename Cont::iterator it = AChain_.begin(); it != AChain_.end();
         ++it)
      std::cout << *it << " ";
  }
};

#endif