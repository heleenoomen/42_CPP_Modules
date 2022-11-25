/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:18:19 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 18:59:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"


int	main( ) {

	Zombie *zombies;

	zombies = zombieHorde( 42, "Francine" );

	for (int i = 0; i < 42; i++)
		zombies[i].announce();

	delete [] zombies;

	system("leaks zombies");
	return 0;
}
