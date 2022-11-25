/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:03:34 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/25 19:22:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

# define WIDTH 45


int	main( ) {

	std::string		s = "HI THIS IS BRAIN";
	std::string*	stringPTR = &s;
	std::string&	stringREF = s;

	std::cout << std::left;
	std::cout << std::setw(WIDTH) << "The memory address of s is:" << &s << std::endl;
	std::cout << std::setw(WIDTH) << "The memory address held by stringPTR is:" << stringPTR << std::endl;
	std::cout << std::setw(WIDTH) << "The memory address held by stringREF is:" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(WIDTH) << "The value of s is:" << s << std::endl;
	std::cout << std::setw(WIDTH) << "The value pointed to by stringPTR is:" << *stringPTR << std::endl;
	std::cout << std::setw(WIDTH) << "The value pointed to by stringREF is:" << stringREF << std::endl;

	return 0;
}