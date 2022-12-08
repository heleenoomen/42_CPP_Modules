/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:31:32 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/08 12:36:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


/* ************************************************************************** */
/* CONSTRUCTORS                                                               */
/* ************************************************************************** */

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called"<< std::endl;
  return ;
}

ClapTrap::ClapTrap(ClapTrap const& src) {
  std::cout << "ClapTrap copy constructor called for "<<src.getName()<< std::endl;
  *this = src;
  return ;
}

ClapTrap::ClapTrap(std::string const& name) : _name(name) , _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout<<"ClapTrap string constructor called for "<<_name<<std::endl;
  return ;
}

ClapTrap::ClapTrap(std::string const& name, int hitPoints, int energyPoints, int attackDamage) :\
_name(name) , _hitPoints(hitPoints) , _energyPoints(energyPoints), _attackDamage(attackDamage) {
	std::cout <<"ClapTrap parametric constructor (string, int, int, int) called for "<<_name<< std::endl;
}


/* ************************************************************************** */
/* ASSIGNMENT OPERATOR                                                        */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
  std::cout << "ClapTrap Assignment operator overload called for "<<rhs.getName() << std::endl;
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
	std::cout << "ClapTrap destructor called for "<<_name<< std::endl;
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
/* setters                                                                    */
/* ************************************************************************** */

void ClapTrap::setEnergyPoints() {
  _energyPoints--;
}

/* ************************************************************************** */
/* ACTIONS                                                                    */
/* ************************************************************************** */

void ClapTrap::attack(std::string const& target) {
  if (_energyPoints == 0 || _hitPoints == 0) {
    std::cout<<"ClapTrap "<<_name<<" is unable to attack: ";
    noPointsLeft();
    return;
  }
  std::cout<<"ClapTrap "<<_name<<" attacks "<<target<<", causing "\
  <<_attackDamage<<" points of damage!";
  _energyPoints--;
  std::cout<<" ClapTrap "<<_name<<" has now "<<_energyPoints<<" energy points left."<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout<<"ClapTrap "<<_name<<" takes damage, losing "<<amount;
  if (amount == 1)
    std::cout<<" hit point!";
  else
	std::cout<<" hit points!";
  _hitPoints-= amount;
  if(_hitPoints < 0)
    _hitPoints = 0;
  std::cout<<" ClapTrap "<<_name<<" has now "<<_hitPoints<<" hit points left."<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints == 0 || _hitPoints == 0) {
    std::cout<<"Alas! ClapTrap "<<_name<<" cannot be repaired: ";
    noPointsLeft();
    return ;
  }
  if (_hitPoints + amount > 10) {
    std::cout<<"ClapTrap "<<_name<<" cannot be repaired to have more than 10 hit points."<<std::endl;
    return ;
  }
  _hitPoints+=amount;
  _energyPoints-=1;
  std::cout<<"ClapTrap "<<_name<<" is being repaired with "<<amount;
  if (amount == 1)
    std::cout<<" hit point.";
else
    std::cout<<" hit points.";
  std::cout<<" ClapTrap "<<_name<<" has now "<<_hitPoints<<" hit points and "\
  <<_energyPoints<<" energy points!"<<std::endl;
}

/* ************************************************************************** */
/* HELPERS                                                                    */
/* ************************************************************************** */

void ClapTrap::noPointsLeft() const {
  if (_hitPoints == 0)
    std::cout<<"No hit points left!"<<std::endl;
  else
    std::cout<<"No energy points left!"<<std::endl;
}