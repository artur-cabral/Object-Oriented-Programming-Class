#include <iostream>
#include <string>
#include "player.h"
#include "TTTBoard3.h"

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
Player::Player(int pnumber) {
	playerNumber = pnumber;
	std::cout << " Player "<< playerNumber << " , please enter your name: ";
	std::cin >> name;
	
}
//----computerPlayerConstructor--------------------------------------------
Player::Player(std::string cname, int pnumber) {
	playerNumber = pnumber;
	name = cname;
}
//---------------------destructor---------------------------------------------
Player::~Player() {};

//--------------------getName-------------------------------------
std::string Player::getName() {
	return(name);
}

//--------------getPlayerNumber-------------------------------------
int Player::getPlayerNumber() {
	return(playerNumber);
}

//-------- makeMove --------------------------------------------------------------------
//Accepts coordinates(i, j, k) and player # as input.Puts X or O in(i, j) location, if possible.
// Returns error if the slot is not empty.
//
//--------------------------------------------------------------------------------------
bool Player::makeMove(TTTBoard3 *Board) {
	int i, j, k;
	bool play = true;
	//Do a while until the person gives a valid move
	do {
		//Prompt the player for a 3D coordinate
		std::cout << getName() << ", please choose a move in the format: i j k" << std::endl;
		std::cin >> i >> j >> k;
		//Return whether or not it is a valid move (valid move is =-1, because currentState is empty when currentState[i][j][k]=-1)
		play = Board->isOkayMove(i, j, k); //Just returns currentState[i][j][k]
		//If spot is empty, place the move and return
		if (play) {
			Board->putMove(i, j, k, playerNumber);
			return(true);
		}
		else //If the spot is not empty, let the user know and repeat
			std::cout << "That's not a valid move " << name << std::endl;
		
	} while (!play);
	//---------------------------------------------------------------------

}//-----End of makeMove-----------------------------------------------------



