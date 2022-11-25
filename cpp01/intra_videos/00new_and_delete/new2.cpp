

/* bad idea to use malloc in cpp
If allocate objects with malloc, it will blow up.
it does not call the constructor of your object
and it does not call the destructor when you free

new and delete will handle it cleanly for you*/

#include <iostream>
#include <string>

class Student {

private:

	std::string	_login;

public:

	Student() : _login("ldefault") {
		
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}

	~Student() {

		std::cout << "Student " << this->_login << " died" << std::endl;
	}
};

int	main() {

	Student*	students = new Student;  ///[42]; // allocate 42 Student objects contiguously on heap

	//Do some stuff here

	delete [] students; // deallocate the whole array

	return 0; //bob is destroyed
}


/* new and delete for arrays:
  
  the above allocates 42 students dynamically and contiguously in heap.
  Please not that it only works with constructors that do not take parameters.
  You have to find work arounds for initializing the array.
  */