#include "Integer.class.hpp"

int	main(void)
{
	Integer		x( 30 );
	Integer		y( 10 );
	Integer		z( 0 );


	std::cout << "Value of x : " << x << std::endl; // this is the overload of the << operator (the std::ostream & function in Integer.class.hpp)
	std::cout << "Value of y : " << y << std::endl;
	y = Integer( 12 ); // the assignment operator overload declared in Integer.class.hpp
	std::cout << "Value of y : " << y << std::endl; // overload operator

	std::cout << "Value of z : " << z << std::endl;
	z = x + y; // the addition operator overload declared in Integer.class.hpp
	std::cout << "Value of z : " << z << std::endl;

	return 0;
}

/* Output:

Constructor called with value 30
Constructor called with value 10
Constructor called with value 0
Value of x : 30
Value of y : 10
Constructor called with value 12
Assignation operation called from 10 to 12
Destructor called with value 12
Value of y : 12
Value of z : 0
Addition operator called with 30 and 12
Constructor called with value 42
Assignation operation called from 0 to 42
Destructor called with value 42
Value of z : 42
Destructor called with value 42
Destructor called with value 12
Destructor called with value 30

*/

/* Be cautious with overloads and respect the following rules:

	1) the overload must be natural.
		If the behaviour of an operator is strange, that is something
		to avoid at any cost
	2) the overload of your operator must be related to the natural
		semantics of this operator: 
			if you have a matrix class and you want to overload
			the plus operator to make an operation of two matrices,
			it makes a lot of sense.
			However, if you make a multiplication of matrix,
			overloading the plus operator, it will not make any
			sense to the developer, and it will become the source of
			many mistakes.
	3) even though it might sound like a good idea, it really is not.
		the cases where operator overloads are really justified are rare.
		 we'll see a good one later in the definition of the copy
		 classes. There are also a few good examples of arithmetic classes,
		 where operator overloads make sense.
		 This is also the case for a operator named brackets: allowing to
		 make an instance act like a function. This is referred to as a
		 'functor', but it is something you will not use very often when
		 you are starting with C++.
		 The operator overload use cases are real, but when you are not
		 familiar with it, you will probably do something stupid.
		 So: practice, but don't be so stupid as to use them everywhere
		 becuase you think it looks nice.


*/