/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:43:31 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 16:58:33 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

#include "layout.hpp"

/* Default constructor */
AMateria::AMateria() {
  std::cout << layout::grey << "AMateria default contstructor called\n"
            << layout::reset;
}

/* Parametric constructor */
AMateria::AMateria(std::string const& type) : type_(type) {
  std::cout << layout::grey << "AMateria parametric contstructor called\n"
            << layout::reset;
}

/* Copy constructor */
AMateria::AMateria(AMateria const& src) {
  std::cout << layout::grey << "AMateria copy constructor called\n"
            << layout::reset;
  *this = src;
}

/* Copy assignment operator */
AMateria& AMateria::operator=(AMateria const& rhs) {
  std::cout << layout::grey << "AMateria copy assignment operator called\n"
            << layout::reset;
  if (this == &rhs) return *this;
  type_ = rhs.getType();
  return *this;
}

/* Destructor */
AMateria::~AMateria() {
  std::cout << layout::grey << "AMateria destructor called\n" << layout::reset;
}

/* Getter */
std::string const& AMateria::getType() const { return type_; }

/* Public methods */
void AMateria::use(ICharacter&) { return; }

/* Private helpers */
bool AMateria::typeDoesNotExist() const {
  if (type_ != "ice" && type_ != "cure") return true;
  return false;
}
