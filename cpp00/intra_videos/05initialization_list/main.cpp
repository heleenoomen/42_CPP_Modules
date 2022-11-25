/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 19:38:06 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1.class.hpp"
#include "Sample2.class.hpp"

int	main() {

	Sample1	instance1( 'a', 42, 4.2f );
	Sample2 instance2( 'z', 13, 3.14f );

	return 0;
}

// Output:
//
// Constructor called
// this->a1: a
// this->a2: 42
// this->a3: 4.2
// Constructor called
// this->a1: z
// this->a2: 13
// this->a3: 3.14
// Destructor called
// Destructor called