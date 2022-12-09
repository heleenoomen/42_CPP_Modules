/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:05:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 21:15:51 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASRC_HPP
#define MATERIASRC_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#include <string>

class MateriaSource : public IMateriaSource {
 private:
  AMateria* _materias[4];
  int _nbrOfAmaterias;
  void _initMaterias();

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
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif