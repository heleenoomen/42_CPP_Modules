/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 10:03:59 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

#include "Animal.hpp"

/* Default constructor */
Animal::Animal() : _type("") {
  std::cout << "Animal default constructor called" << std::endl;
}

/* Copy constructor */
Animal::Animal(Animal const& src) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = src;
}

/* Copy assignment operator */
Animal& Animal::operator=(Animal const& rhs) {
  std::cout << "Animal copy assignment operator called" << std::endl;
  _type = rhs.getType();
  return *this;
}

/* Destructor */
Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

/* Getter */
std::string const& Animal::getType() const { return _type; }

/* Public method */
void Animal::makeSound() const {
  std::cout << "???" << std::endl;
}
