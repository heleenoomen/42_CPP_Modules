/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:16:06 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 16:58:54 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#include <iostream>

#include "layout.hpp"

ICharacter::ICharacter() {
  std::cout << layout::grey << "ICharacter default constructor called\n"
            << layout::reset;
}

ICharacter::ICharacter(ICharacter const& src) {
  std::cout << layout::grey << "ICharacter copy constructor called\n"
            << layout::reset;
  *this = src;
}

ICharacter& ICharacter::operator=(ICharacter const&) {
  std::cout << layout::grey << "ICharacter copy assignment operator called\n"
            << layout::reset;
  return *this;
}

ICharacter::~ICharacter() {
  std::cout << layout::grey << "ICharacter destructor called\n"
            << layout::reset;
}
