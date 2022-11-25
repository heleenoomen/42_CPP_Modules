

/* bad idea to use malloc in cpp */
/* If allocate objects with malloc, it will blow up.
/* it does not call the constructor of your object
/* and it does not call the destructor when you free*/

/* new and delete will handle it cleanly for you*/

#include <iostream>
#include <string>

class Student {

private:

	std::string	_login;

public:

	Student(std::string login) : _login(login) {
		
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}

	~Student() {

		std::cout << "Student " << this->_login << " died" << std::endl;
	}
};

int	main() {

	Student		bob = Student("bfubar");  // allocated statically
	Student*	jim = new Student("jfubar");  // allocated dynamically

	//Do some stuff here

	delete jim; //jim is destroyed

	return 0; //bob is destroyed
}


/* new and delete for arrays:
  
  
  
  */