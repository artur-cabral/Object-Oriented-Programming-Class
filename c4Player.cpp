#include <iostream>
#include <string>
#include "c4Player.h"
#include "c4Board.h"

/*
______ _                         _____ _
| ___ \ |                       /  __ \ |
| |_/ / | __ _ _   _  ___ _ __  | /  \/ | __ _ ___ ___
|  __/| |/ _` | | | |/ _ \ '__| | |   | |/ _` / __/ __|
| |   | | (_| | |_| |  __/ |    | \__/\ | (_| \__ \__ \
\_|   |_|\__,_|\__, |\___|_|     \____/_|\__,_|___/___/
__/ |
|___/
______                _   _
|  ___|              | | (_)
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
\_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/

*/
//--------------------------constructor-------------------------------------------
// asks player for name and assigns to a string. assigns player 0 or 1 as well
c4Player::c4Player(int pnumber) {
	playerNumber = pnumber;
	std::cout << " Player " << playerNumber << " , please enter your name: ";
	std::cin >> playerName;

}
//----computerPlayerConstructor--------------------------------------------
c4Player::c4Player(std::string cname, int pnumber) {
	playerNumber = pnumber;
	playerName = cname;
}
//---------------------destructor---------------------------------------------
c4Player::~c4Player() {};

//--------------------getName-------------------------------------
std::string c4Player::getName() {
	return(playerName);
}

//--------------getPlayerNumber-------------------------------------
int c4Player::getPlayerNumber() {
	return(playerNumber);
}

//-------- makeMove --------------------------------------------------------------------
//Accepts column and player # as input.Puts X or O in the specified column, if possible.
// Returns error if the slot is not empty.
//--------------------------------------------------------------------------------------
bool c4Player::makeMove(c4Board *Board) {
	int column;
	//Do a while until the person gives a valid move
	do {
		//Prompt the player for a 3D coordinate
		std::cout << getName() << ", please choose a column you want to play" << std::endl;
		std::cin >> column;
		//Return whether or not it is a valid move (valid move is =-1, because currentState is empty when currentState[i][j][k]=-1)
		if (Board->putMove(column, playerNumber) == true) {
		//If spot is empty, place the move and return
			return(true);
		 }
			 
		
		else {//If the spot is not empty, let the user know and repeat
			std::cout << "That's not a valid move " << playerName << std::endl;
	
		}
	} while (Board->putMove(column, playerNumber) == false);
	//---------------------------------------------------------------------

}//-----End of makeMove-----------------------------------------------------



