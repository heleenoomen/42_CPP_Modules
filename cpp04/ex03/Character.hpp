/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:25:38 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 16:02:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>

class Character : public ICharacter {
 private:
  static int const _maxNbrOfMaterias = 4;

  /* private attributes */
  std::string _name;
  AMateria* _materias[Character::_maxNbrOfMaterias];
  int _nbrOfMaterias;

  /* private helpers */
  void _setAllMateriasToNull();
  bool _inventoryIsFull() const;
  void _insertMateriaInFirstFreeSlot(AMateria* m);
  int _findFirstFreeSlot() const;
  bool _materiasIndexOutOfRange(int index) const;
  void _deleteExistingMaterias();
  bool _materiaTypeDoesNotExist(AMateria *m);

 public:
  /* Constructors */
  Character();
  Character(std::string const& name);

  /* Copy constructor */
  Character(Character const& src);

  /* Copy assignment operator */
  Character& operator=(Character const& rhs);

  /* Destructor */
  ~Character();
  
  /* Getter */
  std::string const& getName() const;

  /* Public methods */
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};

#endif