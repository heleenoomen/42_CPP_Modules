/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:58:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 11:41:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1.class.hpp"
#include "Sample2.class.hpp"

Sample2::Sample2( void ) {

	std::cout << "Constructor called" << std::endl;
	this->Bar();

	return ;
}


Sample2::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;

}

void	Sample2::bar( void ) const {

	std::cout << "Member function publicBar called" << std::endl;
	return;
}
