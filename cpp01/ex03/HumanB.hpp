/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:31:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 20:44:07 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>

# include "Weapon.hpp"

class HumanB {

public:

	HumanB( std::string name );
	~HumanB( );

	void	attack( ) const;
	
	void	setWeapon( Weapon & weapon );


private:

	std::string	_name;
	
	Weapon*	_weapon;

};

#endif