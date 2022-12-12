/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:05:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 12:30:07 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASRC_HPP
#define MATERIASRC_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#include <string>

class MateriaSource : public IMateriaSource {
 private:
  static int const _maxNbrOfMaterias = 4;
  AMateria* _materias[MateriaSource::_maxNbrOfMaterias];
  int _nbrOfAmaterias;

  /*private helpers */
  void _setAllMateriasToNull();
  void _deleteAllMaterias();

 public:
  /* constructor */
  MateriaSource();

  /* copy constructor */
  MateriaSource(MateriaSource const&);

  /* copy assignment operator */
  MateriaSource& operator=(MateriaSource const&);

  /* destructor */
  virtual ~MateriaSource();

  /* public methods*/
  virtual void learnMateria(AMateria*);
  virtual AMateria* createMateria(std::string const& type);
};

#endif