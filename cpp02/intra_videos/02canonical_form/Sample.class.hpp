/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:51:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/28 11:37:57 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

/*
Canonical form:

Copline form (?)

Good practice / Norm for building basic classes

Make sure there is a certain number of functions available
in all your classes, allowing for a uniform process

*/

# include <iostream>

class Sample {

public:

	Sample( ); // default constructor
	Sample( int const n );
	Sample( Sample const & src );  // copy constructor
	~Sample( );
	
	Sample &	operator=( Sample const & rhs ); // equals assignment operator

	int			getFoo( void ) const;

private:

	int			_foo;
};

#endif


// Not part of canonical form, but found in many classes. Good to get
// used to this.
std::ostream &	operator<<( std::ostream & o, Sample const & i );
/*

A class is in canonical form:

	* when it has at least a default constructor
	* when it has also a copy constructor, meaning a constructor
		taking a a parameter an instance of the class we are
		defining to make a copy of this class
	* equals operator // assignment operator, allowing to make
		assignments from an instance of this class. The behaviour of
		this operator is quite close to the behaviour of the copy
		constructor. But in the case of a copy constructor, we do have
		a new instance created, while in the case of the equals assignment operator,
		we only have an update of the current instance.
	* when the class has a destructor

With these four elements, your class is in canonical or copline form.
It is not required by C++, but we will ask you to systematically write
all your classes in this form from now on, even when it is not specified
in the assignment.

NB : Constructor and Deconstructor in the above are not yet in canonical
form. You will learn this soon.


*/