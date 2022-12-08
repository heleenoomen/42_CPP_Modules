/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:06:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/08 16:12:26 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  std::cout << "\033[48:5:208m -----### TESTING CLAPTRAP ###-----\033[0m"
            << std::endl;
  {
    std::cout << "\033[1;33m ---Default constructor---\033[0m" << std::endl;
    ClapTrap a;
    std::cout << "\033[1;33m ---String constructor---\033[0m" << std::endl;
    ClapTrap b("Bobby");
    std::cout << "\033[1;33m ---Copy constructor---\033[0m" << std::endl;
    ClapTrap c(b);

    std::cout << "\033[1;33m ---Tests ClapTrap a---\033[0m" << std::endl;
    a.attack("Julian");
    a.takeDamage(10);
    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("a random robot");
    b.beRepaired(4);
    std::cout << "\033[1;33m ---Tests ClapTrap b---\033[0m" << std::endl;
    for (int i = 0; i < 12; i++) b.attack("Jane");
    b.beRepaired(2);
    std::cout << "\033[1;33m ---Test ClapTrap c---\033[0m" << std::endl;
    c.attack("Reinhold");
    std::cout << "\033[1;33m ---Deconstructors---\033[0m" << std::endl;
  }
  std::cout << std::endl;
  std::cout << "\033[48:5:208m -----### TESTING SCAVTRAP ###-----\033[0m"
            << std::endl;
  {
    std::cout << "\033[1;33m ---Default constructor---\033[0m" << std::endl;
    ScavTrap a;
    std::cout << "\033[1;33m ---String constructor---\033[0m" << std::endl;
    ScavTrap b("Gingy");
    std::cout << "\033[1;33m ---Copy constructor---\033[0m" << std::endl;
    ScavTrap c(b);

    std::cout << "\033[1;33m ---Tests ScavTrap a---\033[0m" << std::endl;
    a.attack("Gary");
    a.takeDamage(21);
    a.beRepaired(1);
    for (int i = 0; i < 50; i++) a.attack("Gary");
    a.beRepaired(1);
    a.guardGate();
    std::cout << "\033[1;33m ---Tests ScavTrap b---\033[0m" << std::endl;
    b.attack("Gumy");
    b.takeDamage(95);
    b.beRepaired(3);
    b.guardGate();
    std::cout << "\033[1;33m ---Tests ScavTrap b---\033[0m" << std::endl;
    c.attack("Gury");
    c.guardGate();
    c.takeDamage(3);
    c.beRepaired(5);
    std::cout << "\033[1;33m ---Deconstructors---\033[0m" << std::endl;
  }
}