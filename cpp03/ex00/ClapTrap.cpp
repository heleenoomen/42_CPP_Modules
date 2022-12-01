/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:31:32 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/01 16:36:30 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/* NON MEMBER ATTRIBUTES                                                      */
/* ************************************************************************** */

unsigned int const ClapTrap::attack_damage = 7;


/* ************************************************************************** */
/* CONSTRUCTORS                                                               */
/* ************************************************************************** */

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(10) {
  std::cout << "Default constructor called" << std::endl;
  return ;
}

ClapTrap::ClapTrap(ClapTrap const& src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return ;
}

ClapTrap::ClapTrap(std::string const& name) : _name(name) , _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "String constructor called" << std::endl;
  return ;
}


/* ************************************************************************** */
/* ASSIGNMENT OPERATOR                                                        */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
  std::cout << "Assignment operator overload called" << std::endl;
  _name = rhs.getName();
  _hitPoints = rhs.getHitPoints();
  _energyPoints = rhs.getEnergyPoints();
  _attackDamage = rhs.getAttackDamage();
  return *this;
}


/* ************************************************************************** */
/* DESTRUCTOR                                                                 */
/* ************************************************************************** */

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}


/* ************************************************************************** */
/* getters                                                                    */
/* ************************************************************************** */

std::string const& ClapTrap::getName() const {
	return _name;
}

int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}


/* ************************************************************************** */
/* ACTIONS                                                                    */
/* ************************************************************************** */

void ClapTrap::attack(std::string const& target) {
  if (_energyPoints == 0) {
    std::cout<<"ClapTrap "<<_name<<" is unable to attack: No energy points left!"\
    <<std::endl;
    return;
  }
  if (_hitPoints == 0) {
    std::cout<<"ClapTrap "<<_name<<" is unable to attack: No hit points left!"\
    <<std::endl;
	return;
  }
  std::cout<<"ClapTrap "<<_name<<" attacks "<<target<<", causing "\
  <<attack_damage<<" points of damage!"<<std::endl;
  _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout<<"ClapTrap "<<_name<<" takes damage, losing "<<amount;
  if (amount == 1)
    std::cout<<"hitpoint!";
  else
	std::cout<<"hitpoints!";
  std::cout<<std::endl;
  _hitPoints-=attack_damage;
  if(_hitPoints < 0)
    _hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints == 0)
  {
    std::cout<<"Alas! Claptrap "<<_name<<" cannot be repaired: no energy points left!"\
    <<std::endl;
    return ;
  }
  _hitPoints+=amount;
  _energyPoints-=1;
  std::cout<<"Claptrap "<<_name<<" is being repaired with "<<amount;
  if (amount == 1)
    std::cout<<" hit point.";
else
    std::cout<<" hit points.";
  std::cout<<" Hit points: "<<_hitPoints <<" Energy: "\
  <<_energyPoints<<std::endl;
}