/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:31:41 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 20:44:14 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <new>

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {

	_weapon = NULL;
	return ;
};


HumanB::~HumanB( ) {

	return ;
}



void	HumanB::attack( ) const {

	if (_weapon == NULL)
		std::cout << _name << " is unarmed!" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}


void	HumanB::setWeapon( Weapon & weapon ) {

	_weapon = &weapon ;
};