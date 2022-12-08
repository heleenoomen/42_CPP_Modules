/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:58:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/07 17:21:21 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
};

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
  return;
};

Fixed::Fixed(Fixed const& src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
};

Fixed& Fixed::operator=(Fixed const& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs) _rawBits = rhs.getRawBits();
  return *this;
};

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _rawBits;
};

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _rawBits = raw;
  return;
};
