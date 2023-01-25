/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:51:22 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/25 17:28:02 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  typedef typename std::stack<T, Container>::container_type::iterator iterator;
  typedef typename std::stack<T, Container>::container_type::const_iterator
      const_iterator;
  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }

  MutantStack() {}
  MutantStack(Container const& a) : std::stack<T, Container>::stack(a) {}
  MutantStack& operator=(Container const& a) {
    std::stack<T, Container>::operator=(a);
  }
  ~MutantStack() {}
};

#endif
