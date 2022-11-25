/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 13:13:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {

	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;

	return ;

}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst -= 1;

	return;

}

int	Sample::getNbInst( void ) {

	return Sample::_nbInst;
}


int	Sample::_nbInst = 0;

// because getNbInst() is a non member function, the 'this' pointer to the current instant
// is NOT passed and we cannot use it inside. The non member function getNbInst is passed
// no parameters at all.
// But just the name of the class is enough, because _nbInst is a class attribute
// i.e. a non member attribute

// The non member attribute should be initialized as soon as the code is running
// It shouldn't be in an undefined state until the class is first instantiated.
// Therefore, we initialize it as in the above (line 39)