/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:25:38 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 19:50:31 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>

class Character : public ICharacter {
 private:
  static int const inventoryMaxSize_ = 4;

  /* private attributes */
  std::string name_;
  AMateria* inventory_[Character::inventoryMaxSize_];
  int inventorySize_;

  /* private helpers */
  void initializeInventory_();
  bool inventoryFull_() const;
  void deepCopyInventory_(Character const& src);
  void copyIndividualMaterias(Character const& src);
  void emptyInventory();
  void insertMateriaInFirstFreeSlot_(AMateria* m);
  int findFirstFreeSlot_() const;
  bool indexOutOfRangeForInventory_(int index) const;

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