## Orthodox Canonical Form 
### Exercise 00:
> Create a class in Orthodox Canonical Form that represents a fixed-point number:
> * Private members:
>   * An integer to store the fixed-point number value.
>   * A static constant integer to store the number of fractional bits. Its value
will always be the integer literal 8.
> Create a class in Orthodox Canonical Form that represents a fixed-point number:
> * Private members:
>   * An <b>integer</b> to store the fixed-point number value.
>   * A <b>static constant integer</b> to store the number of fractional bits. Its value
will always be the integer literal 8.
> * Public members:
>   * A default constructor that initializes the fixed-point number value to 0.
>   * A copy constructor.
>   * A copy assignment operator overload.
>   * A destructor.
>   * A member function int `getRawBits( void ) const;`
that returns the raw value of the fixed-point value.
>   * A member function void `setRawBits( int const raw );`
that sets the raw value of the fixed-point number.
>
> Running this code:
> ```
> #include <iostream>
> int main( void ) {
> Fixed a;
> Fixed b( a );
> Fixed c;
> c = b;
> std::cout << a.getRawBits() << std::endl;
> std::cout << b.getRawBits() << std::endl;
> std::cout << c.getRawBits() << std::endl;
> return 0;
> }
> ```
>
> Should output something similar to:
> ```
> $> ./a.out
> Default constructor called
> Copy constructor called
> Copy assignment operator called // <-- This line may be missing depending on your implementation
> getRawBits member function called
> Default constructor called
> Copy assignment operator called
> getRawBits member function called
> getRawBits member function called
> 0
> getRawBits member function called
> 0
> getRawBits member function called
> 0
> Destructor called
> Destructor called
> Destructor called
> ```
