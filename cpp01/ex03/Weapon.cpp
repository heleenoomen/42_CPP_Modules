/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:28:38 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 20:24:28 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon ( std::string type ) : _type(type) {

	return ;
};

Weapon::~Weapon ( ) {

	return ;
};




std::string const &	Weapon::getType() const {

	return _type;
};



void	Weapon::setType( std::string const & type ) {

	_type = type;
	// std::cout << "changed weapon to: " << _type << std::endl;
};
