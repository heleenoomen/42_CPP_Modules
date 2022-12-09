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
  _type = "Dog";
  _brain = new Brain;
  for (int i = 0; i < 100; i++) {
    setIdea(i, "");
  }
}

/* Copy constructor */
Dog::Dog(Dog const& src) : Animal(src) {
  std::cout << "Dog copy constructor called" << std::endl;
  _brain = new Brain;
  *_brain = *src._brain;
}

/* Copy assignment operator */
Dog& Dog::operator=(Dog const& rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  _type = rhs.getType();
  *_brain = *rhs._brain;
  return *this;
}

/* Destructor */
Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete _brain;
  }

/* Getters */
std::string const& Dog::getIdea(int i) const { return _brain->getIdea(i); }

/* Set idea */
void Dog::setIdea(int i, std::string const& idea) { _brain->setIdea(i, idea); }

/* Public methods */
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

void Dog::printIdeas() const {
  for (int i = 0; i < 100; i++) {
    if (getIdea(i) != "")
      std::cout << "Idea " << i << ": " << getIdea(i) << std::endl;
  }
}