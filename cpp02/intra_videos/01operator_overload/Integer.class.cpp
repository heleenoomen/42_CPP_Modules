/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:51:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/28 10:55:04 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.class.hpp"
#include <iostream>

Integer::Integer( int const n ) : _n( n ) {

	std::cout << "Constructor called with value " << n << std::endl;
	return ;
}

Integer::~Integer( void ) {

	std::cout << "Destructor called with value " << _n << std::endl;
	return ;
}



int		Integer::getValue( void ) const {

	return _n;
}


// visible parameter rhs + hidden parameter this
Integer &		Integer::operator=( Integer const & rhs) {

	std::cout << "Assignation operation called from " << _n;
	std::cout << " to " << rhs.getValue() << std::endl;

	_n = rhs.getValue();

	return *this; // return reference to current instance.
}

Integer			Integer::operator+( Integer const & rhs) const {

	std::cout << "Addition operator called with " << _n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return Integer( _n + rhs.getValue() ); // return a copy of newly created integer class
}	// there is no cleaner way. We waste a little bit of memory, bcs with a pointer we woudn't be
	// able to make simple chainings (1 + 2 + 3 + 4). So we create this useless copy


// Operator overloads in C++ work with many operators. Read documentation.


/* Overload of the stream redirection operator. More particularly,
	to the left: <<
	Follow the same logic as with the assignment operator:
	the left member is the pointer to the current instance.
	the right member is the parameter rhs.
	Overloading << , we change the code to ostream, simply because
	the ostream class exists somewhere. It is written by a developer
	much more competent than we are. This developer did not know that
	I wanted to write an Integer class, and didn't know eiter that I
	wanted to overload the << operator in the Integer class.
	Then I'm stuck: I cannot use the member functions to overload
	<<
	The solution, since we cannot change the code of the ostream
	class, would not be overloading a member function but just
	overloading a function

	Here the << operator will take as a parameter an ostream instance
	(by reference) and as a 2nd parameter an instance of my Integer
	class.
	
*/
std::ostream &	operator<<( std::ostream & o, Integer const & rhs ) {

	o << rhs.getValue();
	return o;
}