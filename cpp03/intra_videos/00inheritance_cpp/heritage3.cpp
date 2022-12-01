/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage3.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:06:13 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/01 14:22:48 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Leg {
};

class Quadruped {
  public:
   void run(); // Accessible from wherever

  protected:
   Leg legs[4]; // Accessible form a Quadruped or derived object (e.g. Dog)

  private:
   std::string name; // Only accessible from a Quadruped object
};

class Dog : public Quadruped { // can access run() and legs
};

int main() { // can only access run()
	return 0;
}

/*
 To inherit you had to write 'pulic : <PARENT_CLASS>'
 There is also a way to use 'protected' and 'private'
 These are the encapsulation levels of inheritance

 Also, there is something called 'multiple inheritance'
 So far, what we have seen was only 'simple inheritance', where we inherit from
 one class at a time: the dog inherits from the quadruped, the cat inherited from
 the animal, etc.
 
 In multiple inheritance, the dog could inherit from both the quadruped and the animal
 This creates trouble: if both parent classes have a certain behaviour, how do we know
 which one of them is going to be inherited by the dog? Or how do you specify that you 
 want to inherit that behaviour form 'Animal' and not from 'Quadruped'?

 Then there is the 'diamond inheritance'
*/