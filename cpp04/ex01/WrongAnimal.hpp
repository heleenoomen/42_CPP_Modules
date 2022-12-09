/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:40:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 09:54:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
 protected:
  std::string _type;

 public:
  /* default constructor */
  WrongAnimal();

  /* copy constructor */
  WrongAnimal(WrongAnimal const& src);

  /* copy assignment operator */
  WrongAnimal& operator=(WrongAnimal const& rhs);

  /* destructor */
  virtual ~WrongAnimal();

  /* getter */
  std::string const& getType() const;

  void makeSound() const;
};

#endif