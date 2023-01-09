/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:41:00 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 17:24:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
 private:
  static int const brainSize_ = 100;
  std::string ideas_[brainSize_];

 public:
  /* Default constructor */
  Brain();

  /* Copy constructor */
  Brain(Brain const& src);

  /* Copy assignment operator */
  Brain& operator=(Brain const& rhs);

  /* Destructor */
  ~Brain();

  /* getter */
  std::string const& getIdea(int index) const;
  void printIdeas() const;

  /* setter */
  void setIdea(int index, std::string const& idea);
};

#endif
