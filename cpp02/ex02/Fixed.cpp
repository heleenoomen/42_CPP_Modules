/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:58:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/07 17:22:57 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

/* ************************************************************************** */
/* CONSTRUCTORS                                                               */
/* ************************************************************************** */

/* Default constructor */
Fixed::Fixed() : _rawBits(0) { return; }

/* Copy constructor */
Fixed::Fixed(Fixed const& src) {
  *this = src;
  return;
}

/* Int constructor */
Fixed::Fixed(int const i) {
  _rawBits = i << _fractBits;
  return;
}

/* Float constructor */
Fixed::Fixed(float const f) {
  _rawBits = (int)roundf(f * (1 << _fractBits));
  return;
}

/* ************************************************************************** */
/* DECONSTRUCTOR                                                              */
/* ************************************************************************** */

Fixed::~Fixed() { return; }

/* ************************************************************************** */
/* GETTER AND SETTER                                                          */
/* ************************************************************************** */

int Fixed::getRawBits(void) const { return _rawBits; }

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
  Fixed ret(*this);
  _rawBits++;
  return Fixed(ret);
}

Fixed& Fixed::operator++() {
  _rawBits++;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed ret(*this);
  _rawBits--;
  return Fixed(ret);
}

Fixed& Fixed::operator--() {
  _rawBits--;
  return *this;
}

/* ************************************************************************** */
/* ARITHMETIC OPERATORS                                                       */
/* ************************************************************************** */

Fixed Fixed::operator+(Fixed const& rhs) const {
  Fixed tmp;

  tmp.setRawBits(_rawBits + rhs.getRawBits());
  return Fixed(tmp);
}

Fixed Fixed::operator-(Fixed const& rhs) const {
  Fixed tmp;

  tmp.setRawBits(_rawBits - rhs.getRawBits());
  return Fixed(tmp);
}

Fixed Fixed::operator*(Fixed const& rhs) const {
  Fixed tmp;

  tmp.setRawBits((_rawBits * rhs.getRawBits()) >> _fractBits);
  return Fixed(tmp);
}

Fixed Fixed::operator/(Fixed const& rhs) const {
  Fixed tmp;

  tmp.setRawBits((_rawBits / rhs.getRawBits()) << _fractBits);
  return Fixed(tmp);
}

/* ************************************************************************** */
/* COMPARISON OPERATORS                                                       */
/* ************************************************************************** */

bool Fixed::operator==(Fixed const& rhs) const {
  return _rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const& rhs) const {
  return _rawBits != rhs.getRawBits();
}
bool Fixed::operator<=(Fixed const& rhs) const {
  return _rawBits <= rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const& rhs) const {
  return _rawBits >= rhs.getRawBits();
}

bool Fixed::operator>(Fixed const& rhs) const {
  return _rawBits > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const& rhs) const {
  return _rawBits < rhs.getRawBits();
}

/* ************************************************************************** */
/* TYPE CONVERSION                                                            */
/* ************************************************************************** */

float Fixed::toFloat(void) const {
  return ((float)_rawBits) / (1 << _fractBits);
};

int Fixed::toInt(void) const { return _rawBits >> _fractBits; };

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
