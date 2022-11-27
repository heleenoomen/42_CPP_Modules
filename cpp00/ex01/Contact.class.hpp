/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:08:24 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 15:34:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class	Contact {

public:

	Contact( );
	~Contact( );


	void	setFirstName( const std::string& firstName );
	void	setLastName( const std::string& lastName );
	void	setNickName( const std::string& nickName );
	void	setPhoneNumber( const std::string& phoneNumber );
	void	setDarkestSecret( const std::string& darkestSecret );

	void	printContactTable( ) const;
	void	printContact( ) const;

private:

	void	_printField( const std::string& field ) const;

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif