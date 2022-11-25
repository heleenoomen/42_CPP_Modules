/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 21:01:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

// in this constructor, we access private members, but since we are inside
// the class, we can access them and this will compile and work fine
Sample::Sample( void ) {

	std::cout << "Constructor called" << std::endl;

	this->publicFoo = 0;
	std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar(); // underscore makes it immediately clear that we are dealing with a private member

	return ;

}


Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;

}

void	Sample::publicBar( void ) const { // the underscore makes it immediately clear that we are dealing with a private member

	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void	Sample::_privateBar( void ) const { // the underscore makes it immediately clear that we are dealing with a private member

	std::cout << "Member function _privateBar called" << std::endl;
	return;
}
