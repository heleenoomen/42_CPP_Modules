/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:43:21 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/08 20:25:06 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name") {
  std::cout << "DiamondTrap default constructor called" << std::endl;
  DiamondTrap::_name = "default";
  return;
}

DiamondTrap::DiamondTrap::DiamondTrap(std::string const& name)
    : ClapTrap(name + "_clap_name") {
  DiamondTrap::_name = name;
  setHitPoints(FragTrap::getHitPoints());
  setEnergyPoints(ScavTrap::getEnergyPoints());
  setAttackDamage(FragTrap::getAttackDamage());
  std::cout << "DiamondTrap parametric constructor called for " << getName()
            << std::endl;
  return;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
  std::cout << "DiamondTrap copy constructor called for " << src.getName()
            << std::endl;
  DiamondTrap::_name = src.DiamondTrap::_name;
  setHitPoints(src.getHitPoints());
  setEnergyPoints(src.getEnergyPoints());
  setAttackDamage(src.getAttackDamage());
  return;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
  std::cout << "DiamondTrap copy assignment operator called for "
            << rhs.DiamondTrap::_name << std::endl;
  ClapTrap::operator=(rhs);
  _name = rhs.DiamondTrap::_name;
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called for " << DiamondTrap::_name
            << std::endl;
}

void DiamondTrap::whoAmI() const {
  std::cout << "I am a DiamondTrap, my name is " << DiamondTrap::_name
            << ". My ClapTrap name is " << ClapTrap::getName() << std::endl;
  return;
}

void DiamondTrap::attack(std::string const& target) {
  ScavTrap::attack(target);
}
