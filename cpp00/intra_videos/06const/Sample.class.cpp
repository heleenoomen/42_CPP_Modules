/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 20:13:52 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( float const f ) : pi( f ), qd( 42) {

	std::cout << "Constructor called" << std::endl;
	return ;

}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;

}

void	Sample::bar( void ) const { // const keyword to tell the compiler that this function will not alter the current instance

	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;
	
	// this->qd = 0; // with this line uncommented, the code will not compile because a const member function should not alter the current instance
	return;
}

// in the constructor, pi is initialized to the value of f, qd is initialized to the value 42