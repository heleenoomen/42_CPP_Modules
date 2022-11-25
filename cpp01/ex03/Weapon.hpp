/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:25:11 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 20:08:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {


public:

	Weapon( std::string type );
	~Weapon();

	std::string const &	getType() const; // prototype given by execercise

	void	setType( std::string const & type );


private:

	std::string	_type;


};

#endif