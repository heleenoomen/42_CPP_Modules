/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:42:19 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/09 18:02:04 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  /* constructors */
  Ice();

  /* copy constructor */
  Ice(Ice const& src);

  /* assignment operator */
  Ice& operator=(Ice const& rhs);

  /* destructor */
  ~Ice();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif