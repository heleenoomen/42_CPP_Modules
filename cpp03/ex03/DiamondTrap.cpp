/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:43:21 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 19:44:17 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name") {
  std::cout << "DiamondTrap default constructor called for " << getName()
            << '\n';
  DiamondTrap::_name = "default";
  setHitPoints(FragTrap::_hitPoints);
  setEnergyPoints(ScavTrap::_energyPoints);
  setAttackDamage(FragTrap::_attackDamage);
  return;
}

DiamondTrap::DiamondTrap::DiamondTrap(std::string const& name)
    : ClapTrap(name + "_clap_name") {
  std::cout << "DiamondTrap parametric constructor called for " << getName()
            << '\n';
  DiamondTrap::_name = name;
  setHitPoints(FragTrap::_hitPoints);
  setEnergyPoints(ScavTrap::_energyPoints);
  setAttackDamage(FragTrap::_attackDamage);
  return;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) {
  std::cout << "DiamondTrap copy constructor called, copying " << src.getName()
            << '\n';
  *this = src;
  return;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
  std::cout << "DiamondTrap copy assignment operator called, assigning "
            << rhs.getName() << '\n';
  if (this == &rhs) return *this;
  ClapTrap::operator=(rhs);
  DiamondTrap::_name = rhs.DiamondTrap::_name;
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called for " << DiamondTrap::_name
            << '\n';
}

void DiamondTrap::whoAmI() const {
  std::cout << "I am a DiamondTrap, my name is " << DiamondTrap::_name
            << ". My ClapTrap name is " << ClapTrap::getName() << '\n';
  return;
}

void DiamondTrap::attack(std::string const& target) {
  ScavTrap::attack(target);
}
