/*
 _       ___  ______    ____
| |     / _ \ | ___ \  / ___|
| |    / /_\ \| |_/ / / /___
| |    |  _  || ___ \ | ___ \
| |____| | | || |_/ / | \_/ |
\_____/\_| |_/\____/  \_____/

*/
//=============================================================================
// Author: Artur Cabral
//Summary: this lab is to reinforce the idea of vectors in OOD programming
// and give us some practice with this concept
// Important vectors: vector x, vector y, vector xPy(sum of x and y), array Z,
//vector z.
//==============================================================================

#include <iostream>
#include <vector>
#include <string>

int main() {
	//Create a vector x = [ 1,2,3,4,5 ]
	std::vector<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.push_back(4);
	x.push_back(5);
	//Print x vector

	//Create a vector y = [1.2,2.3,3.4,4.5,5.6]
	std::vector<double> y;
	y.push_back(1.2);
	y.push_back(2.3);
	y.push_back(3.4);
	y.push_back(4.5);
	y.push_back(5.6);
	//Print y vector

	//Declare new vector of doubles xPy = x+y;
	std::vector<double> xPy;
	for (int i = 0; i < 5; i++) {
		xPy.push_back(x[i] + y[i]);
	}
	//Declare the iterator to go through elements and print out vector xPy
	std::vector<double>::iterator double_itr;
	std::cout << "xPy = [\n";
	for (double_itr = xPy.begin(); double_itr < xPy.end(); double_itr++)
		std::cout << *double_itr << std::endl;	
	std::cout << "]\n" << std::endl;

	//Create an ARRAY of strings
	std:: string Z[] = {"one", "two", "three", "four", "five"};
	//Declare z to be a vector of strings
	int n = (sizeof(Z) / sizeof(*Z)); // find out the size of array Z
	std::vector<std::string> z(Z,Z+n);
	//Print z to see if it worked
	std::vector<std::string>::iterator string_itr;
	std::cout << "z = [";
	for (string_itr = z.begin(); string_itr < z.end(); string_itr++)
		std::cout << *string_itr << "  ";
	std::cout << "]\n" << std::endl;
	//Add "six"to the back of the array and "zero"to the front
	//Add "six"to the end
	z.push_back("six");
	z.insert(z.begin(), "zero");
	//Print elements of updated vector z
	std::cout << "z = [\n";
	for (string_itr = z.begin(); string_itr < z.end(); string_itr++)
		std::cout << *string_itr << std::endl;
	std::cout << "]\n" << std::endl;
	system("pause");
	return(0);
}