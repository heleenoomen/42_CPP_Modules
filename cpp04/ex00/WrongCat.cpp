/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 16:55:43 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

/* Default constructor */
WrongCat::WrongCat() : type_("WrongCat") {
  std::cout << "WrongCat default constructor called\n";
}

/* Copy constructor */
WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src) {
  std::cout << "WrongCat copy constructor called\n";
  *this = src;
}

/* Copy assignment operator */
WrongCat& WrongCat::operator=(WrongCat const& rhs) {
  std::cout << "WrongCat copy assignment operator called\n";
  WrongAnimal::operator=(rhs);
  return *this;
}

/* Destructor */
WrongCat::~WrongCat() { std::cout << "WrongCat destructor called\n"; }

/* Getter */
std::string const& WrongCat::getType() const { return type_; }

/* Public method */
void WrongCat::makeSound() const { std::cout << "Meow\n"; }
