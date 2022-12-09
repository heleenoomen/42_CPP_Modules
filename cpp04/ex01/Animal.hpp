/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:40:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 13:20:33 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
 protected:
  std::string _type;

 public:
  /* default constructor */
  Animal();

  /* copy constructor */
  Animal(Animal const& src);

  /* copy assignment operator */
  Animal& operator=(Animal const& rhs);

  /* destructor */
  virtual ~Animal();

  /* getter */
  virtual std::string const& getType() const;

  /* public method */
  virtual void makeSound() const;
};

#endif