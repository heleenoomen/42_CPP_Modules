/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:43:24 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/28 12:24:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

public:

	Zombie( );
	~Zombie( );

	void	announce( void ) const;
	void	setName( std::string const & name );

private:

	std::string	_name;

};



Zombie*	zombieHorde( int N, std::string name );


#endif
