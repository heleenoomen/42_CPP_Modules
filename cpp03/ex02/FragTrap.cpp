/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/08 12:35:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap::FragTrap() : ClapTrap() {
  std::cout<<"FragTrap default constructor called" << std::endl;
  return;
}

FragTrap::FragTrap::FragTrap(std::string const& name) : ClapTrap(name, 100, 100, 30) {
  std::cout<<"FragTrap parametric constructor called for "<<getName()<<std::endl;
  return;
}

FragTrap::FragTrap(FragTrap const& src) {
  std::cout<<"FragTrap copy constructor called for "<<src.getName()<<std::endl;
  *this = src;
  return;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
  std::cout<<"FragTrap assignment operator overload called for "<<rhs.getName()<<std::endl; 
  ClapTrap::operator=(rhs);
  return *this;
}

FragTrap::~FragTrap() {
  std::cout<<"FragTrap destructor called for "<<getName()<<std::endl;
}

void FragTrap::highFiveGuys() const {
  std::cout<<"FragTrap "<<getName()<<" says: \"Hi Guys! Want a high five?\""<<std::endl;
  return;
}

void FragTrap::attack(std::string const& target) {
  if (getHitPoints() == 0 || getEnergyPoints() == 0) {
    std::cout<<"FragTrap "<<getName()<<" cannot attack: ";
    noPointsLeft();
	return;
  }
  setEnergyPoints();
  std::cout<<"FragTrap "<<getName()<<" attacks "<<target<<", causing "<<\
  getAttackDamage()<<" point of damage! FragTrap "<<ClapTrap::getName()<<\
  " has now "<<getEnergyPoints()<<" energy points left."<<std::endl;
  
}