/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 18:40:04 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include <iostream>

/* Default constructor */
AAnimal::AAnimal() : _type("") {
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
  _type = rhs.getType();
  return *this;
}

/* Destructor */
AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

/* Getters */
std::string const& AAnimal::getType() const { return _type; }
