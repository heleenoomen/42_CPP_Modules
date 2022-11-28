/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:58:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/28 21:08:03 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed( ) : _value( 0 ) {

	std::cout << "Default constructor called" << std::endl;
	return ;
};

	
Fixed::Fixed( Fixed const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
};


Fixed::Fixed( int const i ) {

	unsigned int	j;

	if (i < 0)
	{
		j = (i * -1) - 1;
		_value = ~j << _fract;
	}
	else
		_value = i << _fract;

	std::cout << "Int constructor called" << std::endl;

	return ;
};


Fixed::Fixed( float f ) {

	int		bitshift_factor = pow((float)2, (float)_fract);

	_value = (int) ( f * bitshift_factor );

	std::cout << "Float constructor called" << std::endl;

	return ;
};

Fixed::~Fixed( ) {

	std::cout << "Destructor called" << std::endl;
	return ;
};


	
Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignment operator called" << std::endl;
	_value = rhs.getRawBits();

	return *this;
};


int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return _value;
};


void	Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;

	return;
};

float	Fixed::toFloat( void ) const {
	
	int				raw;
	float			bitshift_factor;
	float			f;

	bitshift_factor = pow((float)2, (float)_fract);
	raw = _value;
	f = (float) raw / bitshift_factor; 
	return f;
};

int		Fixed::toInt( void ) const {

	int				raw;
	unsigned int	conv;
	int				ret;

	raw = _value;
	if (raw & (1 << 31))
	{
		conv = (~raw) + 1;
		ret = conv >> 8;
		ret *= -1; 
	}
	else
		ret = raw >> 8;
	
	return ret ;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
