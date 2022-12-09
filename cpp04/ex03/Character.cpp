/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:20:04 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 21:21:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

/* Default constructor */
Character::Character()
      : _name(""),
        _nbrOfMaterias(0) { 
  std::cout << "Character default constructor called" << std::endl;
  _initMaterias();
}

/* Parametric constructor */
Character::Character(std::string const& name) 
    : _name(name),
      _nbrOfMaterias(0) {
  std::cout << "Character parametric constructor called" << std::endl;
  _initMaterias();
}

/* Copy constructor */
Character::Character(Character const& src) {
  _initMaterias();
  *this = src;
}

/* Copy assignment operator */
Character& Character::operator=(Character const& rhs) {
  std::cout << "Character copy assignment operator called" << std::endl;
  _name = rhs._name;
  _nbrOfMaterias = rhs._nbrOfMaterias;
  for (int i = 0; i < 4; i++)
    delete _materias[i];
  for (int i = 0; i < _nbrOfMaterias; i++)
    _materias[i] = rhs._materias[i].clone();
}

/* Destructor */
Character::~Character() {
  std::cout << "Character destructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    delete _materias[i];
}

/* Helper (private) */
void Character::_initMaterias() {
  for (int i = 0; i < 4; i++)
    _materias[i] = NULL;
}

/* Public methods */
void Character::equip(AMateria* m) {
  if (m->getType != "ice" && m->getType != "cure")
    return ;
  for (int i = 0; i < 4; i++)
  {
    if (_materias[i] == NULL) {
      _materias[i] = m->clone;
      _nbrOfMaterias++;
      break ;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3)
    return ;
  _materias[idx] = NULL;
  _nbrOfMaterias--;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3 || materias[idx] == NULL)
    return ;
  _materias[idx].use(target);
}

