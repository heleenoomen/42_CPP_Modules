/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 19:00:17 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {

	std::cout << "Constructor called" << std::endl;

	this->foo = 42; // this is a pointer on the current instance. This way we assign the variable foo of the current instance the value 42
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar(); // we call the function directly with help of the current instance pointer keyword 'this'

	return ;

}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;

}

void	Sample::bar( void ) {

	std::cout << "Member function called" << std::endl;
	return;
}

// 'this' is a pointer, therefore we use -> instead of . to access foo, this->foo