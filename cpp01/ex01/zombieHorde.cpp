/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:49:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 18:06:28 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {

	Zombie*	zombies = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		zombies[i].setName( name );
	}

	return zombies;
}
