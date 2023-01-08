/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 09:54:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

/* Default constructor */
Dog::Dog() {
  std::cout << "Dog default constructor called" << std::endl;
  type_ = "Dog";
  brain_ = new Brain;
}

/* Copy constructor */
Dog::Dog(Dog const& src) : AAnimal(src) {
  std::cout << "Dog copy constructor called" << std::endl;
  brain_ = new Brain;
  *brain_ = *src.brain_;
}

/* Copy assignment operator */
Dog& Dog::operator=(Dog const& rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  if (this == &rhs) return *this;
  type_ = rhs.getType();
  *brain_ = *rhs.brain_;
  return *this;
}

/* Destructor */
Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete brain_;
}

/* Getters */
std::string const& Dog::getIdea(int i) const { return brain_->getIdea(i); }

/* Set idea */
void Dog::setIdea(int i, std::string const& idea) { brain_->setIdea(i, idea); }

/* Public methods */
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

void Dog::printIdeas() const { brain_->printIdeas(); }
