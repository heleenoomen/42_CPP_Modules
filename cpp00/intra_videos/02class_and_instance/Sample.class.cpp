/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:03:13 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 13:19:45 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {    // Same syntax as with namespaces Sample::Sample( void ). There are interesting relations between classes and namespaces
	
	std::cout << "Constructor called" << std::endl;
	return ;   // there is no return type, because constructors and destructors in cpp do not have a return type. They are producers, you can see this as a return type 'void', but it is not actually written
				// writing 'return ; ' is optional. But it could be a good idea to write it, just to show that you are done constructing / destructing
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}


