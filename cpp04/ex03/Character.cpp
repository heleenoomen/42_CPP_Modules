/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:20:04 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 16:58:39 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

#include "layout.hpp"

static int const empty = 0;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Character::Character() : name_("Default"), inventorySize_(empty) {
  std::cout << layout::grey << "Character default constructor called\n"
            << layout::reset;
  initializeInventory_();
}

/* Parametric constructor */
Character::Character(std::string const& name)
    : name_(name), inventorySize_(empty) {
  std::cout << layout::grey << "Character parametric constructor called\n"
            << layout::reset;
  initializeInventory_();
}

/* Copy constructor */
Character::Character(Character const& src) : name_(src.name_) {
  initializeInventory_();
  *this = src;
}

/* Copy assignment operator */
Character& Character::operator=(Character const& rhs) {
  std::cout << layout::grey << "Character copy assignment operator called\n"
            << layout::reset;
  if (this == &rhs) return *this;
  inventorySize_ = rhs.inventorySize_;
  deepCopyInventory_(rhs);
  return *this;
}

/* Destructor */
Character::~Character() {
  std::cout << layout::grey << "Character destructor called\n" << layout::reset;
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
  if (m->typeDoesNotExist() || inventoryFull_()) return;
  insertMateriaInFirstFreeSlot_(m);
  ++inventorySize_;
}

void Character::unequip(int idx) {
  if (indexOutOfRangeForInventory_(idx)) return;
  inventory_[idx] = NULL;
  --inventorySize_;
}

void Character::use(int idx, ICharacter& target) {
  if (indexOutOfRangeForInventory_(idx) || inventory_[idx] == NULL) return;
  inventory_[idx]->use(target);
}

void Character::printInventory() const {
  std::cout << layout::magentaBold;
  for (int i = 0; i < inventoryMaxSize_; ++i) {
    std::cout << "* Inventory slot " << i << ": ";
    if (inventory_[i] != NULL)
      std::cout << inventory_[i]->getType() << " *\n";
    else
      std::cout << "EMPTY *\n";
  }
  std::cout << layout::reset;
}
/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Character::initializeInventory_() {
  for (int i = 0; i < Character::inventoryMaxSize_; ++i) inventory_[i] = NULL;
}

void Character::emptyInventory() {
  for (int i = 0; i < inventoryMaxSize_; ++i) {
    delete inventory_[i];
    inventory_[i] = NULL;
  }
}

void Character::copyIndividualMaterias(Character const& src) {
  for (int i = 0; i < src.inventoryMaxSize_; ++i) {
    if (src.inventory_[i] != NULL) inventory_[i] = src.inventory_[i]->clone();
  }
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
    if (inventory_[i] == NULL) return i;
  }
  return 0;
}

/* Only use if intventoryFull_ returned false! */
void Character::insertMateriaInFirstFreeSlot_(AMateria* m) {
  inventory_[findFirstFreeSlot_()] = m;
}

bool Character::indexOutOfRangeForInventory_(int index) const {
  if (index < 0 || index >= Character::inventoryMaxSize_) return true;
  return false;
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Character const& c) {
  o << layout::greenBold << "Name: " << c.getName() << '\n';
  c.printInventory();
  o << layout::reset;
  return o;
}
