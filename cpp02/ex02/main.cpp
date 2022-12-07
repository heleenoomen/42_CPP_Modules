/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:04:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/07 17:24:06 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main() {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  // std::cout << std::endl << "Extra tests for max and min values:" <<
  // std::endl; Fixed c(8388607); Fixed d(-8388608); Fixed e(2); std::cout <<
  // (c.getRawBits()>>8) << std::endl; std::cout << (d.getRawBits()>>8) <<
  // std::endl; Fixed f = d / e; std::cout << f.toInt() << std::endl;
  return 0;
}
