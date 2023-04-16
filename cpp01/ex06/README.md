## Switch Statement
### Exercise 06:
> Sometimes you don’t want to pay attention to everything Harl says. Implement a
system to filter what Harl says depending on the log levels you want to listen to.
>
> Create a program that takes as parameter one of the four levels. It will display all
messages from this level and above. For example:
>
> ```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years whereas you started working here since last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```
>
>Although there are several ways to deal with Harl, one of the most effective is to
SWITCH it off.
>
> Give the name `harlFilter` to your executable.
>
> You must use the switch statement in this exercise