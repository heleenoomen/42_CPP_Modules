/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 12:37:42 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"


Sample::Sample( int v ) : _foo(v) {

	std::cout << "Constructor called" << std::endl;
	std::cout << "this->getFoo: " << this->getFoo() << std::endl;

	return ;

}


Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;

}


int	Sample::getFoo( void ) const {

	return this->_foo;
}


// 
int	Sample::compare( Sample * other ) const { // take as a parameter a random instance

	if ( this->_foo < other->getFoo() ) // compare the value of the _foo attribute
		return -1;
	else if ( this->_foo > other->getFoo() )
		return 1;
	
	return 0;
}
// we use the getFoo() getter to get the value of _foo of the other instance