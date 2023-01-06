/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 17:50:49 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap::ScavTrap() {
  std::cout << "ScavTrap default constructor called for " << getName() << '\n';
  // setHitPoints(100);
  // setEnergyPoints(50);
  // setAttackDamage(20);
  ScavTrap::_hitPoints = 100;
  ScavTrap::_energyPoints = 50;
  ScavTrap::_attackDamage = 20;
  setHitPoints(ScavTrap::_hitPoints);
  setEnergyPoints(ScavTrap::_energyPoints);
  setAttackDamage(ScavTrap::_attackDamage);
  return;
}

ScavTrap::ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
  std::cout << "ScavTrap parametric constructor called for " << getName()
            << '\n';
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
  return;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src) {
  std::cout << "ScavTrap copy constructor called, copying " << getName()
            << '\n';
  return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
  std::cout << "ScavTrap assignment operator overload called, assigning "
            << rhs.getName() << '\n';
  if (this == &rhs)
    return *this;
  ClapTrap::operator=(rhs);
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called for " << getName() << '\n';
}

void ScavTrap::guardGate() const {
  std::cout << "ScavTrap " << getName() << " is now in gatekeeper mode."
            << '\n';
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
            << getAttackDamage() << " point of damage! ScavTrap " << getName()
            << " has " << getEnergyPoints() << " energy points left."
            << '\n';
}
