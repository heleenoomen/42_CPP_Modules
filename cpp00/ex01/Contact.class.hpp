/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:08:24 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/23 13:37:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class	Contact {

public:

	Contact( );
	~Contact( );


	void	setFirstName( const std::string& FirstName );
	void	setLastName( const std::string& LastName );
	void	setNickName( const std::string& NickName );
	void	setPhoneNumber( const std::string& PhoneNumber );
	void	setDarkestSecret( const std::string& DarkestSecret );

	std::string	getFirstName( ) const;
	std::string	getLastName( ) const;
	std::string	getNickName( ) const;
	std::string	getPhoneNumber( ) const;
	std::string	getDarkestSecret( ) const;

	void	printContactTable( ) const;
	void	printContact( ) const;

private:

	void	_printField( const std::string& field ) const;

	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

};

#endif