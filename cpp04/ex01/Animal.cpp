/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 17:26:51 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

/* Default constructor */
Animal::Animal() : type_("") {
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
  if (this == &rhs) return *this;
  type_ = rhs.getType();
  return *this;
}

/* Destructor */
Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

/* Getters */
std::string const& Animal::getType() const { return type_; }

std::string const& Animal::getIdea(int i) const {
  (void)i;
  return type_;
}

/* Setter */
void Animal::setIdea(int i, std::string const& idea) {
  (void)i;
  (void)idea;
}

/* Public method */
void Animal::makeSound() const { std::cout << "???" << std::endl; }
