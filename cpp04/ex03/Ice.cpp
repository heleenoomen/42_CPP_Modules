/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:56:26 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 16:58:50 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

#include "layout.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << layout::grey << "Ice default constructor called\n"
            << layout::reset;
}

Ice::Ice(Ice const& src) : AMateria(src) {
  std::cout << layout::grey << "Ice copy constructor called\n" << layout::reset;
}

Ice& Ice::operator=(Ice const&) {
  std::cout << layout::grey << "Ice copy assignment operator called\n"
            << layout::reset;
  return *this;
}

Ice::~Ice() {
  std::cout << layout::grey << "Ice destructor called\n" << layout::reset;
}

AMateria* Ice::clone() const {
  AMateria* clone = new Ice();
  return clone;
}

void Ice::use(ICharacter& target) {
  std::cout << layout::magentaBold << "* shoots an ice bolt at "
            << target.getName() << " *\n"
            << layout::reset;
}
