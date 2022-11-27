/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:18:19 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 15:43:54 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"


int	main( ) {

	Zombie	zombie1( "Weird" );
	Zombie*	zombie2;

	zombie1.announce();

	zombie2 = newZombie( "Ziggy" );
	zombie2->announce();

	randomChump( "Gilly" );

	delete zombie2;

	return 0;
}