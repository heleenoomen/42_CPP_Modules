/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:51:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 20:02:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_H
# define INTEGER_CLASS_H

# include <iostream>

class Integer {

public:

	Integer( int const n );
	~Integer( );
	
	int		getValue() const;

	Integer &	operator=( Integer const & rhs ); // operator overload (assignment)
													// rhs = right hand side (lhs is hidden (current instance pointer))
									// return type: the current instance will be returned. 
									// Why this return type?
									// Because C and C++ allow to write things like: a = b = c = d;
									// A return type void wouldn't allow to chain assignments this way.

	Integer		operator+( Integer const & rhs) const; // operator overload (addition)
															// const, current integer is never changed
												// in this case, the current instance is not changed
												// 1 + 2 + 3 + 4 can be done by only returning the result
private:						

	int	_n;

};


std::ostream & operator<<( std::ostream & o, Integer const & rhs );


#endif


/*
+ 1 1 // prefix notation
1 + 1 // infix notation (bcs of the plus operator in between the two operands)
1 1 + // postfix notation (stack calculations, also Polish reversed notation)


 prefix notation, also refered to as 'functional notation'

because prefix notation looks a lot like a function +( 1, 1)  (a function taking 2 parameters)

We can modify this functional notation:
	1 + ( 1 ) 
		this is a random instance (1) on which we call the 
		plus member function to which we pass 1 as a parameter.
*/

/* 'operator' is a special keyword that allows to make a simple declaration
	of a member of the class.
	Between the operator and the bracket, specify to which operator you are
	referring to
	Ternary operators cannot be overloaded.
	The number of parameters will be related to the binarity or unarity
	of our operator.
	The assignment operator is binary by definition, which means that
	we have on the left the item that we are assigning to, and on the 
	right the item we are assigning.
	Similarly, the addition operator is binary: on the left the operand,
	on the right another operand.
	We can have a prefix notation (also called functional notation), which
	we can see as a notion similar to a member function.
	C++ is lying to you: it passes systematically of all your member
	functions when they are called an instance of the current class.
	So, in line 27 and line 28 there are actually 2 parameters:
	the parameter that is stated + the pointer to the current instance.

	Unary operator overload: e.g. pre- or postincrementation:
		in that case there would not be visible parameters, only
		the hidden default parameter which is the pointer to the current instance.

	Side note on post- and pre-incrementation:
		To differentiate them, we need a parameter. Read the documentation about this.




*/