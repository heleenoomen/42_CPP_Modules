/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:04:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/07 15:33:52 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

int main() {
  Point a(-3, 4);
  Point b(4, 3);
  Point c(-2.4f, -2);
  Point p(-1.013f, 0.5781f);

  bool inside;
  inside = bsp(a, b, c, p);
  if (inside == true)
    std::cout << "inside!" << std::endl;
  else
    std::cout << "outside!" << std::endl;
  return 0;
}
