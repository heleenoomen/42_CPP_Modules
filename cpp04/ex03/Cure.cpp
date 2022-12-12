/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:56:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 20:12:41 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const& src) : AMateria(src) {
  std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(Cure const&) {
  std::cout << "Cure copy assignment operator called" << std::endl;
  return *this;
}

Cure::~Cure() {
  std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
  AMateria* clone = new Cure();
  return clone;
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "\'s wounds *" << "\n";
}
