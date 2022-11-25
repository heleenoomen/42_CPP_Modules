/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 13:05:56 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class Sample {

public:

	int	foo;

	Sample( void );
	~Sample( void );

	static int	getNbInst( void );  // non member function 


private:

	static int	_nbInst;  // non member attribute

};

#endif

// Both non member attribute & non member function are precede by the static
// keyword.
// The counter keeps track of the number of instances of this class that have
// been made at any given moment
// It does not make sense to have this counter inside a specific instance
// this info makes sense only at the class level, not at the instance level.
// The class wants to know how many instances have been made. For this, we use
// a non member integer, declared as static: _nbInst.
// This non member is private, it cannot be accessed from outside the class.
// It can only be accessed by a function inside, that can either be a member or
// a non member.
// In the above example, a non member function was chosen

// Inside of a class, there also can exist non member functions and non member 
// attributes. You often see these referred to as 'instance variables' and 'instance
// functions' for member attributes and functions,
// versus 'class variables and functions' for non-member variables and functions

// A member function or attriute is something present in the instance of our class
// It means that the class needs to be instantiated for us to use this attribute
// and this function.
// Another property of member attributes, is that each attribute will be different
// in every instance.
// If two instances of the same class have an integer attribute, if you change the
// attribute on one side, it won't be changed on the other. Otherwise it woul be a
// mess.

// But we could image that this behaviour is actually what we want in our code:
// Variables and functions existing at the class level and not at the instance level.
// That is why we will talk about class variables and functions not at the instance
// level. One way to call these is: non member attributes and non member functions.

// To be able to have this behaviour in C++, we will use the 'static' keyword.
// I C this would allow you to allocate a variable in a particular location in 
// your rubable where you could get the value by calling functions, have it locally
// in the compilation unit, et cetera.

// In the context of C++ 'static' has a new semantic.