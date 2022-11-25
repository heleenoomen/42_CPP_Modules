/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 13:56:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample		instance; // class instantiated on the stack
	Sample *	instancep = &instance; // pointer declared on the stack and initialized to the address of instance variable

	int			Sample::*p = NULL; // pointer to member attribute of Sample class. Initialized to NULL
	void		(Sample::*f)( void ) const; // pointer to member function of Sample class.


	p = &Sample::foo; // p is now the address of the foo attribute in the Sample class

	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21; // assign a new value too foo in instance
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of membeer foo: " << instance.foo << std::endl;


	f = &Sample::bar; // f is now the address of the bar function in the sample class.

	(instance.*f)();
	(instancep->*f)();

	return 0;
}

// Output:
//
// Constructor called
// Value of member foo: 0
// Value of member foo: 21
// Value of membeer foo: 42
// Member function called
// Member function called
// Destructor called

// int	*p;				would be a pointer to an integer
// int	Sample::*p;		is a pointer to an integer member of the Sample class

// void	(*f)(void)					would be a pointer to a function of return type void that does not take arguments
// void	(Sample::*f)(void) const;	is a pointer to a member function of the Sample class that has return type void and does not take arguments

