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
  _type = "Cat";
  _brain = new Brain;
  for (int i = 0; i < 100; i++)
    setIdea(i, "");
}

/* Copy constructor */
Cat::Cat(Cat const& src) : Animal(src) {
  std::cout << "Cat copy constructor called" << std::endl;
  _brain = new Brain;
  *_brain = *src._brain;
}

/* Copy assignment operator */
Cat& Cat::operator=(Cat const& rhs) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  Animal::operator=(rhs);
  *_brain = *rhs._brain;
  return *this;
}

/* Destructor */
Cat::~Cat() { 
  std::cout << "Cat destructor called" << std::endl;
  delete _brain;
  }

/* Getters */
std::string const& Cat::getIdea(int i) const { return _brain->getIdea(i); }

/* Setter */
void Cat::setIdea(int index, std::string const& idea) { _brain->setIdea(index, idea); }

/* Public methods */
void Cat::makeSound() const { std::cout << "Meow" << std::endl; }

void Cat::printIdeas() const {
  for (int i = 0; i < 100; i++) {
    if (getIdea(i) != "")
      std::cout << "Idea " << i << ": " << getIdea(i) << std::endl;
  }
}
