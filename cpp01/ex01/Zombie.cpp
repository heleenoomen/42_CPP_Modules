/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:43:31 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 19:01:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"


Zombie::Zombie() {

	std::cout << "A zombie was created" << std::endl;
}



Zombie::~Zombie( ) {

	std::cout << Zombie::_name << " was destroyed." << std::endl;
}




void	Zombie::announce( ) const {

	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



void	Zombie::setName( std::string const & name ) {

	_name = name;
}

