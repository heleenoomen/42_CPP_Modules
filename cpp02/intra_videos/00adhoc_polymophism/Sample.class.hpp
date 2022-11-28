/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:51:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 20:02:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class Sample {

public:

	Sample( );
	~Sample( );
	
	void	bar( char const c ) const;
	void	bar( int const n) const;
	void	bar( float const z ) const;
	void	bar( Sample const & i ) const;
};

#endif
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