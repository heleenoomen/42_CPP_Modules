/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 16:05:03 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class Sample {

public:

	int	foo;

	Sample( void );
	~Sample( void );

	void	bar( void ); // this is a function in a class that you will be able to use from the instance of that class
};

#endif


// attributes are familiar (like variables in a struct in C)
// in C you cannot put functions into structs (only as function pointers)
// in C++ you can declare functions directly inside the class, more convenient to use.
// it works the same as with the constructor and destructor, but this time,
// with a return type in front.

// Here we have a member function void bar(void). We can define the function
// in a .cpp file

// NB ! Contrary to appearances, the bar( void ) member functions actually accepts
// a parameter and not void!
// CPP always passes by default and in a transparent way a parameter that will
// always be first. It will always be a special pointer: a pointer to the current
// instance.