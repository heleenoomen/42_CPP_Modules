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

#include "chainMe.hpp"
#include "pme.hpp"

template <typename Cont, typename ContPairs>
class PmergeMe {
 private:
  ContPairs pairs_;
  Cont AChain_;
  Cont BChain_;

  void makeChains() {
    for (typename ContPairs::iterator it = pairs_.begin(); it != pairs_.end();
         ++it) {
      AChain_.push_back(it->first);
      BChain_.push_back(it->second);
    }
  }

  void sortPairsByFirstElem() {
    ContPairs tmp(pairs_.size());
    pme::sortPairs(pairs_.begin(), pairs_.end(), tmp.begin());
  }

  void mergeChains() {
    chainMe<Cont> m(&AChain_, &BChain_);
    m.insertPending();
  }

  void rmDummy() {
    if (AChain_.front() == -1) AChain_.erase(AChain_.begin());
  }

 public:
  /* default constructor */
  PmergeMe() {}

  /* parametric constructor */
  /* Make a container of pairs of integers out of the input arguments in argv.
  Every pair consists of argv[n] and argv[n + 1]. Every pair is sorted
  immediately, so that first >= second. If the number of arguments in argv is
  odd, a dummy pair is added, consisting of the last argument in argv and -1.
  Since our program only handles sequences of positive numbers, we use -1 as a
  dummy. pme::strtoi converts string to integer and throws an exception if the
  argument is not a number or if the number obtained is negative.
   */
  PmergeMe(int argc, char** argv) {
    for (int i = 1; i + 1 < argc; i += 2) {
      std::pair<int, int> p =
          std::make_pair(pme::stoi(argv[i]), pme::stoi(argv[i + 1]));
      if (p.first < p.second) std::swap(p.first, p.second);
      pairs_.push_back(p);
    }
    if (!(argc % 2))
      pairs_.push_back(std::make_pair(pme::stoi(argv[argc - 1]), -1));
  }

  /* copy constructor */
  PmergeMe(PmergeMe const& src) { *this = src; }

  /* copy assignment operator */
  PmergeMe& operator=(PmergeMe const& rhs) {
    if (this == &rhs) return *this;
    pairs_ = rhs.pairs_;
    AChain_ = rhs.AChain_;
    BChain_ = rhs.BChain_;
    return *this;
  }

  /* destructor */
  ~PmergeMe() {}

  /* public methods */
  void run() {
    sortPairsByFirstElem();
    makeChains();
    mergeChains();
    rmDummy();
    printAChain();
  }

  // void printPairs() {
  //   for (typename ContPairs::iterator it = pairs_.begin(); it !=
  //   pairs_.end();
  //        ++it)
  //     std::cout << it->first << "/" << it->second << "\n";
  // }

  // void printPair(std::pair<int, int>& p) {
  //   std::cout << "Pair: " << p.first << ", " << p.second << '\n';
  // }

  void printAChain() {
    for (typename Cont::iterator it = AChain_.begin(); it != AChain_.end();
         ++it)
      std::cout << *it << " ";
    std::cout << "\n";
  }
};

#endif