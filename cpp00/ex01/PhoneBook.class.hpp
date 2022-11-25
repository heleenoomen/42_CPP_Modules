/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:08:28 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/23 13:41:29 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>

# include "Contact.class.hpp"


class	PhoneBook {

public:

	PhoneBook( );
	~PhoneBook( );

	void	run( );

private:

	void	_ignoreEof( ) const;
	void	_getUserInput( const char *prompt , std::string& input ) const;
	bool	_enterContactDetails( Contact& newContact ) const;
	unsigned int	_getQuery( std::string& input ) const;
	bool			_entryInvalid( const std::string& input ) const;


	void	_addContact( );
	void	_searchContact( ) const;
	void	_printTableHeader() const;

	Contact	_getContact( unsigned int entry ) const;
	void	_updateEntry( );
	void	_updateSize ( );

	Contact			_contacts[8];
	unsigned int	_entry;
	unsigned int	_size;

};


#endif
