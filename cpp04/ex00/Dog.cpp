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

#include<iostream>

#include "Dog.hpp"

/* Default constructor */
Dog::Dog() {
  std::cout << "Dog default constructor called" << std::endl;
  _type = "Dog";
}

/* Copy constructor */
Dog::Dog(Dog const& src) : Animal(src) {
  std::cout << "Dog copy constructor called" << std::endl;
}

/* Copy assignment operator */
Dog& Dog::operator=(Dog const& rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  Animal::operator=(rhs);
  return *this;
}

/* Destructor */
Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
}

/* Getter */
std::string const& Dog::getType() const { return _type; }

/* Public methods */
void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}
