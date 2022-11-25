/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:18:19 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 17:36:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"


int	main( ) {

	Zombie	zombie1( "Karl" );
	Zombie*	zombie2;

	zombie1.announce();

	zombie2 = newZombie( "Ziggy" );
	zombie2->announce();

	randomChump( "Bernd" );

	delete zombie2;

	return 0;
}