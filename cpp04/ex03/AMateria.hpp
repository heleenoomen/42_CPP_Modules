/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:35:43 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 12:46:31 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
 protected:
  std::string _type;

 public:
  /* constructors */
  AMateria();
  AMateria(std::string const & type);

  /* copy constructor */
  AMateria(AMateria const& src);

  /* copy assingment operator */
  AMateria& operator=(AMateria const& rhs);

  /* destructor */
  virtual ~AMateria();

  /* getter */
  std::string const & getType() const;
  bool _typeDoesNotExist() const;

  /* methods */
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif