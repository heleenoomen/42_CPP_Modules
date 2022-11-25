/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:31:41 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 20:28:40 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA( std::string name , Weapon& weapon ) : _name(name) , _weapon(weapon) {

	return ;
};

HumanA::~HumanA( ) {

	return ;
}



void	HumanA::attack( ) const {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}