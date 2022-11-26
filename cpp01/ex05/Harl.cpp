/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:46:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/26 23:35:43 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp" 

Harl::Harl( ) {

	_lookup[0].f = &Harl::_debug;
	_lookup[0].key = "DEBUG";
	_lookup[1].f = &Harl::_info;
	_lookup[1].key = "INFO";
	_lookup[2].f = &Harl::_warning;
	_lookup[2].key = "WARNING";
	_lookup[3].f = &Harl::_error;
	_lookup[3].key = "ERROR";

	return ;
};

Harl::~Harl( ) {

	return ;
};


void	Harl::complain( std::string level ) {


	int			opt = 0;

	while (level != _lookup[opt].key)
		opt++;
	(this->*_lookup[opt].f)();
	return ;
};


void	Harl::_debug( ) {

	std::cout <<  "I love having extra tofu for my \
7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!" << std::endl;
	return ;
};

void	Harl::_info( ) {

	std::cout << "I cannot believe adding extra tofu costs more money. \
You didn’t put enough tofu in my burger! If you did, I wouldn’t \
be asking for more!" << std::endl;
	return ;
};

void	Harl::_warning( ) {

	std::cout <<  "I think I deserve to have some extra tofu for free. \
I’ve been coming for years whereas you started working here since \
last month." << std::endl;
	return ;
};

void	Harl::_error( )  {

	std::cout << "This is unacceptable! I want to speak to the manager \
now." << std::endl;
	return ;
};
