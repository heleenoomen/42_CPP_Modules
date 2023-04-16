## Memory Allocation: Stack vs Heap
### Exercise 00:

> <i>First, implement a <b>Zombie</b> class. It has a string private attribute `name`.<br>
Add a member function `void announce( void );` to the Zombie class. Zombies
announce themselves as follows:
>
> ```
> <name>: BraiiiiiiinnnzzzZ...
> ```
> 
> For a zombie named Foo, the message
would be:
>
> ```
> Foo: BraiiiiiiinnnzzzZ...
> ```
>
> Then, implement the two following functions:
> * `Zombie* newZombie( std::string name );`<br>
>   It creates a zombie, name it, and return it so you can use it outside of the function
scope.
>
> * `void randomChump( std::string name );`<br>
It creates a zombie, name it, and the zombie announces itself.
>
> Now, what is the actual point of the exercise? You have to determine in what case
it’s better to allocate the zombies on the stack or heap.
>
> Zombies must be destroyed when you don’t need them anymore. The destructor must
print a message with the name of the zombie for debugging purposes.</i>
