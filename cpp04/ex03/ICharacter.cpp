/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:16:06 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/09 18:03:10 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#include <iostream>

#include "Layout.hpp"

ICharacter::ICharacter() {
  std::cout << Layout::grey << "ICharacter default constructor called\n"
            << Layout::reset;
}

ICharacter::ICharacter(ICharacter const& src) {
  std::cout << Layout::grey << "ICharacter copy constructor called\n"
            << Layout::reset;
  *this = src;
}

ICharacter& ICharacter::operator=(ICharacter const&) {
  std::cout << Layout::grey << "ICharacter copy assignment operator called\n"
            << Layout::reset;
  return *this;
}

ICharacter::~ICharacter() {
  std::cout << Layout::grey << "ICharacter destructor called\n"
            << Layout::reset;
}
