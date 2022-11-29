/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:58:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 11:48:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>


/* ************************************************************************** */
/* CONSTRUCTORS                                                               */
/* ************************************************************************** */

/* Default constructor */
Fixed::Fixed( ) : _rawBits( 0 ) {

	// std::cout << "Default constructor called" << std::endl;
	return ;
}

/* Copy constructor */
Fixed::Fixed( Fixed const & src ) {

	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

/* Int constructor */
Fixed::Fixed( int const i ) {

	unsigned int	j;

	if (i < 0)
	{
		j = (i * -1) - 1;
		_rawBits = ~j << _fract;
	}
	else
		_rawBits = i << _fract;

	// std::cout << "Int constructor called" << std::endl;

	return ;
}

/* Float constructor */
Fixed::Fixed( float f ) {

	int		bitshift_factor = pow((float)2, (float)_fract);

	_rawBits = (int) ( f * bitshift_factor );

	// std::cout << "Float constructor called" << std::endl;

	return ;
}

/* ************************************************************************** */
/* DECONSTRUCTOR                                                              */
/* ************************************************************************** */

Fixed::~Fixed( ) {

	// std::cout << "Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* GETTER AND SETTER                                                          */
/* ************************************************************************** */

int		Fixed::getRawBits( void ) const {

	// std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}



void	Fixed::setRawBits( int const raw ) {

	// std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;

	return;
};


/* ************************************************************************** */
/* ASSIGNMENT OPERATOR                                                        */
/* ************************************************************************** */

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	// std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = rhs.getRawBits();

	return *this;
}


/* ************************************************************************** */
/* PRE & POST INCREMENT OPERATORS                                             */
/* ************************************************************************** */

Fixed &		Fixed::operator++(int){

	_rawBits++;
	return *this;
}

Fixed &		Fixed::operator++( ) {

	++_rawBits;
	return *this;
}


/* ************************************************************************** */
/* ARITHMETIC OPERATORS                                                       */
/* ************************************************************************** */

Fixed	Fixed::operator+( Fixed const & rhs ) {

	return Fixed( toFloat() + rhs.toFloat() );
}


Fixed	Fixed::operator-( Fixed const & rhs ) {

	return Fixed( toFloat() - rhs.toFloat() );
}


Fixed	Fixed::operator*( Fixed const & rhs ) {

	// std::cout << "Multiplication overload called, toFloat() = "; 
	// std::cout << toFloat(); 
	// std::cout << ", rhs.toFloat() = ";
	// std::cout << rhs.toFloat() << std::endl;
	return Fixed( toFloat() * rhs.toFloat() );
}


Fixed	Fixed::operator/( Fixed const & rhs ) {

	return Fixed( toFloat() / rhs.toFloat() );
}


/* ************************************************************************** */
/* COMPARISON OPERATORS                                                       */
/* ************************************************************************** */

bool	Fixed::operator==( Fixed const & rhs ) {

	return _rawBits == rhs.getRawBits();
}

bool	Fixed::operator!=( Fixed const & rhs ) {
	
	return _rawBits != rhs.getRawBits();
}
	bool	Fixed::operator<=( Fixed const & rhs ) {

	return _rawBits <= rhs.getRawBits();
}

bool	Fixed::operator>=( Fixed const & rhs ) {

	return _rawBits >= rhs.getRawBits();
}

bool	Fixed::operator>( Fixed const & rhs ) {
	
	return _rawBits > rhs.getRawBits();
}

bool	Fixed::operator<( Fixed const & rhs ) {

	return _rawBits < rhs.getRawBits();
}

/* ************************************************************************** */
/* TYPE CONVERSION                                                            */
/* ************************************************************************** */

float	Fixed::toFloat( void ) const {
	
	int				raw;
	float			bitshift_factor;
	float			f;

	bitshift_factor = pow((float)2, (float)_fract);
	raw = _rawBits;
	f = (float) raw / bitshift_factor; 
	return f;
};

int		Fixed::toInt( void ) const {

	int				raw;
	unsigned int	conv;
	int				ret;

	raw = _rawBits;
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

/* ************************************************************************** */
/* MIN / MAX                                                                  */
/* ************************************************************************** */

Fixed &	Fixed::min( Fixed & one, Fixed & two) {

	if (one < two)
		return one;
	return two;
}

Fixed const &	Fixed::min( Fixed const & one, Fixed const & two) {

	if (Fixed(one) < Fixed(two))
		return one;
	return two;
}

Fixed &	Fixed::max( Fixed & one, Fixed & two) {

	if (one > two)
		return one;
	return two;
}


Fixed const &	Fixed::max( Fixed const & one, Fixed const & two) {

	if (Fixed(one) > Fixed(two))
		return one;
	return two;
}

/* ************************************************************************** */
/* STREAM REDIRECTION OPERATOR                                                */
/* ************************************************************************** */

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
