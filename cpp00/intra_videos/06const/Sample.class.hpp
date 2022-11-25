/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 20:09:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class Sample {

public:

	float const	pi;
	int			qd;

	Sample( float const f );
	~Sample( void );

	void	bar( void ) const; // const keyword to tell the compiler that this function will not alter the current instance
};

#endif


// Semantics for const in C were good, but not in every case.
// Const makes a variable constant (read only)
// It's the difference between a program that blows up and one that doesn't in the long run
// Especially later in functional programming, it will make life a lot easier.
// In complex and risky languages like C++, make your code as constant as possible
// More const is more safety
// Try to make your code as constant as possible, it will make your code better

// Const in C++ is a marvel.
// In C initialization of a const was: const int = 4; (on the same line, and this was forbidden by the norm)
// In C++, in a class, we initialize in the constructor

// const member functions will protect your class from future features.
// e.g. when you later add something that alters the function, it will not compile anymore
// you should develop the reflex to make member functions that do not alter the instance
// of your class, make them immediately const. This too avoid future problems.
// so declare and define it const. Good practice.