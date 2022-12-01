/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage1.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:51 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/01 13:51:49 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Cat {
 public:
  Cat();
  Cat(Cat const&);
  Cat& operator=(Cat const&);
  ~Cat();

  void run(int distance);
  void scornSomeone(std::string const& target);

 private:
  int _numberOfLegs;
};

class Pony {
 public:
  Pony();
  Pony(Pony const&);
  Pony& operator=(Pony const&);
  ~Pony();

 void run(int distance);

 void doMagic(std::string const& target);
};

/*
 imagine having to write many classes of animals with some attributes and
 functions in common (e.g. all have legs and all can run) and some other attributes
 that are unique to them (e.g. the cat can scorn someone, the pony can do magic).
 Here inheritance comes in handy: one general class 'animal' with all the shared
 properties, and many classes for specific animals that inherit from the general
 'animal' class
 See: heritage2.cpp
*/
