/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 09:54:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

/* Default constructor */
Cat::Cat() {
  std::cout << "Cat default constructor called" << std::endl;
  type_ = "Cat";
  brain_ = new Brain;
}

/* Copy constructor */
Cat::Cat(Cat const& src) : Animal(src) {
  std::cout << "Cat copy constructor called" << std::endl;
  brain_ = new Brain;
  *brain_ = *src.brain_;
}

/* Copy assignment operator */
Cat& Cat::operator=(Cat const& rhs) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  if (this == &rhs) return *this;
  Animal::operator=(rhs);
  *brain_ = *rhs.brain_;
  return *this;
}

/* Destructor */
Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete brain_;
}

/* Getters */
std::string const& Cat::getIdea(int i) const { return brain_->getIdea(i); }

/* Setter */
void Cat::setIdea(int index, std::string const& idea) {
  brain_->setIdea(index, idea);
}

/* Public methods */
void Cat::makeSound() const { std::cout << "Meow" << std::endl; }

void Cat::printIdeas() const { brain_->printIdeas(); }
