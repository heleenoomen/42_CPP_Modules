/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:18:19 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 18:07:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"


int	main( ) {

	Zombie *zombies;

	zombies = zombieHorde( 42, "Francine" );

	delete [] zombies;

	system("leaks zombie");
	return 0;
}
