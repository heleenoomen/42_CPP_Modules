/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:58:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 18:38:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
};

Fixed::Fixed(Fixed const& src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;

  return;
};

Fixed::Fixed(int const i) {
  unsigned int j;

  if (i < 0) {
    j = (i * -1) - 1;
    _rawBits = ~j << _fractBits;
  } else
    _rawBits = i << _fractBits;

  std::cout << "Int constructor called" << std::endl;

  return;
};

Fixed::Fixed(float f) {
  _rawBits = (int)roundf(f * (1 << _fractBits));

  std::cout << "Float constructor called" << std::endl;

  return;
};

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
  return;
};

Fixed& Fixed::operator=(Fixed const& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  _rawBits = rhs.getRawBits();

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

float Fixed::toFloat(void) const {
  return ((float)_rawBits) / (1 << _fractBits);
};

int Fixed::toInt(void) const {
  unsigned int conv;
  int ret;

  if (_rawBits & (1 << 31)) {
    conv = (~_rawBits) + 1;
    ret = conv >> 8;
    ret *= -1;
  } else
    ret = _rawBits >> 8;

  return ret;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
  o << rhs.toFloat();
  return o;
}
