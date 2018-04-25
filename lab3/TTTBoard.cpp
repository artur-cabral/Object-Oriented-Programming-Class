#include "TTTBoard.h"
/*
______                _   _
|  ___|              | | (_)
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
\_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/
//---- TTTBoard constructor------------------------------------------------
// Define how the NxN matrix is created, taking the input N from the user
TTTBoard::TTTBoard(int passedN) {
	// dinamically allocate the array
	N = passedN;
	currentState = new int*[N];
	for (int i = 0; i < N; i++)
		currentState[i] = new int[N];
	reset();

};

//--- TTTBoard destructor -------------------------------------------------
// Clears the alocated memory in the class, clears the NxN board
TTTBoard::~TTTBoard() {
	// clear the board
	for (int i = 0; i < N; ++i)
		delete[] currentState[i];
	delete[] currentState;

}

//------displayBoard(displays the current state of the board, with X or O, and empty spots
// If currentState[i][j] == -1 display a way for user to pick this empty spot.
// If currentState[i][j] == 0 display an X, similarly display a O if it is 1
void TTTBoard::displayBoard() {
	
	// Top row - == N-1
	for (int j = N - 1; j >= 0; j--) {
		for (int i = 0; i < N - 1; i++)
			if (currentState[i][j] == -1)// takes care of first and second columns
				std::cout << " (" << i << "," << j << ")\t|";
			else if (currentState[i][j] == 0)
				std::cout << "    X \t|";
			else
				std::cout << "    O \t|";
				
			//take care of third column
			if (currentState[N-1][j] == -1)
				std::cout << " (" << N - 1 << "," << j << ")" << std::endl;
			else if (currentState[N-1][j] == 0)
				std::cout << "   X \n";
			else {
				std::cout << "   O \n";
			}
		for(int i=0; i < N; i++)//takes care of the dotted lines to separate the rows
			if (j != 0)
				std::cout << "--------";
		std::cout << "\n";
	}
	
}

//--- isWinner -------------------------------
// Determine is the given user is a winner. If so, 
//
//horiz: x x x 
//veriz: x    
//       x
//       x
//diag:  x
//		  x
//		   x

bool TTTBoard::isWinner(int whichPlayer) {

	//Diagonal - lower left to upper right
	//check to see if whichPlayer "owns" (0,0),(1,1),...(N,N)
	bool flag = true;
	// if whichPlayer does now "own" one of the (i,i) we set the flag back to false
	for (int i = 0; i < N; i++) {
		if (currentState[i][i] != whichPlayer)
			flag = false;

		
	}
	if (flag == true)
		return(true);
	
	//Diagonal - lower right to upper left
	//check to see if whichPlayer "owns" (N-1,0),(N-2,1),...(0,N-1)
	flag = true;
	// if whichPlayer does now "own" one of the (i,N-1-i) we set the flag back to false
	for (int i = 0; i < N; i++) {
		if (currentState[i][N - 1 - i] != whichPlayer)
			flag = false;

		
	}
	if (flag == true)
		return(true);

	//Horizontal
	//check to see if whichPlayer "owns"(i,N-1),(i,N-2),...(N-1,0)
	for (int i = 0; i < N; i++) {
		flag = true;
		for (int j = 0; j < N; j++) {
			if (currentState[i][j] != whichPlayer)
				flag = false;

			
		}
		if (flag == true)
			return(true);
	}
	// Vertical
	//check to see if whichPlayer "owns" (i,N-1),(i,N-2),...(N-1,0)
	for (int j = 0; j < N; j++) {
		flag = true;
		for (int i = 0; i < N; i++) {
			if (currentState[i][j] != whichPlayer)
				flag = false;


		}
		if (flag == true)
			return(true);
	}
	return(false);
}
//-------- makeMove --------------------------------------------------------------------
//Accepts coordinates(i, j) and player # as input.Puts X or O in(i, j) location, if possible.
// Returns error if the slot is not empty.
//
//--------------------------------------------------------------------------------------
bool TTTBoard::makeMove(int whichPlayer, int I, int J) {
	


	// Puts X or O in (i,j) location, if possible
	if (currentState[I][J] == -1) {
		currentState[I][J] = whichPlayer;
		return(true);

	}
	
		// returns error if location (i,j) is NOT empty
	else {
		while (currentState[I][J] != -1) {
			std::cout << "This is an invalid move, please play again:" << std::endl;
			std::cin >> I >> J;
			if (currentState[I][J] == -1) {
				currentState[I][J] = whichPlayer;
				return(true);
			}
		}
			return(false);
	}
	
}
 
//-------reset-----------------------------------------------------------
// reset the currentState of the entire board back to -1
//------------------------------------------------------------------------
void TTTBoard::reset() {
	//reset the currentState to -1
	for (int i = 0; i < N; i++) {
		for (int j=0; j < N; j++) {
			currentState[i][j] = -1;
		}
	}
}