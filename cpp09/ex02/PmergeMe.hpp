/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

// #include <string>
// #include <iostream>
#include <vector>
#include <list>

class PmergeMe {
 private:
  std::vector<int> v_;
  std::list<int> l_;

  // /* private methods*/

  // protected:

  // /* protected methods */

 public:
  /* default constructor */
  PmergeMe();
  PmergeMe(int argc, char** argv);

  /* copy constructor */
  PmergeMe(PmergeMe const& src);

  /* copy assignment operator */
  PmergeMe& operator=(PmergeMe const& rhs);

  /* default destructor */
  ~PmergeMe();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, PmergeMe const& cname);

#endif