/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:56:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 20:12:41 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const& src) : AMateria(src) {
  std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(Ice const& src) {
  std::cout << "Ice copy assignment operator called" << std::endl;
  return *this;
}

Ice::~Ice() {
  std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
  AMateria* clone = new Ice();
  return clone;
}
