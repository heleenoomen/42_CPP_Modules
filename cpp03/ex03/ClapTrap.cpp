/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:31:32 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/08 17:27:51 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

/* ************************************************************************** */
/* CONSTRUCTORS                                                               */
/* ************************************************************************** */

ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
  return;
}

ClapTrap::ClapTrap(ClapTrap const& src) {
  std::cout << "ClapTrap copy constructor called for " << src.getName()
            << std::endl;
  *this = src;
  return;
}

ClapTrap::ClapTrap(std::string const& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap string constructor called for " << _name << std::endl;
  return;
}

ClapTrap::ClapTrap(int hitPoints, int energyPoints, int attackDamage)
    : _name("Default"),
    _hitPoints(hitPoints),
    _energyPoints(energyPoints),
    _attackDamage(attackDamage) {
  std::cout << "ClapTrap int constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const& name, int hitPoints, int energyPoints,
                   int attackDamage)
    : _name(name),
      _hitPoints(hitPoints),
      _energyPoints(energyPoints),
      _attackDamage(attackDamage) {
  std::cout << "ClapTrap parametric constructor called (string + int + int + "
               "int) for "
            << _name << std::endl;
  return;
}

/* ************************************************************************** */
/* COPY ASSIGNMENT OPERATOR                                                   */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
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
  std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

/* ************************************************************************** */
/* GETTERS                                                                    */
/* ************************************************************************** */

std::string const& ClapTrap::getName() const { return _name; }

int ClapTrap::getHitPoints() const { return _hitPoints; }

int ClapTrap::getEnergyPoints() const { return _energyPoints; }

int ClapTrap::getAttackDamage() const { return _attackDamage; }

/* ************************************************************************** */
/* SETTERS                                                                    */
/* ************************************************************************** */

void ClapTrap::decrEnergyPoints() { _energyPoints--; }

void ClapTrap::setEnergyPoints(int amount) {
  if (amount >= 0)
    _energyPoints = amount;
}

void ClapTrap::setHitPoints(int amount) {
  if (amount >= 0)
    _hitPoints = amount;
}

void ClapTrap::setAttackDamage(int amount) {
  if (amount >= 0)
    _attackDamage = amount;
}

/* ************************************************************************** */
/* ACTIONS                                                                    */
/* ************************************************************************** */

void ClapTrap::attack(std::string const& target) {
  if (_energyPoints == 0 || _hitPoints == 0) {
    std::cout << "ClapTrap " << _name << " is unable to attack: ";
    noPointsLeft();
    return;
  }
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage;
  printPoints(_attackDamage);
  std::cout << " of damage!";
  _energyPoints--;
  std::cout << " ClapTrap " << _name << " has " << _energyPoints << " energy";
  printPoints(_energyPoints);
  std::cout << " left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << _name << " takes damage, losing " << amount
            << " hit";
  printPoints(amount);
  _hitPoints -= amount;
  if (_hitPoints < 0) _hitPoints = 0;
  std::cout << ". ClapTrap " << _name << " has " << _hitPoints << " hit";
  printPoints(_hitPoints);
  std::cout << " left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints == 0 || _hitPoints == 0) {
    std::cout << "Alas! ClapTrap " << _name << " cannot be repaired: ";
    noPointsLeft();
    return;
  }
  if (_hitPoints + amount > 10) {
    std::cout << "ClapTrap " << _name
              << " cannot be repaired to have more than 10 hit points."
              << std::endl;
    return;
  }
  _hitPoints += amount;
  _energyPoints -= 1;
  std::cout << "ClapTrap " << _name << " is being repaired with " << amount
            << " hit";
  printPoints(amount);
  std::cout << ". ClapTrap " << _name << " has now " << _hitPoints << " hit";
  printPoints(_hitPoints);
  std::cout << " and " << _energyPoints << " energy";
  printPoints(_energyPoints);
  std::cout << " left!" << std::endl;
}

/* ************************************************************************** */
/* HELPERS                                                                    */
/* ************************************************************************** */

void ClapTrap::noPointsLeft() const {
  if (getHitPoints() == 0)
    std::cout << "No hit points left!" << std::endl;
  else
    std::cout << "No energy points left!" << std::endl;
}

void ClapTrap::printPoints(unsigned int amount) const {
  if (amount == 1)
    std::cout << " point";
  else
    std::cout << " points";
}
