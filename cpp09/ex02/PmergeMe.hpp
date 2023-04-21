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
  PmergeMe(char** argv) {
    for (++argv; argv + 1 != NULL; argv += 2) {
      std::pair<int, int> p =
          std::make_pair(pme::strtoi(argv), pme::strtoi(argv + 1));
      if (p.first < p.second) std::swap(p.first, p.second);
      pairs_.pushback(p);
    }
    if (argv != NULL) pairs_.pushback(std::make_pair(pme::strtoi(argv), -1));
  }

  void makeChains() {
    for (ContPairs::iterator it = pairs_.begin(); it != pairs_.end(); ++it) {
      AChain_.push_back(it->first);
      BChain_.push_back(it->second);
    }
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

  /* default destructor */
  ~PmergeMe();

  /* public methods */
  void run() {
    pme::mergeSortPairs(pairs_);
    makeChains();
    chainMe m(&AChain_, &BChain_);
    m.insertPending();
    if (AChain_.front() == -1) AChain_.erase(AChain_.begin());
  }
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, PmergeMe const& cname);

#endif