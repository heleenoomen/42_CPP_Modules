/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:16:06 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 13:00:39 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#include <iostream>

ICharacter::ICharacter() {
  std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const& src) {
  std::cout << "ICharacter copy constructor called" << std::endl;
  *this = src;
}

ICharacter& ICharacter::operator=(ICharacter const&) {
  std::cout << "ICharacter copy assignment operator called" << std::endl;
  return *this;
}

ICharacter::~ICharacter() {
  std::cout << "ICharacter destructor called" << std::endl;
}
