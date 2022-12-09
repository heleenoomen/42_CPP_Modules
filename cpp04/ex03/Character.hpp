/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:25:38 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 20:44:33 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string const& _name;
  AMateria *_materias[4];
  int _nbrOfMaterias;
  void _initMaterias();

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

  /* Public methods */
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif