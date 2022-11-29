/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:04:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 20:35:58 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

int main() {
  Point a(-3.f, 4.f);
  Point b(4.f, 3.f);
  Point c(-2.4f, -2.f);
  Point p(5.f, 1.1f);

  bool inside;
  inside = bsp(a, b, c, p);
  if (inside == true)
    std::cout << "inside!" << std::endl;
  else
    std::cout << "outside!" << std::endl;
  return 0;
}
