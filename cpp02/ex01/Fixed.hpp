/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:51:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/28 20:41:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:

	Fixed( );
	Fixed( Fixed const & src );
	Fixed( int const fixpt );
	Fixed( float f );

	~Fixed( );
	
	Fixed &	operator=( Fixed const & rhs );

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	int					_value;
	static int const	_fract = 8;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif