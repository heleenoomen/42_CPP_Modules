/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:42:19 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 12:10:35 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
 public:
  /* constructors */
  Cure();
  
  /* copy constructor */
  Cure(Cure const& src);

  /* assignment operator */
  Cure& operator=(Cure const& rhs);

  /* destructor */
  ~Cure();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif