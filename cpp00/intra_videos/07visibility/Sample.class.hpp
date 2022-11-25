/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 21:03:06 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class Sample {

public: // public keyword, everything underneath will be public

	int	publicFoo; // visible from inside & outside the class

	Sample( void );
	~Sample( void );

	void	publicBar( void ) const; // usable from inside & outside the class


private: // private keyword, everything underneath here will be private

	int	_privateFoo; // internal. Only visible and usable from inside of this class

	void	_privateBar( void ) const; // good practice / convention to name private members with an underscore

};

#endif


// Private and public allow for the encapsulations of the members of our class
// and the member function that are only visible form the inside
// of our class,
// or from the outside.
// public: accessable from inside + outside the class
// private: accessable only from inside the class
// code will not compile if you try to access private members from outside the class
// you can so hide the implementation details of your class
// only the part that will be useful for your user is visible.


// underscore can be placed befor or after private variable, depending on your preferences (or leave it out altogether, but it's sort of a convention)
// makes it immediately clear that your dealing with a public or a private variable


// Daily life example:
//
// Only the commands the user needs should be accessible and visible for
// the user. (shell, mouse, etc.)
// The inner workings can be hidden, they are private.