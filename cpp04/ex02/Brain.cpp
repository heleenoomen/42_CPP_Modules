/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:14:25 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 17:32:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

/* Default constructor */
Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

/* Copy constructor */
Brain::Brain(Brain const& src) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = src;
}

/* Copy assignment operator */
Brain& Brain::operator=(Brain const& src) {
  std::cout << "Brain copy assignment operator called" << std::endl;
  if (this == &src) return *this;
  for (int i = 0; i < 100; i++) {
    ideas_[i] = src.getIdea(i);
  }
  return *this;
}

/* Destructor */
Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

/* Getter */
std::string const& Brain::getIdea(int index) const { return ideas_[index]; }

/* Setter */
void Brain::setIdea(int index, std::string const& idea) {
  ideas_[index] = idea;
}

/* Public methods */
void Brain::printIdeas() const {
  for (int i = 0; i < brainSize_; ++i) {
    if (ideas_[i] != "") std::cout << "Idea " << i << ": " << ideas_[i] << '\n';
  }
}