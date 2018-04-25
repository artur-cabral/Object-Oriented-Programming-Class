#include <iostream>
#include "TTTBoard3.h"
#include "player.h"
/*
 ___________   _____ _           _____               _____          
|____ |  _  \ |_   _(_)         |_   _|             |_   _|         
    / / | | |   | |  _  ___ ______| | __ _  ___ ______| | ___   ___ 
    \ \ | | |   | | | |/ __|______| |/ _` |/ __|______| |/ _ \ / _ \
.___/ / |/ /    | | | | (__       | | (_| | (__       | | (_) |  __/
\____/|___/     \_/ |_|\___|      \_/\__,_|\___|      \_/\___/ \___|
*/

/*
 _____                             _             ______ _                         _____ _
/  __ \                           | |            | ___ \ |                       /  __ \ |
| /  \/ ___  _ __ ___  _ __  _   _| |_ ___ _ __  | |_/ / | __ _ _   _  ___ _ __  | /  \/ | __ _ ___ ___
| |    / _ \| '_ ` _ \| '_ \| | | | __/ _ \ '__| |  __/| |/ _` | | | |/ _ \ '__| | |   | |/ _` / __/ __|
| \__/\ (_) | | | | | | |_) | |_| | ||  __/ |    | |   | | (_| | |_| |  __/ |    | \__/\ | (_| \__ \__ \
 \____/\___/|_| |_| |_| .__/ \__,_|\__\___|_|    \_|   |_|\__,_|\__, |\___|_|     \____/_|\__,_|___/___/
                      | |                                        __/ |
                      |_|                                       |___/
*/
//-----------Computer Player Class--------------------------------------------------------------
//Computer Player inherits the Player class, so by default, every data member and function
// member and function member in Player now exists in Computer Player
// Author: Artur Cabral
//---------------------------------------------------------------------------------------
class ComputerPlayer :public Player {
public:
	ComputerPlayer(std::string cname, int compNumber);
	~ComputerPlayer();
	void decideOnAMove(TTTBoard3 *Board, int passedN, int compNumber);
private:
	
};
//======== Computer Player Functions ==================================================

//------ constructor -------------------------------------------
ComputerPlayer::ComputerPlayer(std::string cname, int compNumber) : Player(cname, compNumber) {
	
}

// ---- end of constructor-------------------------------------

//destructor-----------------------------------------------
ComputerPlayer::~ComputerPlayer(){}
//---------------------------------------------------------

//------ decideOnAMove---------------------------------------------
void ComputerPlayer::decideOnAMove(TTTBoard3 *Board, int passedN, int compNumber) {
	int N = passedN;
	//check if there is a winning move
	//generates a random move
	for (int ii = 0; ii < 100000; ii++) {
		int i2, j2, k2;
		i2 = rand() % N;
		j2 = rand() % N;
		k2 = rand() % N;
		//checks if the move is okay
		if (Board->isOkayMove(i2, j2, k2) == true) {
			//if okay, place move on the board
			Board->putMove(i2, j2, k2, compNumber);
			//check if the move wins the game, if not, reset to -1
			if (Board->isWinner(compNumber) == false) { //if the move doesn't win the game, erase move
				Board->putMove(i2, j2, k2, -1);
			}
			//if it wins the game, return
			else return;
			//Look for a spot that player can win, anc place a move there
			Board->putMove(i2, j2, k2, !compNumber);
			//Check to see if player can win with that move, if so, place computer move there to block it
			if (Board->isWinner(!compNumber) == true) {
				Board->putMove(i2, j2, k2, compNumber);
				std::cout << "Computer plays: (" << i2 << "," << j2 << "," << k2 << ")" << std::endl;
				return;
			}
			Board->putMove(i2, j2, k2, -1);
				
			
		}
	}
	//place move if isWinner true

	//erase movement, set currentState[i][j][k] = -1, and try another move

	//if no winning move, place a random move on an empty spot
	//generates a random move
	for (int ii = 0; ii < 100000; ii++) {
		int i2, j2, k2;
		i2 = rand() % N;
		j2 = rand() % N;
		k2 = rand() % N;
		//checks if the move is okay
		if (Board->isOkayMove(i2, j2, k2) == true) {
			//if okay, place move on the board
			Board->putMove(i2, j2, k2, compNumber);
			std::cout << "Computer plays: (" << i2 << ","<< j2 << "," << k2 << ")" << std::endl;
			break;
		}
	}
}
//----end of decideOnAmove-----------------------------------------
void playGame() {
	std::cout << " ___________   _____ _           _____               _____ " << std::endl;
	std::cout << "|____ | __  \\ |_   _(_)         |_   _|             |_   _|" << std::endl;
	std::cout << "   / / |  | |   | |  _  ___ ______| | __ _  ___ ______| | ___   ___" << std::endl;
	std::cout << "   \\ \\ |  | |   | | | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\ " << std::endl;
	std::cout << ".___/ /| / /    | | | | (__       | | (_| | (__       | | (_) |  __/" << std::endl;
	std::cout << "\\____/|___/     \\_/ |_|\\___|      \\_/\\__,_|\\___|      \\_/\\___/ \\___| " << std::endl;
	// Declare a temporary N (passedN)
	int passedN;
	//Declare the pick coordinates and player
	int player, isIt;

	//Create two players
	//Player player0(0);
	//Player player1(1);
	ComputerPlayer cplayer0("Computer X", 0);
	ComputerPlayer cplayer1("Computer O", 1);
	// Ask use to enter in the board size. 
	std::cout << "What size of the board do you want? ";
	// Read in board size as passedN
	std::cin >> passedN;
	if (passedN == 3 || passedN == 4 || passedN == 5) {
		// declare an instance of TTTBoard, initializing with the value of passedN
		TTTBoard3 myBoard(passedN);
		myBoard.displayBoard();

		for (int i = 0; i < passedN*passedN*passedN; i++) {
			player = i % 2;
			if (player == 0) {// EVEN - X player			
							  // ask for a move, place an X
							  //call function makeMove
				cplayer0.decideOnAMove(&myBoard, passedN, 0);
				// check to see if they won (isWinner)
				myBoard.isWinner(player);
				if (myBoard.isWinner(player) == true) {
					std::cout << cplayer0.getName() << " is the WINNER! Congratulations!" << std::endl;
					myBoard.displayBoard();
					return;
				}

				// check for a Stalemate
				myBoard.isStalemate();
				if (myBoard.isStalemate() == true) {
					std::cout << "It's a TIE, nobody won this game!\n" << std::endl;
					myBoard.displayBoard();
					return;
				}
				//Display board
				myBoard.displayBoard();
			}

			else {
				// ask for a move, place an O
				//call function makeMove
				cplayer1.decideOnAMove(&myBoard, passedN, 1);
				// check to see if they won (isWinner)
				myBoard.isWinner(player);
				if (myBoard.isWinner(player) == true) {
					std::cout << cplayer1.getName() << " is the WINNER! Congratulations!" << std::endl;
					myBoard.displayBoard();
					return;
				}

				//Display board
				myBoard.displayBoard();

			}
		}

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

		std::cout << "Play another game? (1=yes/0=no): ";
		std::cin >> answer;

	} while (answer == 1);
	system("pause");
	return(0);
}
/*=============WORK IN PROGRESS===================================
Creating a menu so you can pick and choose player 0 or 1 to be person or computer

code so far:
//Declare the pick coordinates and player
int player, isIt, player0, player1;
//Ask if player 0 is player or computer
std::cout << "Player0 -> (0 = Person Player, 1 = Computer Player)";
std::cin >> player0;
if(player0 == 0)
Player player0(0);
else
ComputerPlayer cplayer("Computer X", 0);
//Ask if player 1 is player or computer
std::cout << "Player0 -> (0 = Person Player, 1 = Computer Player)";
std::cin >> player1;
if (player1 == 0)
Player player1(1);
else
ComputerPlayer cplayer("Computer O", 1);

*/