/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:44:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 09:54:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

/* Default constructor */
Cat::Cat() {
  std::cout << "Cat default constructor called\n";
  type_ = "Cat";
}

/* Copy constructor */
Cat::Cat(Cat const& src) : Animal(src) {
  std::cout << "Cat copy constructor called\n";
}

/* Copy assignment operator */
Cat& Cat::operator=(Cat const& rhs) {
  std::cout << "Cat copy assignment operator called\n";
  Animal::operator=(rhs);
  return *this;
}

/* Destructor */
Cat::~Cat() { std::cout << "Cat destructor called\n"; }

/* Public method */
void Cat::makeSound() const { std::cout << "Meow\n"; }
