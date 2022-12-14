/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:40:26 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 17:31:40 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 protected:
  std::string type_;

 public:
  /* default constructor */
  WrongCat();

  /* copy constructor */
  WrongCat(WrongCat const& src);

  /* copy assignment operator */
  WrongCat& operator=(WrongCat const& rhs);

  /* destructor */
  ~WrongCat();

  /* getter */
  std::string const& getType() const;

  virtual void makeSound() const;
};

#endif