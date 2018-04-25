/*
 _____ _           _____               _____          
|_   _(_)         |_   _|             |_   _|         
  | |  _  ___ ______| | __ _  ___ ______| | ___   ___ 
  | | | |/ __|______| |/ _` |/ __|______| |/ _ \ / _ \
  | | | | (__       | | (_| | (__       | | (_) |  __/
  \_/ |_|\___|      \_/\__,_|\___|      \_/\___/ \___|
                                                      
*/
//-----------------------------------------------------------------
// Author: Artur Cabral
// Summary: the goal of this code is to create a tic-tac-toe board to be used in a future project
//			
//Important classes: TTTBoard, the class contains an NxN board with "states"of empty, X, or O.
// Important functions: -> isWinner(checks if there is a winner on each move)
//						-> makeMove(takes coordinates (i,j) from the use and places 0 or 1 in the coordinates given, 
//						   if valid, displayBoard(displays the current state of the board, with X or O, and empty spots
//						-> 

//-----------------------------------------------------------------

#include "TTTBoard3.h"
void playGame() {
	// Declare a temporary N (passedN)
	int passedN;
	//Declare the pick coordinates and player
	int pickI, pickJ, player;
	// Ask use to enter in the board size. 
	std::cout << "What size of the board do you want? ";
	// Read in board size as passedN
	std::cin >> passedN;
	if (passedN == 3 || passedN == 4 || passedN == 5) {
		// declare an instance of TTTBoard, initializing with the value of passedN
		TTTBoard myBoard(passedN);
		myBoard.displayBoard();

		for (int i = 0; i < passedN*passedN; i++) {
			player = i % 2;
			if (player == 0) {// EVEN - X player			
				// ask for a move, place an X
				std::cout << "Player X make a move (i j): ";
				std::cin >> pickI >> pickJ;
				//call function makeMove
				myBoard.makeMove(player, pickI, pickJ);
				// check to see if they won (isWinner)
				myBoard.isWinner(player);
				if (myBoard.isWinner(player) == true) {
					std::cout << "Player X is the WINNER! Congratulations!" << std::endl;
					myBoard.displayBoard();
					return;
				}

				//Display board
				myBoard.displayBoard();
			}
			else {
				// ask for a move, place an O
				std::cout << "Player O make a move (i j): ";
				std::cin >> pickI >> pickJ;
				//call function makeMove
				myBoard.makeMove(player, pickI, pickJ);
				// check to see if they won (isWinner)
				myBoard.isWinner(player);
				if (myBoard.isWinner(player) == true) {
					std::cout << "Player O is the WINNER! Congratulations!" << std::endl;
					myBoard.displayBoard();
					return;
				}
				//Display board
				myBoard.displayBoard();
			}
		}
		// Stalemate
		std::cout << "It's a TIE, nobody won this game!\n" << std::endl;
	}
	else {
		std::cout << "This board size cannot be chosen. Please start another game and choose 3, 4, or 5." << std::endl;
	}

}
/*
___  ___      _
|  \/  |     (_)
| .  . | __ _ _ _ __
| |\/| |/ _` | | '_ \
| |  | | (_| | | | | |
\_|  |_/\__,_|_|_| |_|
*/
int main() {
	int answer;// declare the user answer to "play again"
	// While loop to playGame function
	do {
		playGame();
		
		std::cout << "Play another game? (1=yes/0=no)";
		std::cin >> answer;
		
	} while (answer == 1);

	

	system("pause");
	return(0);
}
