/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:04:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 18:29:21 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

int	main( ) {

	Point	a(-3, 4);
	Point	b(4, 3);
	Point	c(-2, -2);
	Point	p(-0.5 , 1);
	
	bool	inside;
	inside = bsp(a, b, c, p);
	if (inside == true)
		std::cout << "inside!" << std::endl;
	else
		std::cout << "outside!" << std::endl;
	return 0;
}
