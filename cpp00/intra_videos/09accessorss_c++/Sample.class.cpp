/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 11:55:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"


Sample::Sample( void ) {

	std::cout << "Constructor called" << std::endl;

	this->setFoo( 0 );
	std::cout << "this->getFoo: " << this->getFoo() << std::endl;

	return ;

}


Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;

}


int	Sample::getFoo( void ) const { // const gives readonly access to current instance

	return this->_foo; // return a copy of _foo 
}


void	Sample::setFoo( int v ) { // in order to make the user able to change _foo

	if (v >= 0) 
		this->_foo = v; // I don't want _foo to have a negative value
	
	return ;
}
// In real life, if the user enters a negative value, you'll have to write to the log
// or give an error to inform the user that something went wrong.
// We could also replace the return type by a boolean to inform the user that 
// a change has been applied or not