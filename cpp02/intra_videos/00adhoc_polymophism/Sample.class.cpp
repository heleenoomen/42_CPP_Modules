/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:51:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 20:04:42 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>


Sample::Sample( ) {

	std::cout << "Constructor called" << std::endl;
	return ;
};


Sample::~Sample( ) {

	std::cout << "Destructor called" << std::endl;
	return ;
};
	
void	Sample::bar( char const c ) const {

	std::cout << "Member function bar called with char overload: " << c << std::endl;
	return ;
};

void	Sample::bar( int const n) const {

	std::cout << "Member function bar called with int overload: " << n << std::endl;
	return ;
};
void	Sample::bar( float const z ) const {

	std::cout << "Member function bar called with float overload: " << z << std::endl;
	return ;
};

void	Sample::bar( Sample const & i ) const {

	std::cout << "Member function bar called with Sample const & overload: " << std::endl;
	return ;
};



/*
adhoc_polymorphism = function overloading

it allows to define many function having the same name but
accepting different parameters

It works not just on member functions, but on any function.

Principle is:
	* you have 1 function name
	* you have different parameters for every overload

This allows to specialize how a function works based on its params



*/