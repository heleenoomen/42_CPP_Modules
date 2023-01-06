/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 17:55:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
  std::cout << "FragTrap default constructor called for " << getName() << '\n';
  FragTrap::_hitPoints = 100;
  FragTrap::_energyPoints = 100;
  FragTrap::_attackDamage = 30;
  setHitPoints(FragTrap::_hitPoints);
  setEnergyPoints(FragTrap::_energyPoints);
  setAttackDamage(FragTrap::_attackDamage);
  // setHitPoints(100);
  // if (getEnergyPoints() == 10) setEnergyPoints(100);
  // setAttackDamage(30);
  return;
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
  FragTrap::_hitPoints = 100;
  FragTrap::_energyPoints = 100;
  FragTrap::_attackDamage = 30;
  setHitPoints(FragTrap::_hitPoints);
  setEnergyPoints(FragTrap::_energyPoints);
  setAttackDamage(FragTrap::_attackDamage);
  // setHitPoints(100);
  // if (getEnergyPoints() == 10) setEnergyPoints(100);
  // setAttackDamage(30);
  std::cout << "FragTrap parametric constructor called for " << getName()
            << '\n';
  return;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {
  std::cout << "FragTrap copy constructor called, copying " << src.getName()
            << '\n';
  return;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
  std::cout << "FragTrap copy assignment operator called, assigning "
            << rhs.getName() << '\n';
  if (this == &rhs)
    return *this;
  ClapTrap::operator=(rhs);
  FragTrap::_hitPoints = rhs.FragTrap::_hitPoints;
  FragTrap::_energyPoints = rhs.FragTrap::_energyPoints;
  FragTrap::_attackDamage = rhs.FragTrap::_hitPoints;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called for " << getName() << '\n';
}

void FragTrap::highFiveGuys() const {
  std::cout << "FragTrap " << getName()
            << " says: \"Hi Guys! Want a high five?\"" << '\n';
  return;
}

void FragTrap::attack(std::string const& target) {
  if (getHitPoints() == 0 || getEnergyPoints() == 0) {
    std::cout << "FragTrap " << getName() << " cannot attack: ";
    noPointsLeft();
    return;
  }
  decrEnergyPoints();
  std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "
            << getAttackDamage();
  printPoints(getAttackDamage());
  std::cout << " of damage! FragTrap " << ClapTrap::getName() << " has "
            << getEnergyPoints() << " energy";
  printPoints(getEnergyPoints());
  std::cout << " left." << '\n';
}
