/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:40:12 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/26 23:46:03 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>

class Harl {

public:

	Harl( );
	~Harl( );

	void	complain( std::string level );

private:

	typedef struct lookup {
		std::string	key;
		void (Harl::*f)(void) const;
	} lookup;


	void	_debug( ) const;
	void	_info( ) const;
	void	_warning( ) const;
	void	_error( ) const;

	lookup	_lookup[4];// = {{"Error", _error}, {"INFO", _info}, {"Warning", _warning}, {"DEBUG", _debug}};
};


#endif