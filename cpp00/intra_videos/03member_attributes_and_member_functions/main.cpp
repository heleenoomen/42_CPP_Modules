/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:05:28 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 19:05:38 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample	instance;

	instance.foo = 42; // use the foo attribute of the instance of the sample class. It is a stack variable, not a pointer, so use a dot, like in C.
	std::cout << "instance.foo: " << instance.foo << std::endl; // display the foo attribute

	instance.bar(); // this calls the bar function of this instance of the sample class

	return 0;
}

// To access attributes from pointers, use -> , so: instance->foo = 42