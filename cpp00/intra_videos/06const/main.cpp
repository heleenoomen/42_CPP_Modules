/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 20:13:41 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample	instance( 3.14f );

	instance.bar();

	return 0;
}

// output:
// Constructor called
// this->pi = 3.14
// this->qd = 42
// Destructor called

// NB when you uncomment line 35 in the .cpp file, the code
// will not compile, because the const member function bar
// cannot alter the current instance:

	// Sample.class.cpp:35:11: error: cannot assign to non-static data member within
	//       const member function 'bar'
	//         this->qd = 0; // with this line uncommented, the code will no...
	//         ~~~~~~~~ ^
	// Sample.class.cpp:30:14: note: member function 'Sample::bar' is declared const
	//       here
	// void    Sample::bar( void ) const { // const keyword to tell the comp...
	// ~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~
	// 1 error generated.