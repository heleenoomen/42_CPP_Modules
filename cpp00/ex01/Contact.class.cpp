/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:24:36 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 15:34:50 by hoomen           ###   ########.fr       */
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

	_firstName = s ;
};


void	Contact::setLastName( const std::string& s ) {
	
	_lastName = s ;
};


void	Contact::setNickName( const std::string& s ) {

	_nickName = s ;
};

void	Contact::setPhoneNumber( const std::string& s ) {

	_phoneNumber = s ;
};

void	Contact::setDarkestSecret( const std::string& s ) {

	_darkestSecret = s ;
};


void	Contact::printContact( ) const {
	
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nick name: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}


void	Contact::_printField( const std::string& field ) const {

	if (field.length() < 10)
		std::cout << std::setw(10) << field << "|";
	else
		std::cout << std::setw(9) << field.substr(0, 9) << "." << "|";
}


void	Contact::printContactTable( void ) const {

	_printField( _firstName );
	_printField( _lastName );
	_printField( _nickName );
}

