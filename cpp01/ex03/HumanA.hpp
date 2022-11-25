/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:31:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 20:29:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>

# include "Weapon.hpp"

class HumanA {

public:

	HumanA( std::string name , Weapon& weapon );
	~HumanA( );

	void	attack( ) const;


private:

	std::string	_name;
	
	Weapon&	_weapon;

};

#endif