/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:26:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 17:38:41 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>


int	SkipLeadingSpaces(char *s) {
	int	j;

	j = 0;

	while ( std::isspace(s[j]) )
		j++;

	return j;

}


bool	TrailingSpaces( char *s , int j ) {

	while (s[j] != '\0')
	{
		if ( !std::isspace(s[j]))
			return false;
		j++;
	}

	return true;

}


int	main(int argc, char **argv) {

	int	i;
	int	j;


	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}


	i = 1;
	while (argv[i] != NULL)
	{
		j = SkipLeadingSpaces(argv[i]);
		while ( argv[i][j] != '\0' )
		{
			if (TrailingSpaces(argv[i], j))
				break ;
			std::cout << ( char )std::toupper( argv[i][j] );
			j++;
		}
		std::cout << " ";
		i++;
	}
	std::cout << std::endl;


	return 0;
}
