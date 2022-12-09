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
  _initMaterias();
}

MateriaSource::MateriaSource(MateriaSource const& src) {
  std::cout << "MateriaSource copy constructor called" << std::endl;
  _initMaterias();
  *this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
  for (int i = 0; i < 4; i++)
    delete _materias[i];
  for (int i = 0; i < 4; i++)
    _materias[i] = src._materias[i]->clone();
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource destructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    delete _materias[i];
}

void MateriaSource::learnMateria(AMateria* m) {
  for (int i; i < 4; i++) {
    if (_materias[i] == NULL) {
      _materias[i] = m->clone();
      _nbrOfAmaterias++;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i; i < 4; i++) {
    if (_materias[i]->getType() == type)
      return _materias[i]->clone();
  }
  return NULL;
}



