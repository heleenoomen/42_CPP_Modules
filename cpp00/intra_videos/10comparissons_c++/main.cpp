/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 12:47:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample	instance1 ( 42 );
	Sample	instance2 ( 42 );

	if ( &instance1 == &instance1 )
		std::cout << "instance 1 and instance1 are physically equal" << std::endl;
	else
		std::cout << "instance 1 and instance1 are not physically equal" << std::endl;
	
	if ( &instance1 == &instance2 )
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	else
		std::cout << "instance 1 and instance2 are not physically equal" << std::endl;
	

	if ( instance1.compare( &instance1 ) == 0 )
		std::cout << "instance 1 and instance1 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance1 are not structurally equal" << std::endl;
	
	if ( instance1.compare( &instance2 ) == 0 )
		std::cout << "instance1 and instance2 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance2 are not structurally equal" << std::endl;

	return 0;

}

// Output:

// Constructor called
// this->getFoo: 42
// Constructor called
// this->getFoo: 42
// instance 1 and instance1 are physically equal		// Instance 1's address is equal to instance 1's address
// instance 1 and instance2 are not physically equal	// Instance 1's address is not equal to instance 2's address
// instance 1 and instance1 are structurally equal		// The value of _foo is equal between instance1 and instance1
// instance1 and instance2 are structurally equal		// The value of _foo is equal between instance1 and instance2
// Destructor called
// Destructor called

// 'Physical comparison' = compare addresses
// 'Structural comparison' = compare members