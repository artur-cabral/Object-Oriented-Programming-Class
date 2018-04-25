#pragma once
#include <iostream>


/*
______                     _   _____ _
| ___ \                   | | /  __ \ |
| |_/ / ___   __ _ _ __ __| | | /  \/ | __ _ ___ ___
| ___ \/ _ \ / _` | '__/ _` | | |   | |/ _` / __/ __|
| |_/ / (_) | (_| | | | (_| | | \__/\ | (_| \__ \__ \
\____/ \___/ \__,_|_|  \__,_|  \____/_|\__,_|___/___/
______          _                 _   _
|  _  \        | |               | | (_)
| | | |___  ___| | __ _ _ __ __ _| |_ _  ___  _ __  ___
| | | / _ \/ __| |/ _` | '__/ _` | __| |/ _ \| '_ \/ __|
| |/ /  __/ (__| | (_| | | | (_| | |_| | (_) | | | \__ \
|___/ \___|\___|_|\__,_|_|  \__,_|\__|_|\___/|_| |_|___/
*/
// Create a class called TTTBoard3
// This class should have two data members: N (size of the board NxN) and currentState
//Data Members - //------ currentState (an NxN matrix which contains a - 1 for an unassigned grid point, a 0 if an X is in the location,
//and a 1 if O is in that location.
//Function Members - isWinner, makeMove, displayBoard, reset, and anythingElse

class TTTBoard3 {
public:
	//constructor: the function to run to create the board using an array NxN given by the user
	TTTBoard3(int size);// pass in N from the user to create NxN matrix
						   //Destructor: Clears the memory(delete currentState)
	~TTTBoard3();
	void displayBoard();
	bool isWinner(int whichPlayer);
	int isOkayMove(int i,int j,int k)const;
	void putMove(int i,int j,int k,int playerNumber);
	bool isStalemate();
	void reset();
private:
	int ***currentState;
	int N;


};
