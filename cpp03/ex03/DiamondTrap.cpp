/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/05 15:39:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap::DiamondTrap() {
  std::cout<<"DiamondTrap default constructor called for "<<getName()<<std::endl;
  return;
}

DiamondTrap::DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  DiamondTrap::_name = name;
  setHitPoints(FragTrap::getHitPoints());
  setEnergyPoints(ScavTrap::getEnergyPoints());
  setAttackDamage(FragTrap::getAttackDamage());
  std::cout<<"DiamondTrap parametric constructor called for "<<DiamondTrap::_name<<std::endl;
  std::cout<<"DiamondTrap, FragTrap has "<<FragTrap::getHitPoints()<<" hit points"<<std::endl;
  std::cout<<"DiamondTrap, ScavTrap has "<<ScavTrap::getEnergyPoints()<<" energy points"<<std::endl;
  std::cout<<"DiamondTrap, FragTrap has "<<FragTrap::getAttackDamage()<<" attack damage"<<std::endl;
  return;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
  std::cout<<"DiamondTrap copy constructor called for "<<src.getName()<<std::endl;
  *this = src;
  return;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
  std::cout<<"DiamondTrap assignment operator overload called for "<<rhs.getName()<<std::endl; 
  ClapTrap::operator=(rhs);
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout<<"DiamondTrap destructor called for "<<DiamondTrap::_name<<std::endl;
}


void DiamondTrap::whoAmI() const {
  std::cout<<"I am a DiamondTrap, my name is "<<DiamondTrap::_name<<". My ClapTrap name is "<<ClapTrap::getName()<<std::endl;
  return;
}

void DiamondTrap::attack(std::string const& target) {
  ScavTrap::attack(target);
}
