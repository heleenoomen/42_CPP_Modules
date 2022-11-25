/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:24:36 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/23 13:36:47 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact( ) {
	
	return ;

}


Contact::~Contact( ) {

	return ;

}


void	Contact::setFirstName( const std::string& s ) {   //try to make s by reference &  AND make s const reference (it only needs to read and copy)

	_FirstName = s ;
};


void	Contact::setLastName( const std::string& s ) {
	
	_LastName = s ;
};


void	Contact::setNickName( const std::string& s ) {

	_NickName = s ;
};

void	Contact::setPhoneNumber( const std::string& s ) {

	_PhoneNumber = s ;
};

void	Contact::setDarkestSecret( const std::string& s ) {

	_DarkestSecret = s ;
};


void	Contact::printContact( ) const {
	
	std::cout << "First name: " << _FirstName << std::endl;
	std::cout << "Last name: " << _LastName << std::endl;
	std::cout << "Nick name: " << _NickName << std::endl;
	std::cout << "Phone number: " << _PhoneNumber << std::endl;
	std::cout << "Darkest secret: " << _DarkestSecret << std::endl;
}


void	Contact::_printField( const std::string& field ) const {

	if (field.length() < 10)
		std::cout << std::setw(10) << field << "|";
	else
		std::cout << std::setw(9) << field.substr(0, 9) << "." << "|";
}


void	Contact::printContactTable( void ) const {

	_printField( _FirstName );
	_printField( _LastName );
	_printField( _NickName );
}

