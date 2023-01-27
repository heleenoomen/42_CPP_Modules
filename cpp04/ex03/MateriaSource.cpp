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

#include "layout.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* default constructor */
MateriaSource::MateriaSource() : nbrOfMaterias_(0) {
  std::cout << layout::grey << "MateriaSource default constructor called\n"
            << layout::reset;
  _setAllMateriasToNull();
}

/* string constructor */
MateriaSource::MateriaSource(std::string const& name)
    : name_(name), nbrOfMaterias_(0) {
  std::cout << layout::grey << "MateriaSource string constructor called for "
            << name_ << "\n"
            << layout::reset;
  _setAllMateriasToNull();
}

/* copy constructor */
MateriaSource::MateriaSource(MateriaSource const& src) : name_(src.name_) {
  std::cout << layout::grey << "MateriaSource copy constructor called\n"
            << layout::reset;
  _setAllMateriasToNull();
  *this = src;
}

/* copy assignment operator */
MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
  if (this == &src) return *this;
  _deleteAllMaterias();
  for (int i = 0; i < src.nbrOfMaterias_; ++i)
    materias_[i] = src.materias_[i]->clone();
  nbrOfMaterias_ = src.nbrOfMaterias_;
  return *this;
}

/* destructor */
MateriaSource::~MateriaSource() {
  std::cout << layout::grey << "MateriaSource destructor called\n"
            << layout::reset;
  _deleteAllMaterias();
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& MateriaSource::getName() const { return name_; }

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < MateriaSource::maxNbrOfMaterias_; ++i) {
    if (materias_[i] == NULL) {
      materias_[i] = m;
      ++nbrOfMaterias_;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) const {
  for (int i = 0; i < MateriaSource::maxNbrOfMaterias_; ++i) {
    if (materias_[i]->getType() == type) return materias_[i]->clone();
  }
  return NULL;
}

void MateriaSource::printMaterias() const {
  for (int i = 0; i < MateriaSource::maxNbrOfMaterias_; ++i) {
    if (materias_[i] != NULL)
      std::cout << "Materia nbr " << i << ": " << materias_[i]->getType()
                << '\n';
  }
}

/* ************************************************************************** */
/* Privated methods                                                           */
/* ************************************************************************** */

void MateriaSource::_setAllMateriasToNull() {
  for (int i = 0; i < MateriaSource::maxNbrOfMaterias_; ++i)
    materias_[i] = NULL;
}

void MateriaSource::_deleteAllMaterias() {
  for (int i = 0; i < MateriaSource::maxNbrOfMaterias_; ++i) {
    delete materias_[i];
    materias_[i] = NULL;
  }
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, MateriaSource const& m) {
  o << layout::greenBold << "Name: " << m.getName() << "\n"
    << "Materias learned:\n";
  m.printMaterias();
  o << layout::reset;
  return o;
}
