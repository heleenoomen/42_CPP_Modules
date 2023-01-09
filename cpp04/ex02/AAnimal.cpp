/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 17:38:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include <iostream>

/* Default constructor */
AAnimal::AAnimal() : type_("") {
  std::cout << "AAnimal default constructor called" << std::endl;
}

/* Copy constructor */
AAnimal::AAnimal(AAnimal const& src) {
  std::cout << "AAnimal copy constructor called" << std::endl;
  *this = src;
}

/* Copy assignment operator */
AAnimal& AAnimal::operator=(AAnimal const& rhs) {
  std::cout << "AAnimal copy assignment operator called" << std::endl;
  if (this == &rhs) return *this;
  type_ = rhs.getType();
  return *this;
}

/* Destructor */
AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

/* Getters */
std::string const& AAnimal::getType() const { return type_; }

std::string const& AAnimal::getIdea(int i) const {
  (void)i;
  return type_;
}

/* Setter */
void AAnimal::setIdea(int i, std::string const& idea) {
  (void)i;
  (void)idea;
}

/* Public method */
void AAnimal::makeSound() const { std::cout << "???" << std::endl; }
