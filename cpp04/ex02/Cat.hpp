/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:40:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 09:54:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 private:
  Brain* brain_;

 public:
  /* default constructor */
  Cat();

  /* copy constructor */
  Cat(Cat const& src);

  /* copy assignment operator */
  Cat& operator=(Cat const& rhs);

  /* destructor */
  virtual ~Cat();

  /* getters */
  std::string const& getIdea(int index) const;

  /* setter */
  void setIdea(int index, std::string const& idea);

  /* public methods */
  virtual void makeSound() const;
  void printIdeas() const;
};

#endif