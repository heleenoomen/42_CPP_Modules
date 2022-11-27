/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:26:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 15:36:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv) {


	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	std::string	arg;
	std::string::const_iterator it;
	
	int	i = 1;
	while (argv[i] != NULL)
	{
		arg = argv[i];
		for (it = arg.begin() ; it != arg.end() ; ++it) {
			std::cout << (char) std::toupper((int) *it);
		}
		i++;
	}
	std::cout << std::endl;

	return 0;
}
