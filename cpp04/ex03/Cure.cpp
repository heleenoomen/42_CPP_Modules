/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:56:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 20:12:41 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

#include "layout.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << layout::grey << "Cure default constructor called\n"
            << layout::reset;
}

Cure::Cure(Cure const& src) : AMateria(src) {
  std::cout << layout::grey << "Cure copy constructor called\n"
            << layout::reset;
}

Cure& Cure::operator=(Cure const&) {
  std::cout << layout::grey << "Cure copy assignment operator called\n"
            << layout::reset;
  return *this;
}

Cure::~Cure() {
  std::cout << layout::grey << "Cure destructor called\n"
            << layout::reset << layout::reset;
}

AMateria* Cure::clone() const {
  AMateria* clone = new Cure();
  return clone;
}

void Cure::use(ICharacter& target) {
  std::cout << layout::magentaBold << "* heals " << target.getName()
            << "\'s wounds *\n"
            << layout::reset;
}
