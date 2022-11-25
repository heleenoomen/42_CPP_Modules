/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:20:12 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 19:05:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"

int	main() {

	Sample	instance;   // name of the instance. This is like declaring a variable on the stack in C: the variable will live until the function returns. 

	return 0;

}

// Sample is the static part: the object we have declared in our header.
// The instance variable is the dynamic part: an instance of the sample class.
// It's like Sample is the mould, and instance is a cake made with this mould.
// You will be able to make many different cakes with this mould. Cake instances made with the same mould ;)

// Instanciating the Sample class (line 17) will automatically call the constructor.
// So, when we write line 17, the constructor code will be run.
// When the function returns, the destructor is called, because instance here was a local variable
