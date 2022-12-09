/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:16:06 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 20:19:47 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#include <iostream>

ICharacter::ICharacter() {
  std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const& src) {
  std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter& ICharacter::operator=(ICharacter const& rhs) {
  std::cout << "ICharacter copy assignment operator called" << std::endl;
}

ICharacter::~ICharacter() {
  std::cout << "ICharacter destructor called" << std::endl;
}
