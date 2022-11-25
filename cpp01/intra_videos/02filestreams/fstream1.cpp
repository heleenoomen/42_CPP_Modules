
#include <iostream>
#include <fstream>

int	main() {

	std::ifstream	ifs("numbers"); // input file stream
	unsigned int	dst;
	unsigned int	dst2;
	ifs >> dst >> dst2; // read 2 integers

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();  // close the stream to close the file

	//---------------------------

	std::ofstream	ofs("test.out");

	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
}


// line 7: 1) create an input stream
// 			2) open the numbers file and link it to the stream
// the outcome will be a stream from which you will be able to read

// another way to open an ifstream: ifstream.open()

// checkout istringstream and ostringstream (cf. scanf, sprintf)
// useful for log output etc.