/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:58:09 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 21:05:30 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() : _nbrOfAmaterias(0) {
  std::cout << "MateriaSource default constructor called" << std::endl;
  _setAllMateriasToNull();
}

MateriaSource::MateriaSource(MateriaSource const& src) {
  std::cout << "MateriaSource copy constructor called" << std::endl;
  _setAllMateriasToNull();
  *this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
  _deleteAllMaterias();
  for (int i = 0; i < src._nbrOfAmaterias; ++i)
    _materias[i] = src._materias[i]->clone();
  _nbrOfAmaterias = src._nbrOfAmaterias;
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource destructor called" << std::endl;
  _deleteAllMaterias();
}

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < MateriaSource::_maxNbrOfMaterias; ++i) {
    if (_materias[i] == NULL) {
      _materias[i] = m;
      ++_nbrOfAmaterias;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < MateriaSource::_maxNbrOfMaterias; ++i) {
    if (_materias[i]->getType() == type)
      return _materias[i]->clone();
  }
  return NULL;
}

void MateriaSource::_setAllMateriasToNull() {
  for (int i = 0; i < MateriaSource::_maxNbrOfMaterias; ++i)
    _materias[i] = NULL;
}

void MateriaSource::_deleteAllMaterias() {
  for (int i = 0; i < MateriaSource::_maxNbrOfMaterias; ++i) {
    delete _materias[i];
    _materias[i] = NULL;
  }
}
