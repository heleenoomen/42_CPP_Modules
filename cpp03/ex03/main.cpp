/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:06:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/08 17:08:35 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  std::cout << "\033[1;33m ---String constructor---\033[0m" << std::endl;
  DiamondTrap a("Katy");

  std::cout << "\033[1;33m ---Tests DiamondTrap a---\033[0m" << std::endl;
  a.whoAmI();
  a.attack("Juniper2");
  a.takeDamage(16);
  a.beRepaired(1);

  std::cout << "\033[1;33m ---Copy constructor---\033[0m" << std::endl;
  DiamondTrap b(a);

  std::cout << "\033[1;33m ---Tests DiamondTrap b---\033[0m" << std::endl;
  b.whoAmI();
  b.attack("Jill");
  b.takeDamage(5);
  b.beRepaired(1);

  
  std::cout << "\033[1;33m ---Default constructor---\033[0m" << std::endl;
  DiamondTrap c;

  std::cout << "\033[1;33m ---Copy assignment operator---\033[0m" << std::endl;
  c = a;
  c.whoAmI();
  c.attack("a robot guru");
  c.takeDamage(13);
  c.beRepaired(6);
  std::cout << "\033[1;33m ---Deconstructors---\033[0m" << std::endl;
}
