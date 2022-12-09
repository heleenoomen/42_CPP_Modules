/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:43:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 19:56:21 by hoomen           ###   ########.fr       */
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
}

/* Destructor */
AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl; }

/* Public methods */
void AMateria::use(ICharacter& target) { return; }
