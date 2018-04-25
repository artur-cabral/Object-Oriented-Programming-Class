#include <iostream>
#include<vector>
#include<string>
#include "c4Board.h"
#include "c4Player.h"
#include "c4Computer.h"


void playGame() {
	int player;
	//create a board
	c4Board myBoard;
	//Create two players
	c4Player player0(0);
	ComputerPlayer player1("Computer",1);
	myBoard.displayBoard();
	for (int i = 0; i < 42; i++) {
		player = i % 2;
		if (player == 0) {// EVEN - X player			
						  // ask for a move, place an X
						  //call function makeMove
			player0.makeMove(&myBoard);
			//Display board
			myBoard.displayBoard();
			// check to see if they won (isWinner)
			myBoard.isWinner(player);
			if (myBoard.isWinner(player) == true) {
				std::cout << player0.getName() << " is the WINNER! Congratulations!" << std::endl;
				return;
			}

		}

		else {
			// ask for a move, place an O
			//call function makeMove
			player1.chooseMove(&myBoard,1);
			//Display board
			myBoard.displayBoard();
			// check to see if they won (isWinner)
			myBoard.isWinner(player);
			if (myBoard.isWinner(player) == true) {
				std::cout << player1.getName() << " is the WINNER! Congratulations!" << std::endl;
				
				return;
			}

		}
	}
	std::cout << "Stalemate, nobody won this game!\n" << std::endl;
	return;
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

		std::cout << "Play another game? (1=yes/0=no): ";
		std::cin >> answer;

	} while (answer == 1);
	system("pause");
	return(0);
}