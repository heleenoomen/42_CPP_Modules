#include "Sample.class.hpp"
#include <iostream>


int	main(void)
{
	Sample	instance1;
	Sample	instance2( 42 );
	Sample	instance3( instance1 );

	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;
	std::cout << instance3 << std::endl;
}

/* output:

Default constructor called
Parametric Constructor called
Copy constructor called
Assignation operation called from 0 to 0
0
42
0
Assignation operation called from 0 to 42
42
Destructor called
Destructor called
Destructor called

*/

/* Canonical for

	Excellent practice & widely used

	Get familiar with the scripts in your text editors, whether it's
	emacs of vim, and get prebuilt class templates with the default constructors
	and so on, which must be present.

	There are also a few classes where the default constructor is useless.
	It doesn't mean that we don't have a canonical form.
	You can write the declaration of the default constructor in the private
	section of the class. It would then not be possible to make a default
	instantiation from the oustide, but it would be clearly written in the
	declaration of your class that the default constructor is actually present,
	but just inaccessible for your user.
*/