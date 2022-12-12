/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:20:04 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 16:07:12 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

/* Default constructor */
Character::Character() : _name("Default"), _nbrOfMaterias(0) { 
  std::cout << "Character default constructor called" << std::endl;
  _setAllMateriasToNull();
}

/* Parametric constructor */
Character::Character(std::string const& name) : _name(name), _nbrOfMaterias(0) {
  std::cout << "Character parametric constructor called" << std::endl;
  _setAllMateriasToNull();
}

/* Copy constructor */
Character::Character(Character const& src) {
  *this = src;
}

/* Copy assignment operator */
Character& Character::operator=(Character const& rhs) {
  std::cout << "Character copy assignment operator called" << std::endl;
  _name = rhs._name;
  _nbrOfMaterias = rhs._nbrOfMaterias;
  _deleteExistingMaterias();
  for (int i = 0; i < rhs._nbrOfMaterias; ++i)
    _materias[i] = rhs._materias[i]->clone();
  return *this;
}

/* Destructor */
Character::~Character() {
  std::cout << "Character destructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    delete _materias[i];
}

/* Public methods */
void Character::equip(AMateria* m) {
  if (m->_typeDoesNotExist() || _inventoryIsFull())
    return ;
  _insertMateriaInFirstFreeSlot(m);
  ++_nbrOfMaterias;
}

void Character::unequip(int idx) {
  if (_materiasIndexOutOfRange(idx))
    return ;
  _materias[idx] = NULL;
  --_nbrOfMaterias;
}

void Character::use(int idx, ICharacter& target) {
  if (_materiasIndexOutOfRange(idx) || _materias[idx] == NULL)
    return ;
  _materias[idx]->use(target);
}

/* getter */
std::string const& Character::getName() const {
  return _name;
}

/* private helpers */
void Character::_setAllMateriasToNull() {
  for (int i = 0; i < Character::_maxNbrOfMaterias; ++i)
    _materias[i] = NULL;
}

bool Character::_inventoryIsFull() const {
  return _nbrOfMaterias >= Character::_maxNbrOfMaterias;
}

/* Only use if _intventoryIsFull returned false! */
void Character::_insertMateriaInFirstFreeSlot(AMateria* m) {
  _materias[_findFirstFreeSlot()] = m;
}

/* Only use if _intenvtoryIsFull returned false! */
int Character::_findFirstFreeSlot() const {
  for (int i = 0; i < Character::_maxNbrOfMaterias; ++i) {
    if (_materias[i] == NULL)
      return i;
  }
  return 0;
}

bool Character::_materiasIndexOutOfRange(int index) const {
  if (index < 0 || index >= Character::_maxNbrOfMaterias)
    return true;
  return false;
}

void Character::_deleteExistingMaterias() {
  for (int i = 0; i < Character::_maxNbrOfMaterias; ++i) {
    delete _materias[i];
    _materias[i] = NULL;
  }
}
