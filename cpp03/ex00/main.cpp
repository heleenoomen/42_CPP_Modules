/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:06:42 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 17:11:35 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

void testClapTrap() {
  std::cout << "\033[48:5:208m -----### TESTING CLAPTRAP ###-----\033[0m\n";
  std::cout << "\033[1;33m ---Default constructor for ClapTrap a---\033[0m\n";
  ClapTrap a;
  std::cout << "\033[1;33m ---Tests ClapTrap a---\033[0m\n";
  a.attack("Julian");
  a.takeDamage(10);
  a.takeDamage(10);
  a.beRepaired(5);
  a.attack("a random robot");
  std::cout << "\033[1;33m ---String constructor for ClapTrap b---\033[0m\n";
  ClapTrap b("Bobby");
  std::cout << "\033[1;33m ---Tests ClapTrap b---\033[0m\n";
  for (int i = 0; i < 12; i++) b.attack("Jane");
    b.beRepaired(2);
  b.beRepaired(4);
  std::cout << "\033[1;33m ---Copy constructor for ClapTrap c, copy from b---\033[0m\n";
  ClapTrap c(b);
  std::cout << "\033[1;33m ---Test ClapTrap c---\033[0m\n";
  c.attack("Reinhold");
  std::cout << "\033[1;33m ---Deconstructors---\033[0m\n";
}

int main() {
  testClapTrap();
  std::cout << '\n';
}