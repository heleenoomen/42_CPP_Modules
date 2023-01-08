/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:56:26 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 20:30:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Layout.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {
  std::cout << Layout::grey << "Ice default constructor called\n"
            << Layout::reset;
}

Ice::Ice(Ice const& src) : AMateria(src) {
  std::cout << Layout::grey << "Ice copy constructor called\n"
            << Layout::reset;
}

Ice& Ice::operator=(Ice const&) {
  std::cout << Layout::grey << "Ice copy assignment operator called\n"
            << Layout::reset;
  return *this;
}

Ice::~Ice() {
  std::cout << Layout::grey << "Ice destructor called\n"
            << Layout::reset;
}

AMateria* Ice::clone() const {
  AMateria* clone = new Ice();
  return clone;
}

void Ice::use(ICharacter& target) {
  std::cout << Layout::magentaBold << "* shoots an ice bolt at " << target.getName()
            << " *\n" << Layout::reset;
}
