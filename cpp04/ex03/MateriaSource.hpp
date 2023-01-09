/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:05:45 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/09 12:44:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASRC_HPP
#define MATERIASRC_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#include <string>

class MateriaSource : public IMateriaSource {
 private:
  std::string const name_;
  static int const maxNbrOfMaterias_ = 4;
  AMateria* materias_[MateriaSource::maxNbrOfMaterias_];
  int nbrOfMaterias_;

  /*private helpers */
  void _setAllMateriasToNull();
  void _deleteAllMaterias();

 public:
  /* constructor */
  MateriaSource();
  MateriaSource(std::string const& name);

  /* copy constructor */
  MateriaSource(MateriaSource const&);

  /* copy assignment operator */
  MateriaSource& operator=(MateriaSource const&);

  /* destructor */
  virtual ~MateriaSource();

  /* getter */
  std::string const& getName() const;

  /* public methods*/
  virtual void learnMateria(AMateria*);
  virtual AMateria* createMateria(std::string const& type) const;
  void printMaterias() const;
};

/* insertion operator */
std::ostream& operator<<(std::ostream& o, MateriaSource const& m);
#endif