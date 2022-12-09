/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:40:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 09:54:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "Animal.hpp"

class Dog : public Animal {
 public:
  /* default constructor */
  Dog();

  /* copy constructor */
  Dog(Dog const& src);

  /* copy assignment operator */
  Dog& operator=(Dog const& rhs);

  /* destructor */
  virtual ~Dog();

  virtual void makeSound() const;
};

#endif