/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:51:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/01 14:03:10 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Animal {
 public:
  Animal();
  Animal(Animal const&);
  Animal& operator=(Animal const&);
  ~Animal();

  void run(int distance);
  void call();
  void eat(std::string const& what);
  void walk(int distance);

 private:
  int _numberOfLegs();
};

class Cat : public Animal {
 public:
  Cat();
  Cat(Cat const&);
  Cat& operator=(Cat const&);

  void scornSomeone(std::string const& target);
};
/* the cat inherits from the Animal publicly. This means:
    * the cat is an animal in every aspect
    * it is not ONLY an animal: it has its own behaviour
	* The cat will be able to call eat() and walk() from
	  the animal class, it will inherit these behaviours (these member functions)
*/

class Pony : public Animal {
 public:
  Pony();
  Pony(Pony const&);
  Pony& operator=(Pony const&);
  ~Pony();

  void doMagic(std::string const& target);
  void run(int distance);
};
/* the pony is also an animal. It has all the behaviours from the
   animal class, plus its own behaviours ('do Magic')
   Animals have a general way of running.
   The pony might have a specific way of running, which replaces the
   general animals one.
*/

/* Explore further:
    * how to call the constructor for the parent class?
	* how to make sure the destructors are called for both classes?
*/

/* In order to instantiate a cat (or a pony) we will have to instantiate
   an animal first.
*/