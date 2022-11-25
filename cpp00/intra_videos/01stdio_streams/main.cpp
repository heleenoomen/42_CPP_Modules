/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:50:49 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 13:01:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


//	cout and cin from the standard namespace to redirect flows from and to stdout and stdin
//	using the back << and forward >> operators


int	main(void) {

	char	buff[512];

	std::cout << "Hello world !" << std::endl;  // redirect Hello world string to stdout, then redirect a carriage return to the stdout (std::endl)

	std::cout << "Input a word: ";
	std::cin >> buff;  // redirect from stdin to the buff
	std::cout << "You entered: [" << buff << "]" << std::endl; // redirect "You entered [" string, then buff, the "]" string, then carriage return to stdout

	return 0;
}

// std::enl		-> object of the standard namespace. Takes care of carriage return on different systems.
// (linux: \\n, microsoft; \r\n  cpp saves you this trouble with the endl object and puts the necesarry 
// characters to write a newline for the system you are on)


// documentation of iostream: www.cplusplus.com/reference/iostream
// you will find all the documentation of the website on www..cplusplus.com
// notice the tabs: C++98, c++11. In this piscine we use C++98 as an introduction to the basics of C++. 
// 	C++11 is interesting too, but more complicated. We will see C++11 in later projects. For this piscine, we will use C++98