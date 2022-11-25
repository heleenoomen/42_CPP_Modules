/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:43:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 17:32:59 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"


Zombie::Zombie( std::string name ) : _name(name) {

}

Zombie::~Zombie( ) {

	std::cout << Zombie::_name << " was destroyed." << std::endl;
}


void	Zombie::announce( ) const {

	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


/* ************************************************** */
/* newZombie (heap)                                   */
/* ************************************************** */

