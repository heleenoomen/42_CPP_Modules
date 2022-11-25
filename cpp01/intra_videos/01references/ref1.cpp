
/* in C we need pointers to allocate memory and pass it around


   in C++ we can use references: more or less an alias for
   an existing variable.

   Or we might define it like this:
   A reference is a pointer that is constant and always unreferenced
   and never void.
   
   */

#include <iostream>

int	main() {

	int		numberOfBalls = 42;

	int*	ballsPtr = &numberOfBalls; // pointer
	int&	ballsRef = numberOfBalls; // reference
//	int&	ballsRefs; // > This would be erroneous! (*see below!)

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84; // no dereferencing needed
	std::cout << numberOfBalls << std::endl;

	return 0;
}

// a reference is somewhat like a constant pointer.
// it is always, always pointing to the same item.


// * line 22 would be erroneous, because it is a reference
// pointing to nothing. And since it is constant, we cannot
// make it point to something else later.
// In other words: you cannot create an unitialized reference.

// On the bright side: once you have a reference, it will
// always point on something.

// a reference is like a dereferenced pointer. We are interested
// in the thing that is pointed to, not in the pointer itself.