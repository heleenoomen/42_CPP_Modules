/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 19:24:56 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) {
  std::cout << "ScavTrap default constructor called\n";
  return;
}

ScavTrap::ScavTrap::ScavTrap(std::string const& name)
    : ClapTrap(name, 100, 50, 20) {
  std::cout << "ScavTrap parametric constructor called for " << getName()
            << '\n';
  return;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src) {
  std::cout << "ScavTrap copy constructor called for " << getName() << '\n';
  return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
  std::cout << "ScavTrap assignment operator overload called for "
            << rhs.getName() << '\n';
  ClapTrap::operator=(rhs);
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

void ScavTrap::guardGate() const {
  std::cout << "ScavTrap " << getName() << " is now in gatekeeper mode.\n";
  return;
}

void ScavTrap::attack(std::string const& target) {
  if (getHitPoints() == 0 || getEnergyPoints() == 0) {
    std::cout << "ScavTrap " << getName() << " cannot attack: ";
    noPointsLeft();
    return;
  }
  decrEnergyPoints();
  std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
            << getAttackDamage();
  printPoints(getAttackDamage());
  std::cout << " of damage! ScavTrap " << getName() << " has "
            << getEnergyPoints() << " energy";
  printPoints(getEnergyPoints());
  std::cout << " left.\n";
}
