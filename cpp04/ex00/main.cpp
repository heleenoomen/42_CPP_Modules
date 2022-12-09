/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:01:09 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 17:49:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "\033[48:5:208m -----### TEST ANIMAL INHERITANCE (RIGHT "
               "CLASSES) ###-----\033[0m"
            << std::endl;
  {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
  }
  std::cout << std::endl;
  std::cout << "\033[48:5:208m -----### TEST ANIMAL INHERITANCE (WRONG "
               "CLASSES) ###-----\033[0m"
            << std::endl;
  {
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;
  }
  std::cout << std::endl;
  std::cout << "\033[48:5:208m -----### TEST COPYING ###-----\033[0m" 
            << std::endl;
  {
    std::cout << "\033[1;33m ---Default constructor (dog1)---\033[0m" << std::endl;
    Dog dog1;
    std::cout << "\033[1;33m ---Dog1 type and sound---\033[0m" << std::endl;
    std::cout << dog1.getType() << std::endl;
    dog1.makeSound();
    std::cout << "\033[1;33m ---Copy constructor (dog2 copied from dog1)---\033[0m" << std::endl;
    Dog dog2(dog1);
    std::cout << "\033[1;33m ---Dog2 type and sound---\033[0m" << std::endl;
    std::cout << dog2.getType() << std::endl;
    dog2.makeSound();
    std::cout << "\033[1;33m ---Destructors---\033[0m" << std::endl;
  }
  
  system("leaks animals");
  return 0;
}