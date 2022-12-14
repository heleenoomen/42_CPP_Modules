/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:51:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/07 17:23:43 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(Fixed const& src);
  Fixed(int const fixpt);
  Fixed(float const f);

  ~Fixed();

  /* to discern post- and pre, post gets a dummy int parameter */
  Fixed& operator=(Fixed const& rhs);
  Fixed operator++(int);
  Fixed& operator++();
  Fixed operator--(int);
  Fixed& operator--();

  Fixed operator+(Fixed const& rhs) const;
  Fixed operator-(Fixed const& rhs) const;
  Fixed operator*(Fixed const& rhs) const;
  Fixed operator/(Fixed const& rhs) const;

  bool operator==(Fixed const& rhs) const;
  bool operator!=(Fixed const& rhs) const;
  bool operator<=(Fixed const& rhs) const;
  bool operator>=(Fixed const& rhs) const;
  bool operator>(Fixed const& rhs) const;
  bool operator<(Fixed const& rhs) const;

  static Fixed& min(Fixed& one, Fixed& two);
  static Fixed const& min(Fixed const& one, Fixed const& two);
  static Fixed& max(Fixed& one, Fixed& two);
  static Fixed const& max(Fixed const& one, Fixed const& two);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  int _rawBits;
  static int const _fractBits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif