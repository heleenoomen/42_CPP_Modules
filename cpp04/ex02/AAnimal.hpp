/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:40:26 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 17:26:47 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
 protected:
  std::string type_;

 public:
  /* default constructor */
  AAnimal();

  /* copy constructor */
  AAnimal(AAnimal const& src);

  /* copy assignment operator */
  virtual AAnimal& operator=(AAnimal const& rhs);

  /* destructor */
  virtual ~AAnimal();

  /* getters */
  std::string const& getType() const;
  virtual std::string const& getIdea(int index) const;

  /* setter */
  virtual void setIdea(int index, std::string const& idea);

  /* public method */
  virtual void makeSound() const = 0;
};

#endif