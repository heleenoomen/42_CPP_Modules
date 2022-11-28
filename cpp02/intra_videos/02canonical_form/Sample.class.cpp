/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:51:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/28 11:44:11 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>


Sample::Sample( ) : _foo( 0 ) {

	std::cout << "Default constructor called" << std::endl;
	
	return ;
};


Sample::Sample( int const n) : _foo( n ) {

	std::cout << "Parametric Constructor called" << std::endl;

	return;
}

Sample::Sample( Sample const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}


Sample::~Sample( ) {

	std::cout << "Destructor called" << std::endl;
	return ;
};

Sample &		Sample::operator=( Sample const & rhs) {

	std::cout << "Assignment operation called from " << _foo;
	std::cout << " to " << rhs.getFoo() << std::endl;

	_foo = rhs.getFoo();

	return *this; // return reference to current instance.
}

std::ostream &	operator<<( std::ostream & o, Sample const & rhs ) {

	o << rhs.getFoo();
	return o;
}
	
int	Sample::getFoo( ) const {

	return _foo;
}



/*
adhoc_polymorphism = function overloading

it allows to define many function having the same name but
accepting different parameters

It works not just on member functions, but on any function.

Principle is:
	* you have 1 function name
	* you have different parameters for every overload

This allows to specialize how a function works based on its params



*/