/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:01:09 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 18:26:44 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test(Animal const& animal) {
  std::cout << "Type: " << animal.getType() << ", sound: ";
  animal.makeSound();
}

int main() {
  /* Test correct deletion Cat/Dog instances via pointer of parent class Animal */
  std::cout << "\033[48:5:208m -----### TEST CORRECT DELETION CAT/DOG VIA "
               "POINTERS TO ANIMAL) ###-----\033[0m"
            << std::endl;
  {
    std::cout << "\033[1;33m ---Declare array of Aninmal pointers---\033[0m" << std::endl;
    const Animal* animalArray[6];

    std::cout << "\033[1;33m ---Construct Dogs and Cats---\033[0m" << std::endl;
    for (int i = 0; i < 3; i++)
      animalArray[i] = new Dog;
    for (int i = 3; i < 6; i++)
      animalArray[i] = new Cat;
  
    std::cout << "\033[1;33m ---Test types and sounds---\033[0m" << std::endl;
    for (int i = 0; i < 6; i++) {
      std::cout << "Type: " << animalArray[i]->getType()
                << ". Sound: ";
      animalArray[i]->makeSound();
    }
    std::cout << "\033[1;33m ---Destruct Cat and Dog objects---\033[0m" << std::endl;
    for (int i = 0; i < 6; i++)
        delete animalArray[i];
    std::cout << std::endl;
  
    std::cout << "\033[1;33m -----### CHECK LEAKS ###-----\033[0m"
              << std::endl;
    system("leaks animals");
  }
  std::cout << std::endl;

  /* Test deep copies */
  std::cout << "\033[48:5:208m -----### TEST DEEP COPIES ###-----\033[0m"
            << std::endl;
  {
    std::cout << "\033[1;33m ---Default constructor (dog1)---\033[0m" << std::endl;
    Dog* dog1 = new Dog;

    std::cout << "\033[1;33m ---Test type and sound dog1---\033[0m" << std::endl;
    test(*dog1);

    std::cout << "\033[1;33m ---Set ideas for dog1---\033[0m" << std::endl;
    dog1->setIdea(0, "I would really like a walk in the park");
    dog1->setIdea(1, "Gotta sniff this");
    dog1->setIdea(2, "Gotta catch that dove!");
    dog1->setIdea(3, "I love my owner");
    dog1->setIdea(4, "They trew a stick! This is great, run!");
    std::cout << "\033[1;33m ---Print ideas dog1---\033[0m" << std::endl;
    dog1->printIdeas();

    std::cout << "\033[1;33m ---Default constructor (dog2)---\033[0m" << std::endl;
    Dog* dog2 = new Dog();

    std::cout << "\033[1;33m ---Test type and sound dog1---\033[0m" << std::endl;
    test(*dog1);

    std::cout << "\033[1;33m ---Copy assignment operator (dog2 = dog1)---\033[0m" << std::endl;
    *dog2 = *dog1;

    std::cout << "\033[1;33m ---Test type and sound dog2---\033[0m" << std::endl;
    test(*dog2);

    std::cout << "\033[1;33m ---Delete dog 1---\033[0m" << std::endl;
    delete dog1;

    std::cout << "\033[1;33m ---Print ideas dog2 after deletion dog 1---\033[0m" << std::endl;
    dog2->printIdeas();

    std::cout << "\033[1;33m ---Copy constructor (dog3 copied from dog2)---\033[0m" << std::endl;
    Dog* dog3 = new Dog(*dog2);

    std::cout << "\033[1;33m ---Delete dog 2---\033[0m" << std::endl;
    delete dog2;

    std::cout << "\033[1;33m ---Print ideas dog 3 after deletion dog 2---\033[0m" << std::endl;
    dog3->printIdeas();
    std::cout << "\033[1;33m ---Test type and sound dog3---\033[0m" << std::endl;
    test(*dog3);
    std::cout << "\033[1;33m ---Delete dog 3---\033[0m" << std::endl;
    delete dog3;
 
    std::cout << "\033[1;33m ---Default constructor cat1---\033[0m" << std::endl;
    Cat* cat1 = new Cat;
    std::cout << "\033[1;33m ---Test type and sound cat1---\033[0m" << std::endl;
    test(*cat1);

    std::cout << "\033[1;33m ---Set ideas for cat1---\033[0m" << std::endl;
    cat1->setIdea(0, "Meeeow, I am a beautiful cat");
    cat1->setIdea(1, "Meeeow, gotta sleep");
    cat1->setIdea(2, "It is my hoooooooooman");
    cat1->setIdea(3, "my hoooooman left the kitchen, gotta steal cheese now");
    cat1->setIdea(4, "Caught a mouse for my hoooman");
    cat1->setIdea(5, "Let's be honest: hooooomans are pretty stupid, but you got to love them");
    cat1->setIdea(6, "More food please!");
    std::cout << "\033[1;33m ---Print ideas cat1---\033[0m" << std::endl;
    cat1->printIdeas();

    std::cout << "\033[1;33m ---Copy constructor (cat 2 copied from cat1)---\033[0m" << std::endl;
    Cat* cat2 = new Cat(*cat1);

    std::cout << "\033[1;33m ---Delete cat1 object---\033[0m" << std::endl;
    delete cat1;

    std::cout << "\033[1;33m ---Print ideas cat2 after deletion cat1---\033[0m" << std::endl;
    cat2->printIdeas();
    std::cout << "\033[1;33m ---Test type and sound cat2---\033[0m" << std::endl;
    test(*cat2);

    std::cout << "\033[1;33m ---Delete cat2 object---\033[0m" << std::endl;
    delete cat2;
    std::cout << std::endl;
  
    std::cout << "\033[1;33m -----### CHECK LEAKS ###-----\033[0m"
              << std::endl;
    system("leaks animals");
  }
  std::cout << std::endl;
  
  std::cout << "\033[48:5:208m -----### CHECK LEAKS ###-----\033[0m"
            << std::endl;
  system("leaks animals");
}
