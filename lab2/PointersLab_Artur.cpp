/***************************************************
 _       ___  ______   _____
| |     / _ \ | ___ \ / __  \
| |    / /_\ \| |_/ / `' / /'
| |    |  _  || ___ \   / /
| |____| | | || |_/ / ./ /___
\_____/\_| |_/\____/  \_____/

* Author: Artur Cabral
* Summary: the goal of this program is to prompt the user for a size N, it then allocates x to be a double of size N ,
assigns it the rst N entries in the Fibonacci sequence, and computes the norm of the array.
* Important Variables: N(size of the array),x (a double of size N)

******************************************************/

#include <iostream>
#include <string>

//Declare the templates of my functions
void fillFibonacci(double *x, int N);

double getNorm(double *x, int N);

void printDoubleArray(std::string arrayName,double *x, int N);

/*___  ___      _       
  |  \/  |     (_)      
  | .  . | __ _ _ _ __  
  | |\/| |/ _` | | '_ \ 
  | |  | | (_| | | | | |
  \_|  |_/\__,_|_|_| |_|
*/
int main() {
	// Prompt user for a size N for my array
	int N;
	std::cout << "What size array would you like to make?  ";
	std::cin >> N;

	//Make an array of size N
	double *x = new double[N];

	//Fill x with my Fibonacci sequence
	fillFibonacci(x, N);

	//Print x filled with the Fibonacci sequence
	printDoubleArray("MyFibonacci",x, N);

	//Find norm and print
	
	std::cout << "Norm = " << getNorm(x, N) << "  " << std::endl;
	
	//Print out norm routine
	printDoubleArray("MyFibonacci", x, N);

	//Free the memory for x	
	delete []x;

	system("pause");
	return(1);
}

/*
______                _   _
|  ___|              | | (_)
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
\_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/


*/
//Function to create a fibonacci sequence up to N
void fillFibonacci(double *x, int N) {
	// Declare the first two elements of the sequence
	x[0] = 1;
	x[1] = 1;

	// Create a for loop to generate the Fibonacci sequence in my array x
	for (int i = 2; i < N; i++) {
		x[i] = x[i - 1] + x[i - 2];
	}

}

// Function to find the norm of the fibonacci sequence
double getNorm(double *x, int N) {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		x[i] = x[i] * x[i];
		sum = sum + x[i];

	}
	return(sqrt(sum));
}

//General function to print the double array
void printDoubleArray(std::string arrayName,double *x, int N) {
	// Print Array nicely
	std::cout << arrayName << "= [";
	for (int i = 0; i < N-1; i++) {
		
		std::cout << x[i] << "  ";

	}
	std::cout << x[N - 1] << "]" << std::endl;

}