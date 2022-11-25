/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:03:30 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 13:14:39 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// On the naming convention of these files:
// Sample.class.hpp
//		Sample is the class name, with the capitalized S
//		To make clear that we are dealing with a class, we use the .class pre-extension (so that we can see right away that we are dealing with a class header)
//		The .hpp expression is used so that your text editor picks the right mode (cpp instead of c)
//			.h or .hpp doesn't matter for the working of your program, just convenient for your editor.
//			again no real rules here, just pick a convention and stick with it. Be consistent.

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {    // class keyword to introduce a class. Sample to identify this class (i.e. this new type, this new data structure)

public:

	Sample( void );  // declare a constructor: name of the class
	~Sample( void ); // declare a destructor: name of the class preceded by tilde

}; // don't forget the semi colon! 


// when this class is instantiated, the constructor is called
// when the instance of the class is destroyed, the destructor will be called

#endif
