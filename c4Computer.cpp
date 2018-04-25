#include <iostream>
#include <vector>
#include "c4Board.h"
#include "c4Player.h"
#include "c4Computer.h"


//======== Computer Player Functions ==================================================

//------ constructor -------------------------------------------
ComputerPlayer::ComputerPlayer(std::string cname, int compNumber) : c4Player(cname, compNumber) {

}

// ---- end of constructor-------------------------------------

//destructor-----------------------------------------------
ComputerPlayer::~ComputerPlayer() {}
//---------------------------------------------------------

//chooseMove--------------------------------------------------
void ComputerPlayer::chooseMove(c4Board *Board, int compNumber) {
	//scan board to see if there is a winning move, if so, place move
	//use a loop to switch through columns, and iterator to go through rows
	for (int i = 0; i < 7; i++) {
		for (auto outItr = Board->currentState.begin(); outItr < Board->currentState.end(); outItr++) {
			if (*((outItr + i)->begin() + i) == -1) {//check if the spot is empty
				Board->putMove(i, compNumber);//place move on empty spot
				if (Board->isWinner(compNumber) == true)
					return;
				else
					Board->putMove(i, -1);//how to erase a move if we can't pick a specific location?
			}
				
		}
	
	}
		
	//pretend a move on first possible column
	
	//check to see if can win on next move using recursion "chooseMove"
	//check to see if can win on next move using recursion "chooseMove"
	//check to see if can win on next move using recursion "chooseMove"
	//recursion up to 3 layers, if all true, pick the first move and return

	//no winning path? place a random move:
	for (int ii = 0; ii < 100000; ii++) {
		int column;
		column = rand() % 7;
		//checks if the move is okay
		if (Board->putMove(column,compNumber) == true) {
			//if okay, place move on the board
			std::cout << "Computer plays column: " << column << std::endl;
			break;
		}
	}
}//------------end of chooseMove-------------------------------------