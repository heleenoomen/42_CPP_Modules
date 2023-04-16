## Heap Allocation: Zombie Array
### Exercise 01:
> <i>Time to create a <b>horde of Zombies</b>!
> 
> Implement the following function in the appropriate file:
> 
> `Zombie* zombieHorde( int N, std::string name );`
> 
> It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
zombies, giving each one of them the name passed as parameter. The function returns a
pointer to the first zombie.
>
> Implement your own tests to ensure your `zombieHorde()` function works as expected.
Try to call `announce()` for each one of the zombies.
>
> Don’t forget to <b>delete</b> all the zombies and check for <b>memory leaks</b>.</i>
