/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 09:54:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

#include "WrongCat.hpp"

/* Default constructor */
WrongCat::WrongCat() : _type("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

/* Copy constructor */
WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = src;
}

/* Copy assignment operator */
WrongCat& WrongCat::operator=(WrongCat const& rhs) {
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  WrongAnimal::operator=(rhs);
  return *this;
}

/* Destructor */
WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

/* Getter */
std::string const& WrongCat::getType() const { return _type; }

/* Public method */
void WrongCat::makeSound() const {
  std::cout << "Meow" << std::endl;
}
