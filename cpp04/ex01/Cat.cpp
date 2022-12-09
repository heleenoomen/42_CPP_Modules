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
  // for (int i = 0; i < 100; i++)
  //   _brain
}

/* Copy constructor */
Cat::Cat(Cat const& src) : Animal(src) {
  std::cout << "Cat copy constructor called" << std::endl;
  _brain = NULL;
  *this = src;
}

/* Copy assignment operator */
Cat& Cat::operator=(Cat const& rhs) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  Animal::operator=(rhs);
  delete _brain;
  _brain = new Brain;
  for (int i = 0; i < 100; i++)
    _brain[i] = rhs._brain[i];
  return *this;
}

/* Destructor */
Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

/* Getter */
std::string const& Cat::getType() const { return _type; }

/* Public method */
void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
