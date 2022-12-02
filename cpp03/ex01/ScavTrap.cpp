/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/02 15:46:14 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap::ScavTrap() : ClapTrap() {
  std::cout<<"ScavTrap default constructor called"<<std::endl;
  return;
}

ScavTrap::ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name, 100, 50, 20) {
  std::cout<<"ScavTrap string constructor called"<<std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src) {
  std::cout<<"ScavTrap copy constructor called"<<std::endl;
  *this = src;
  return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
  std::cout<<"ScavTrap assignment operator overload called"<<std::endl; 
  ClapTrap::operator=(rhs);
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout<<"ScavTrap destructor called"<<std::endl;
}

void ScavTrap::guardGate() const {
  std::cout<<"ScavTrap "<<ClapTrap::getName()<<" is now in gatekeeper mode."<<std::endl;
  return;
}

void ScavTrap::attack(std::string const& target) {
  if (ClapTrap::getHitPoints() == 0 || ClapTrap::getEnergyPoints() == 0) {
    std::cout<<"ScavTrap "<<ClapTrap::getName()<<" cannot attack: ";
    if (ClapTrap::getHitPoints() == 0)
      std::cout<<"No hit points left."<<std::endl;
    else
      std::cout<<"No energy points left."<<std::endl;
    return ;
  }
  ClapTrap::setEnergyPoints();
  std::cout<<"ScavTrap "<<ClapTrap::getName()<<" attacks "<<target<<", causing "<<\
  ClapTrap::getAttackDamage()<<" point of damage! ScavTrap "<<ClapTrap::getName()<<\
  " has now "<<ClapTrap::getEnergyPoints()<<" energy points left."<<std::endl;
  
}
