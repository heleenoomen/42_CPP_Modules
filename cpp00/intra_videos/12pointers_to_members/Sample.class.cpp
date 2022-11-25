/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 13:36:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"


Sample::Sample( void ) : foo( 0 ) {

	std::cout << "Constructor called" << std::endl;
	return ;
}


Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}


void	Sample::bar( void ) const {

	std::cout << "Member function called" << std::endl;
	return;
}
