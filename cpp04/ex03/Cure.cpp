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
#include "Layout.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {
  std::cout << Layout::grey << "Cure default constructor called\n"
            << Layout::reset;
}

Cure::Cure(Cure const& src) : AMateria(src) {
  std::cout << Layout::grey << "Cure copy constructor called\n"
            << Layout::reset;
}

Cure& Cure::operator=(Cure const&) {
  std::cout << Layout::grey << "Cure copy assignment operator called\n"
            << Layout::reset;
  return *this;
}

Cure::~Cure() {
  std::cout << Layout::grey << "Cure destructor called\n" << Layout::reset
            << Layout::reset;
}

AMateria* Cure::clone() const {
  AMateria* clone = new Cure();
  return clone;
}

void Cure::use(ICharacter& target) {
  std::cout << Layout::magentaBold << "* heals " << target.getName()
            << "\'s wounds *\n" << Layout::reset;
}
