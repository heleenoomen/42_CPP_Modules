/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:46:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 12:53:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp" 

Harl::Harl( ) {

	return ;
};

Harl::~Harl( ) {

	return ;
};


void	Harl::complain( std::string level ) const {

	std::string const	levels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	int i;

	for (i = 0; i < 4; i++)
		if (level == levels[i])
			break ;
	
	switch (i) {
		case 0: {
			_debug();
		}
		case 1: {
			_info();
		}
		case 2: {
			_warning();
		}
		case 3: {
			_error();
			break ;
		}
		default: {
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
		}
	}
};


void	Harl::_debug( ) const {

	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<  "I love having extra tofu for my \
7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!" << std::endl;
	std::cout << std::endl;
	return ;
};

void	Harl::_info( ) const {

	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra tofu costs more money. \
You didn’t put enough tofu in my burger! If you did, I wouldn’t \
be asking for more!" << std::endl;
	std::cout << std::endl;
	return ;
};

void	Harl::_warning( ) const {

	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<  "I think I deserve to have some extra tofu for free. \
I’ve been coming for years whereas you started working here since \
last month." << std::endl;
	std::cout << std::endl;
	return ;
};

void	Harl::_error( ) const {

	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager \
now." << std::endl;
	std::cout << std::endl;
	return ;
};
