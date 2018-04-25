//-----------LAB 8---------------------------------------------------
// Author: Artur Cabral
// Summary: This lab performs the Brute Force and Euclidean Algorithm
//to calculate GCD of two numbers, and it is also necessary to calculate
//the time each function takes to be performed, to evaluate which one is 
//more efficient.
//Important functions: 
//-------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
//--------------FUNCTIONS-----------------------------------------------
//------------BRUTE FORCE GCD------------------------------
int bruteForceGCD(long int m, long int n) {
	// Start at min(m, n) see if divides m AND n.If so, quit, if not, reduce
	//by 1 and continue. gcd(27,18) algorithm should do:
	//18,17,16,15,14,13,12,11,10,9 STOP
	int q = std::min(m, n);
	int remainder0, remainder1,counter=0;
	for (int i = q; i >= 1; i--) {
		remainder0 = m%i;
		remainder1 = n%i;
		if (remainder0 == 0 && remainder1 == 0) {
			std::cout << counter << " iterations" << std::endl;
			return(i);
		}
			
		counter++;
	}
	
}//end of bruteForceGCD

//----------EUCLIDEAN GCD---------------------------------
int euclideanGCD(long int m, long int n) {
	int r,counter=0;
	//loop
	while (n!=0) {
		r = m%n;  // start with r= m%n
	//if r is zero, then n is the gcd
		if (n == 0)
			return(m);
		else{
			m = n;
			n = r;
		}
		counter++;
	}
	std::cout << counter << " iterations" << std::endl;
	return(m);
} //end of euclideanGCD


int main() {
	long int m, n;
	std::cout << "---------------CALCULATE THE GCD-------------------" << std::endl;
	std::cout << "Enter two numbers to calculate the GCD (separated by a space): ";
	std::cin >> m >> n;
	std::cout << "Using Brute Force Algorithm: " << std::endl;
	std::cout<< "The GCD between " << m << " and " << n << " is " << bruteForceGCD(m, n) << std::endl;
	std::cout << std::endl;

	std::cout << "Using Euclidean Algorithm: " << std::endl;
	std::cout << "The GCD between " << m << " and " << n << " is " << euclideanGCD(m, n) << std::endl;
	std::cout << std::endl;
	// use the clock to find how long an operation takes
	//find the clock time before the operation
	//find clock time at the end of operation
	//subtract the two

	//Do it with the function bruteForceGCD
	clock_t t1 = clock(), t2;
		bruteForceGCD(m, n);
	t2 = clock();
	//Now, t2-t1 is the time of operation
	std::cout << std::setprecision(16) << std::fixed;
	std::cout << "CPU Time is : ";
	std::cout << (t2 - t1) / (double)CLOCKS_PER_SEC;
	std::cout << " seconds" << std::endl;
	std::cout << std::endl;
	//Now calculate the time it takes with the function euclideangcd
	t1 = clock(), t2;
	euclideanGCD(m, n);
	t2 = clock();
	//now, t2-t1 is the time of operation
	std::cout << std::setprecision(16) << std::fixed;
	std::cout << "CPU Time is : ";
	std::cout << (t2 - t1) / (double)CLOCKS_PER_SEC;
	std::cout << " seconds" << std::endl;
	std::cout << std::endl;
	system("pause");
	return(0);
}