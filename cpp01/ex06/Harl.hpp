/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:40:12 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 12:42:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>

class Harl {

public:

	Harl( );
	~Harl( );

	void	complain( std::string level ) const;

private:

	void	_debug( ) const;
	void	_info( ) const;
	void	_warning( ) const;
	void	_error( ) const;

};


#endif