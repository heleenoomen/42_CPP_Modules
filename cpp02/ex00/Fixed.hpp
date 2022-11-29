/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:51:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 18:40:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
 public:
  Fixed();
  ~Fixed();

  Fixed(Fixed const& src);

  Fixed& operator=(Fixed const& rhs);

  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  int _value;
  static int const _fract = 8;
};

#endif