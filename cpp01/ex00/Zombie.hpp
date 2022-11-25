/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:43:24 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 17:37:21 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

public:

	Zombie( std::string );
	~Zombie( );

	void	announce( void ) const;


private:

	std::string	_name;

};



Zombie*	newZombie( std::string name );
void	randomChump( std::string name );


#endif
