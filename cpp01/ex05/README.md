## Lookup Table (Function Pointers)
### Exercise 05:
> <i>Do you know Harl? We all do, do we? In case you don’t, find below the kind of
comments Harl makes. They are classified by levels:
> * <b>"DEBUG"</b> level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.<br>
Example: </i>"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<i>
> * <b>"INFO"</b> level: These messages contain extensive information. They are helpful for
tracing program execution in a production environment.<br>
Example: </i>"I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"<i>
> * <b>"WARNING"</b> level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.<br>
Example: </i>"I think I deserve to have some extra bacon for free. I’ve been coming for
years whereas you started working here since last month."<i>
> * <b>"ERROR"</b> level: These messages indicate an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.<br>
Example: </i>"This is unacceptable! I want to speak to the manager now."<i>
>
> You are going to automate Harl. It won’t be difficult since it always says the same
things. You have to create a <b>Harl</b> class with the following private member functions:
> * `void debug( void );`
> * `void info( void );`
> * `void warning( void );`
> * `void error( void );`
> <b>Harl</b> also has a public member function that calls the four member functions above
depending on the level passed as parameter:
>
`void complain( std::string level );`
>
> The goal of this exercise is to use <b>pointers to member functions</b>. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!
> Create and turn in tests to show that Harl complains a lot. You can use the examples
of comments listed above in the subject or choose to use comments of your own.
