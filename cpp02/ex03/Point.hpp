/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:07:20 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 17:52:34 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:

	Point( );
	Point( float const x, float const y );
	Point( Point const & src );

	~Point( );

	Point &	operator=( Point const & rhs );

	float	getX( ) const;
	float	getY( ) const;
	int		getXraw( ) const;
	int		getYraw( ) const;
	Fixed const &	getXFixed( ) const;
	Fixed const &	getYFixed( ) const;

private:

	Fixed const	_x;
	Fixed const	_y;

};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif