/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:20:04 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/09 11:48:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Layout.hpp"

#include <iostream>

static int const empty = 0;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Character::Character() : name_("Default"), inventorySize_(empty) { 
  std::cout << Layout::grey << "Character default constructor called\n"
            << Layout::reset;
  initializeInventory_();
}

/* Parametric constructor */
Character::Character(std::string const& name) : name_(name), inventorySize_(empty) {
  std::cout << Layout::grey << "Character parametric constructor called\n"
            << Layout::reset;
  initializeInventory_();
}

/* Copy constructor */
Character::Character(Character const& src) {
  *this = src;
}

/* Copy assignment operator */
Character& Character::operator=(Character const& rhs) {
  std::cout << Layout::grey << "Character copy assignment operator called\n"
            << Layout::reset;
  if (this == &rhs)
    return *this;
  name_ = rhs.name_;
  inventorySize_ = rhs.inventorySize_;
  deepCopyInventory_(rhs);
  return *this;
}

/* Destructor */
Character::~Character() {
  std::cout << Layout::grey << "Character destructor called\n" << Layout::reset;
  emptyInventory();
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& Character::getName() const { return name_; }

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Character::equip(AMateria* m) {
  if (m->typeDoesNotExist() || inventoryFull_())
    return ;
  insertMateriaInFirstFreeSlot_(m);
  ++inventorySize_;
}

void Character::unequip(int idx) {
  if (indexOutOfRangeForInventory_(idx))
    return ;
  inventory_[idx] = NULL;
  --inventorySize_;
}

void Character::use(int idx, ICharacter& target) {
  if (indexOutOfRangeForInventory_(idx) || inventory_[idx] == NULL)
    return ;
  inventory_[idx]->use(target);
}

void Character::printInventory() const {
  std::cout << Layout::magentaBold;
  for (int i = 0; i < inventoryMaxSize_; ++i) {
    std::cout << "* Inventory slot " << i << ": ";
    if (inventory_[i] != NULL)
      std::cout << inventory_[i]->getType() << " *\n";
    else
      std::cout << "EMPTY *\n";
  }
  std::cout << Layout::reset;
}
/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Character::initializeInventory_() {
  for (int i = 0; i < Character::inventoryMaxSize_; ++i)
    inventory_[i] = NULL;
}

void Character::emptyInventory() {
  for (int i = 0; i < inventoryMaxSize_; ++i) {
    delete inventory_[i];
    inventory_[i] = NULL;
  }
}

void Character::copyIndividualMaterias(Character const& src) {
  for (int i = 0; i < inventoryMaxSize_; ++i)
    inventory_[i] = src.inventory_[i]->clone();
}

void Character::deepCopyInventory_(Character const& src) {
  emptyInventory();
  copyIndividualMaterias(src);
}

bool Character::inventoryFull_() const {
  return inventorySize_ >= Character::inventoryMaxSize_;
}

/* Only use if intenvtoryFull_ returned false! */
int Character::findFirstFreeSlot_() const {
  for (int i = 0; i < Character::inventoryMaxSize_; ++i) {
    if (inventory_[i] == NULL)
      return i;
  }
  return 0;
}

/* Only use if intventoryFull_ returned false! */
void Character::insertMateriaInFirstFreeSlot_(AMateria* m) {
  inventory_[findFirstFreeSlot_()] = m;
}

bool Character::indexOutOfRangeForInventory_(int index) const {
  if (index < 0 || index >= Character::inventoryMaxSize_)
    return true;
  return false;
}
