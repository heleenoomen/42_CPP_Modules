/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:29:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/23 20:32:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>


/* ************************************************************************** */
/* CONSTRUCTOR                                                                */
/* ************************************************************************** */


PhoneBook::PhoneBook( ) {
	
	this->_entry = 0;
	this->_size = 0;
	return ;

}


/* ************************************************************************** */
/* DECONSTRUCTOR                                                              */
/* ************************************************************************** */


PhoneBook::~PhoneBook( ) {

	return ;
}




/* ************************************************************************** */
/* Get USER Input                                                             */
/* ************************************************************************** */



void	PhoneBook::_ignoreEof( ) const {
	
	std::cin.clear();
	std::clearerr(stdin);
}



void	PhoneBook::_getUserInput( const char *prompt , std::string& input) const {

	input.clear();

	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		_ignoreEof();
		input.clear();
		std::cout << std::endl;
	}
	size_t first_non_white = input.find_first_not_of(" \t");
	if (first_non_white == input.npos)
	{
		input = "";
		return ;
	}
	size_t last_non_white = input.find_last_not_of(" \t");
	input = input.substr( first_non_white, last_non_white - first_non_white + 1 );
}




/* ************************************************************************** */
/* ADD CONTACT                                                                */
/* ************************************************************************** */



void	PhoneBook::_updateSize( ) {

	if (_size < 8)
		_size++;
}



void	PhoneBook::_updateEntry( ) {

	_entry++;
	if (_entry == 8)
		_entry = 0;
}


bool	PhoneBook::_enterContactDetails( Contact& newContact ) const {
	std::string	input;

	_getUserInput("First name: ", input );
	if ( input.empty() )
		return false;
	newContact.setFirstName ( input );
	_getUserInput("Last name: ", input );
	if ( input.empty() )
		return false;
	newContact.setLastName ( input );
	_getUserInput("Nickname: ", input );
	if ( input.empty() )
		return false;
	newContact.setNickName ( input );
	_getUserInput("Phone number: ", input );
	if ( input.empty() )
		return false;
	newContact.setPhoneNumber ( input );
	_getUserInput("Darkest secret: ", input );
	if ( input.empty() )
		return false;
	newContact.setDarkestSecret( input );
	return true;
}



void	PhoneBook::_addContact( ) {

	Contact		newContact;

	if ( _enterContactDetails( newContact ) == false ) {
		return ;
	}

	_contacts[_entry] = newContact;
	_updateEntry( );
	_updateSize( );

}




/* ************************************************************************** */
/* SEARCH PHONEBOOK                                                           */
/* ************************************************************************** */


bool	PhoneBook::_entryInvalid( const std::string& input ) const {
	if ( input.length() > 1 )
		return true;

	if ( input[0] < '1')
		return true;

	if ( (unsigned int) input[0] - '0' > _size )
		return true;

	return false;
}



unsigned int	PhoneBook::_getQuery( std::string& input ) const {
	while ( _entryInvalid( input ) )
		_getUserInput( "Please enter a valid entry: " , input );

	return (input[0] - '0');
}




void	PhoneBook::_printTableHeader( ) const {

	std::cout << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First name" << "|";
	std::cout << std::right << std::setw(10) << "Last name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << "|";
	std::cout << std::endl;
}




void	PhoneBook::_searchContact( ) const {

	std::string		input;
	unsigned int	query;
	
	if (_size == 0)
	{
		std::cout << "Your PhoneBook is empty" << std::endl;
		return ;
	}
	_printTableHeader();
	for (unsigned int i = 0; i < _size; i++)
	{
		std::cout << std::right;
		std::cout << std::setw(10) << i + 1 << "|";
		_contacts[i].printContactTable();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	_getUserInput("Which contact do you wish to display? Type Entry: ", input);
	query = _getQuery( input );
	_contacts[query - 1].printContact( );
}




/* ************************************************************************** */
/* RUN PHONEBOOK                                                              */
/* ************************************************************************** */


void	PhoneBook::run( ) {
		std::string	input;

	while( true )
	{
		_getUserInput("Please enter an action: ADD / SEARCH / EXIT: " , input );
		if (input == "ADD")
			_addContact( );
		else if (input == "SEARCH")
			_searchContact( );
		else if (input == "EXIT")
			break ;
	}

	return ;

}
