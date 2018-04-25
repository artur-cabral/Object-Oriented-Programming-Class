#include "TTTBoard3.h"
/*
______                     _   _____ _
| ___ \                   | | /  __ \ |
| |_/ / ___   __ _ _ __ __| | | /  \/ | __ _ ___ ___
| ___ \/ _ \ / _` | '__/ _` | | |   | |/ _` / __/ __|
| |_/ / (_) | (_| | | | (_| | | \__/\ | (_| \__ \__ \
\____/ \___/ \__,_|_|  \__,_|  \____/_|\__,_|___/___/
______                _   _
|  ___|              | | (_)
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
\_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/
//---- TTTBoard constructor------------------------------------------------
// Define how the NxN matrix is created, taking the input N from the user
TTTBoard3::TTTBoard3(int size) {
	//Allocate a 3d matrix
	//First dimension(1D)
	N = size;
	currentState = new int**[N];
	//2D
	for (int i = 0; i < N; i++)
		currentState[i] = new int*[N];
	//3D(for each 2D location, make a 1D location on it)
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			currentState[i][j] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				currentState[i][j][k] = -1;


	reset();

};

//--- TTTBoard destructor -------------------------------------------------
// Clears the alocated memory in the class, clears the NxN board
TTTBoard3::~TTTBoard3() {
	// clear the board
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			delete[] currentState[i][j];
		}
		delete[] currentState[i];
	}
	delete[] currentState;

}

//------displayBoard(displays the current state of the board, with X or O, and empty spots
// If currentState[i][j] == -1 display a way for user to pick this empty spot.
// If currentState[i][j] == 0 display an X, similarly display a O if it is 1
void TTTBoard3::displayBoard() {
	//for (int i = 0; i < N; i++)//takes care of the dotted lines to separate the rows
	//		std::cout << "----------";
	//std::cout << "\n";
	// top row - == n-1
	for (int k = N - 1; k >= 0; k--) {
		for (int i = 0; i < N; i++)//takes care of the dotted lines to separate the rows
			std::cout << "----------";
		std::cout << "\n";
		for (int j = N - 1; j >= 0; j--) {
			for (int i = 0; i < N; i++) {
				if (currentState[i][j][k] == -1)// takes care of first and second columns
					std::cout << " (" << i << "," << j << "," << k << ") |";
				else if (currentState[i][j][k] == 0)
					//std::cout << "    X \t|";
					std::cout <<"    X    |";
				else
					std::cout << "    O    |";
					//std::cout << "    O \t|";
				//std::cout << i << "," << j << "," << k << "\t|";
			}
			std::cout << "\b\b" << "  " << std::endl; // new line for "traditional" 2D board
			
			for (int i = 0; i < N; i++)//takes care of the dotted lines to separate the rows
				std::cout << "----------";
			std::cout << "\n";
			
			}
		//End of a 2D board (make lots of space)
		std::cout << "\n\n" << std::endl;
		}
		
	}
//-------isOKayMove-------------------------------------------
//returns the currentState[i][j][k]
int TTTBoard3::isOkayMove(int i,int j,int k) const{
	if (currentState[i][j][k] == -1)
		return(true);
	else
		return(false);
	
}
//-------putMove----------------------------------------------
//changes the currentState to reflect a move made by the player
void TTTBoard3::putMove(int i, int j, int k, int playerNumber) {
	currentState[i][j][k] = playerNumber;
}
	
//--- isWinner ----------------------------------------------
// Determine is the given user is a winner. If so, 
//
//horiz: x x x 
//veriz: x    
//       x
//       x
//diag:  x
//		  x
//		   x

bool TTTBoard3::isWinner(int whichPlayer) {
	//Check for all 2D wins, using a for loop to fix k as 0,1, and 2. Wins in 2D include vertical, 
	// horizontal and diagonal for each of the 6 boards in 2D
	//outside for loop to fix k value
	bool flag = true;
	//Check using k as my 3rd coordinate----------------------------------------------------
	for (int k = 0; k < N; k++) {
		flag = true;
		//Diagonal - lower left to upper right
		// if whichPlayer does now "own" one of the (i,i,k) we set the flag back to false
		for (int i = 0; i < N; i++) {
			if (currentState[i][i][k] != whichPlayer)
				flag = false;
		}
		if (flag == true)
			return(true);

		//Diagonal - lower right to upper left
		//check to see if whichPlayer "owns" (N-1,0),(N-2,1),...(0,N-1)
		flag = true;
		// if whichPlayer does now "own" one of the (i,N-1-i) we set the flag back to false
		for (int i = 0; i < N; i++) {
			if (currentState[i][N - 1 - i][k] != whichPlayer)
				flag = false;
		}
		if (flag == true)
			return(true);
		//Horizontal
		//check to see if whichPlayer "owns"(i,N-1),(i,N-2),...(N-1,0)
		for (int i = 0; i < N; i++) {
			flag = true;
			for (int j = 0; j < N; j++) {
				if (currentState[i][j][k] != whichPlayer)
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
				if (currentState[i][j][k] != whichPlayer)
					flag = false;
			}
			if (flag == true)
				return(true);
		}
	
	}
	
	//Check using k as my 2nd coordinate-----------------------------------------------
	for (int k = 0; k < N; k++) {
		flag = true;
		//Diagonal - lower left to upper right
		// if whichPlayer does now "own" one of the (i,i,k) we set the flag back to false
		for (int i = 0; i < N; i++) {
			if (currentState[i][k][i] != whichPlayer)
				flag = false;
		}
		if (flag == true)
			return(true);

		//Diagonal - lower right to upper left
		//check to see if whichPlayer "owns" (N-1,0),(N-2,1),...(0,N-1)
		flag = true;
		// if whichPlayer does now "own" one of the (i,N-1-i) we set the flag back to false
		for (int i = 0; i < N; i++) {
			if (currentState[i][k][N - 1 - i] != whichPlayer)
				flag = false;
		}
		if (flag == true)
			return(true);
		//Horizontal
		//check to see if whichPlayer "owns"(i,N-1),(i,N-2),...(N-1,0)
		for (int i = 0; i < N; i++) {
			flag = true;
			for (int j = 0; j < N; j++) {
				if (currentState[i][k][j] != whichPlayer)
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
				if (currentState[i][k][j] != whichPlayer)
					flag = false;
			}
			if (flag == true)
				return(true);
		}
	
	}
	
	//Check using k as my 1st coordinate-----------------------------------------------
	for (int k = 0; k < N; k++) {
		flag = true;
		//Diagonal - lower left to upper right
		// if whichPlayer does now "own" one of the (i,i,k) we set the flag back to false
		for (int i = 0; i < N; i++) {
			if (currentState[k][i][i] != whichPlayer)
				flag = false;
		}
		if (flag == true)
			return(true);

		//Diagonal - lower right to upper left
		//check to see if whichPlayer "owns" (N-1,0),(N-2,1),...(0,N-1)
		flag = true;
		// if whichPlayer does now "own" one of the (i,N-1-i) we set the flag back to false
		for (int i = 0; i < N; i++) {
			if (currentState[k][i][N - 1 - i] != whichPlayer)
				flag = false;
		}
		if (flag == true)
			return(true);
		//Horizontal
		//check to see if whichPlayer "owns"(i,N-1),(i,N-2),...(N-1,0)
		for (int i = 0; i < N; i++) {
			flag = true;
			for (int j = 0; j < N; j++) {
				if (currentState[k][i][j] != whichPlayer)
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
				if (currentState[k][i][j] != whichPlayer)
					flag = false;
			}
			if (flag == true)
				return(true);
		}
	
	}
	//--End of 2D checks--------------------------------------------------
	// Check 3D Diagonals-----------------------------------------------
	// (0,0,0) (1,1,1) (2,2,2)
	flag=true;
	for(int i=0;i<N;i++)
		if (currentState[i][i][i] != whichPlayer) {
			flag = false;
			break;
		}
	if (flag == true)
		return(true);
	//(2,0,0) (1,1,1) (0,2,2)
	flag=true;
	for(int i=0;i<N;i++)
		if (currentState[N - (i + 1)][i][i] != whichPlayer) {
			flag=false;
			break;
		}
	if (flag==true)
		return(true);
	//(0,2,0) (1,1,1) (2,0,2)
	flag = true;
	for(int i=0;i<N;i++)
		if (currentState[i][N-(i+1)][i] != whichPlayer) {
			flag = false;
			break;
		}
	if (flag==true)
		return(true);
	//(2,2,0) (1,1,1) (0,0,2)
	flag = true;
	for (int i = 0; i<N; i++)
		if (currentState[i][i][N-(i+1)] != whichPlayer) {
			flag = false;
			break;
		}
	if (flag==true)
		return(true);
//--------End of diagonals-------------------------------------
	return(false);
	
}//---End of isWinner==============================================

//------isStalemate------------------------------------------------
//tests to see if board is full (or if game cannot be won)
bool TTTBoard3::isStalemate() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (currentState[i][j][k] == -1)
					return(false);
	// if all spots are filled and there is no winner, return true for Stalemate			
	return(true);
}
//---------end of isStalemate------------------------------------------

//-------reset-----------------------------------------------------------
// reset the currentState of the entire board back to -1
//------------------------------------------------------------------------
void TTTBoard3::reset() {
	//reset the currentState to -1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				currentState[i][j][k] = -1;
			}
		}
	}
}
