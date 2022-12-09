/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 10:03:59 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

/* Default constructor */
WrongAnimal::WrongAnimal() : _type("") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

/* Copy constructor */
WrongAnimal::WrongAnimal(WrongAnimal const& src) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = src;
}

/* Copy assignment operator */
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  _type = rhs.getType();
  return *this;
}

/* Destructor */
WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

/* Getter */
std::string const& WrongAnimal::getType() const { return _type; }

/* Public method */
void WrongAnimal::makeSound() const { std::cout << "???" << std::endl; }
