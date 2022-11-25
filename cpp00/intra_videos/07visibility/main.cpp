/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 21:01:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample	instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;
	// instance._privateFoo = 42;
	//std::cout << "instance._privateFoo: " << instance_privateBar << std::endl;

	instance.publicBar();
	// instance._privateBar();

	return 0;
}

// with lines 22, 23, 26 uncommented it will not compile, because
// we cannot access private members from outside the class:

	// main.cpp:22:11: error: '_privateFoo' is a private member of 'Sample'
	// 		instance._privateFoo = 42;
	// 				^
	// ./Sample.class.hpp:31:6: note: declared private here
	// 		int     _privateFoo; // internal. Only visible and usable from ins...
	// 				^
	// 1 error generated.