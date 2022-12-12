/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:43:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 12:44:49 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

/* Default constructor */
AMateria::AMateria() {
  std::cout << "AMateria default contstructor called" << std::endl;
}

/* Parametric constructor */
AMateria::AMateria(std::string const& type) : _type(type) {
  std::cout << "AMateria parametric contstructor called" << std::endl;
}

/* Copy constructor */
AMateria::AMateria(AMateria const& src) {
  std::cout << "AMateria copy constructor called" << std::endl;
  *this = src;
}

/* Copy assignment operator */
AMateria& AMateria::operator=(AMateria const& rhs) {
  std::cout << "AMateria copy assignment operator called" << std::endl;
  _type = rhs.getType();
  return *this;
}

/* Destructor */
AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl; }

/* Getter */
std::string const& AMateria::getType() const {
  return _type;
}

/* Public methods */
void AMateria::use(ICharacter&) { return; }

/* Private helpers */
bool AMateria::_typeDoesNotExist() const {
  if (_type != "ice" && _type != "cure")
    return true;
  return false;
}
