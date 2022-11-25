/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 12:04:03 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample	instance;

	instance.setFoo( 42 );
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
	instance.setFoo ( -42 );
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;

	return 0;
}

// Output:
// Constructor called
// this->getFoo: 0
// instance.getFoo(): 42     // setFoo( 42 ) works
// instance.getFoo(): 42	// setFoo (-42 ) didn't work bcs the value we gave as a parameter was negative. So, _foo remains unchanged
// Destructor called


// It is a good practice to use and even overuse getters and setters.
// Sometimes you do not have to write a setter, just a getter.
// Sometimes your getter will allow you to aggregate data or transform the result.
// For example: you have a class dealing with money and monetary values, 
// and your setter is able to take as a parameter a currency in which you want to
// have the return.
// You process in an agnostic way the value in your class. You do not know if they are
// francs or dollars. You decide, but it has nothing to do with your user.
// When the user calls this value, they can specify a currency. Then you return after
// doing the math in your getter.
// This allows you to have control over what you provide to the user when you
// are writing. It allows for some control over what the user provides you, to make
// sure that the vlues make sene.