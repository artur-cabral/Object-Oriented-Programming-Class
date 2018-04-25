#pragma once
#include <iostream>


/*
_____ _
/  __ \ |
| /  \/ | __ _ ___ ___  ___  ___
| |   | |/ _` / __/ __|/ _ \/ __|
| \__/\ | (_| \__ \__ \  __/\__ \
\____/_|\__,_|___/___/\___||___/
*/
// Create a class called TTTBoard
// This class should have two data members: N (size of the board NxN) and currentState
//Data Members - //------ currentState (an NxN matrix which contains a - 1 for an unassigned grid point, a 0 if an X is in the location,
//and a 1 if O is in that location.
//Function Members - isWinner, makeMove, displayBoard, reset, and anythingElse
class TTTBoard {

public:
	//constructor: the function to run to create the board using an array NxN given by the user
	TTTBoard(int passedN); // pass in N from the user to create NxN matrix
						   //Destructor: Clears the memory(delete currentState)
	~TTTBoard();
	void displayBoard();
	bool isWinner(int whichPlayer);
	bool makeMove(int whichPlayer, int I, int J);
	void reset();
private:
	int N;
	int** currentState;
};

