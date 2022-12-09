/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:40:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 18:00:16 by hoomen           ###   ########.fr       */
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
  virtual Animal& operator=(Animal const& rhs);

  /* destructor */
  virtual ~Animal();

  /* getters */
  std::string const& getType() const;
  virtual std::string const& getIdea(int index) const;

  /* setter */
  virtual void setIdea(int index, std::string const& idea);

  /* public method */
  virtual void makeSound() const;

  virtual void printIdeas() const;
};

#endif