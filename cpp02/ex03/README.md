## Binary Space Partitioning (BSP)
### Exercise 03:
> <i>Now that you have a functional Fixed class, it would be nice to use it.
> 
> Implement a function which indicates whether a point is inside of a triangle or not.
>
> Start by creating the class <b>Point</b> in Orthodox Canonical Form that represents
a 2D point:
> * Private members:
>   * A Fixed const attribute x.
>   * A Fixed const attribute y.
>   * Anything else useful.
> * Public members:
>   * A default constructor that initializes x and y to 0.
>   * A constructor that takes as parameters two constant floating-point numbers.
It initializes x and y with those parameters.
>   * A copy constructor.
>   * A copy assignment operator overload.
>   * A destructor.
>   * Anything else useful.
> To conclude, implement the following function in the appropriate file:<br>
> </i>`bool bsp( Point const a, Point const b, Point const c, Point const point);`<i>
> * a, b, c: The vertices of our beloved triangle.
> * point: The point to check.
> * Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on edge, it will return False.
> Implement and turn in your own tests to ensure that your class behaves as expected.</i>