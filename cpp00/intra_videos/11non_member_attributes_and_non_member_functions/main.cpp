/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 13:19:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"


void	f0( void ) {

	Sample	instance;

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;

	return;
}


void	f1( void ) {

	Sample	instance;

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	f0();

	return ;
}


int	main() {

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl; // this will be 0, because nothing in instantiated
	f1(); 
	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl; // again zero, because the instance created in f1() will be gone as soon as f1() returns;

	return 0;
}

// Output:

// Number of instances : 0
// Constructor called
// Number of instances : 1
// Constructor called
// Number of instances : 2
// Destructor called
// Destructor called
// Number of instances : 0
