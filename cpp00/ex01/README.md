## My Awesome Phonebook
### Exercise 01:

> <i>Welcome to the 80s and their unbelievable technology! Write a program that behaves
> like a crappy awesome phonebook software.<br>
> You have to implement two classes:<br>
> * PhoneBook
>   * It has an array of contacts.
>   * It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
> replace the oldest one by the new one.
>   * Please note that dynamic allocation is forbidden.
> * Contact
>   * Stands for a phonebook contact.
>
> On program start-up, the phonebook is empty and the user is prompted to enter one
> of three commands. The program only accepts ADD, SEARCH and EXIT.
> * ADD: save a new contact
>   * If the user enters this command, they are prompted to input the information
> of the new contact one field at a time. Once all the fields have been completed,
> add the contact to the phonebook.
>   * The contact fields are: first name, last name, nickname, phone number, and
darkest secret. A saved contact can’t have empty fields.
> * SEARCH: display a specific contact
>   * Display the saved contacts as a list of 4 columns: index, first name, last
>name and nickname.
>   * Each column must be 10 characters wide. A pipe character (’|’) separates
> them. The text must be right-aligned. If the text is longer than the column,
> it must be truncated and the last displayable character must be replaced by a
> dot (’.’).
>   * Then, prompt the user again for the index of the entry to display. If the index
> is out of range or wrong, define a relevant behavior. Otherwise, display the
> contact information, one field per line.
> * EXIT:
>   * The program quits and the contacts are lost forever!
