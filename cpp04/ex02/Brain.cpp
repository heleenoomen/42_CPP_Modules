/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:14:25 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 17:00:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

/* Default constructor */
Brain::Brain() {
  std::cout << "Brain default constructor called" << std::endl;
}

/* Copy constructor */
Brain::Brain(Brain const& src) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = src;
}

/* Copy assignment operator */
Brain& Brain::operator=(Brain const& src) {
  std::cout << "Brain copy assignment operator called" << std::endl;
  for (int i = 0; i < 100; i++) {
    _ideas[i] = src.getIdea(i);
  }
  return *this;
}

/* Destructor */
Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
}

/* Getter */
std::string const& Brain::getIdea(int index) const { return _ideas[index]; }

/* Setter */
void Brain::setIdea(int index, std::string const& idea) { _ideas[index] = idea; }