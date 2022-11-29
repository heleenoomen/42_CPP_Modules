/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:58:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 18:49:29 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) {
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
  _value = rhs.getRawBits();

  return *this;
};

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _value;
};

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _value = raw;

  return;
};
