/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 16:46:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

/* Default constructor */
Animal::Animal() : _type("") {
  std::cout << "Animal default constructor called\n";
}

/* Copy constructor */
Animal::Animal(Animal const& src) {
  std::cout << "Animal copy constructor called\n";
  *this = src;
}

/* Copy assignment operator */
Animal& Animal::operator=(Animal const& rhs) {
  std::cout << "Animal copy assignment operator called\n";
  _type = rhs.getType();
  return *this;
}

/* Destructor */
Animal::~Animal() { std::cout << "Animal destructor called\n"; }

/* Getter */
std::string const& Animal::getType() const { return _type; }

/* Public method */
void Animal::makeSound() const { std::cout << "???\n"; }
