/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:58:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 18:53:57 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

/* ************************************************************************** */
/* CONSTRUCTORS                                                               */
/* ************************************************************************** */

/* Default constructor */
Fixed::Fixed() : _rawBits(0) {
  // std::cout << "Default constructor called" << std::endl;
  return;
}

/* Copy constructor */
Fixed::Fixed(Fixed const& src) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = src;

  return;
}

/* Int constructor */
Fixed::Fixed(int const i) {
  unsigned int j;

  if (i < 0) {
    j = (i * -1) - 1;
    _rawBits = ~j << _fractBits;
  } else
    _rawBits = i << _fractBits;

  // std::cout << "Int constructor called" << std::endl;

  return;
}

/* Float constructor */
Fixed::Fixed(float f) {
  _rawBits = (int)roundf(f * (1 << _fractBits));

  return;
}

/* ************************************************************************** */
/* DECONSTRUCTOR                                                              */
/* ************************************************************************** */

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
  return;
}

/* ************************************************************************** */
/* GETTER AND SETTER                                                          */
/* ************************************************************************** */

int Fixed::getRawBits(void) const {
  return _rawBits;
}

void Fixed::setRawBits(int const raw) {
  _rawBits = raw;

  return;
};

/* ************************************************************************** */
/* ASSIGNMENT OPERATOR                                                        */
/* ************************************************************************** */

Fixed& Fixed::operator=(Fixed const& rhs) {
  _rawBits = rhs.getRawBits();

  return *this;
}

/* ************************************************************************** */
/* PRE & POST INCREMENT/DECREMENTS OPERATORS                                  */
/* ************************************************************************** */

Fixed Fixed::operator++(int) {
  Fixed ret;
  ret.setRawBits(_rawBits);
  _rawBits++;
  return Fixed(ret);
}

Fixed& Fixed::operator++() {
  ++_rawBits;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed ret;
  ret.setRawBits(_rawBits);
  _rawBits--;
  return Fixed(ret);
}

Fixed& Fixed::operator--() {
  --_rawBits;
  return *this;
}

/* ************************************************************************** */
/* ARITHMETIC OPERATORS                                                       */
/* ************************************************************************** */

Fixed Fixed::operator+(Fixed const& rhs) {
  Fixed tmp;

  tmp.setRawBits(_rawBits + rhs.getRawBits());
  return Fixed(tmp);
}

Fixed Fixed::operator-(Fixed const& rhs) {
  Fixed tmp;

  tmp.setRawBits(_rawBits - rhs.getRawBits());
  return Fixed(tmp);
}

Fixed Fixed::operator*(Fixed const& rhs) {
  Fixed tmp;

  tmp.setRawBits((_rawBits * rhs.getRawBits()) >> _fractBits);
  return Fixed(tmp);
}

Fixed Fixed::operator/(Fixed const& rhs) {
  Fixed tmp;

  tmp.setRawBits((_rawBits << _fractBits) / (rhs.getRawBits()));
  return Fixed(tmp);
}

/* ************************************************************************** */
/* COMPARISON OPERATORS                                                       */
/* ************************************************************************** */

bool Fixed::operator==(Fixed const& rhs) {
  return _rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const& rhs) {
  return _rawBits != rhs.getRawBits();
}
bool Fixed::operator<=(Fixed const& rhs) {
  return _rawBits <= rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const& rhs) {
  return _rawBits >= rhs.getRawBits();
}

bool Fixed::operator>(Fixed const& rhs) { return _rawBits > rhs.getRawBits(); }

bool Fixed::operator<(Fixed const& rhs) { return _rawBits < rhs.getRawBits(); }

/* ************************************************************************** */
/* TYPE CONVERSION                                                            */
/* ************************************************************************** */

float Fixed::toFloat(void) const {
  return ((float)_rawBits) / (1 << _fractBits);
};

int Fixed::toInt(void) const {
  int raw;
  unsigned int conv;
  int ret;

  raw = _rawBits;
  if (raw & (1 << 31)) {
    conv = (~raw) + 1;
    ret = conv >> _fractBits;
    ret *= -1;
  } else
    ret = raw >> _fractBits;

  return ret;
};

/* ************************************************************************** */
/* MIN / MAX                                                                  */
/* ************************************************************************** */

Fixed& Fixed::min(Fixed& one, Fixed& two) {
  if (one < two) return one;
  return two;
}

Fixed const& Fixed::min(Fixed const& one, Fixed const& two) {
  if (Fixed(one) < Fixed(two)) return one;
  return two;
}

Fixed& Fixed::max(Fixed& one, Fixed& two) {
  if (one > two) return one;
  return two;
}

Fixed const& Fixed::max(Fixed const& one, Fixed const& two) {
  if (Fixed(one) > Fixed(two)) return one;
  return two;
}

/* ************************************************************************** */
/* STREAM REDIRECTION OPERATOR                                                */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
  o << rhs.toFloat();
  return o;
}
