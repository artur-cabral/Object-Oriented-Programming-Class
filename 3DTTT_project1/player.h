#pragma once
#include <iostream>
#include <string>
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
______          _                 _   _                 
|  _  \        | |               | | (_)                
| | | |___  ___| | __ _ _ __ __ _| |_ _  ___  _ __  ___ 
| | | / _ \/ __| |/ _` | '__/ _` | __| |/ _ \| '_ \/ __|
| |/ /  __/ (__| | (_| | | | (_| | |_| | (_) | | | \__ \
|___/ \___|\___|_|\__,_|_|  \__,_|\__|_|\___/|_| |_|___/
*/

class Player {
public:
	//constructor: asks player for name and assigns to a string. assigns player 0 or 1 as well
	Player(int playerNumber);
	Player(std::string cname, int pnumber);
	//destructor
	~Player();
	//makeMove: take the board as (i,j,k) as arguments and make a move, if possible
	bool makeMove(TTTBoard3 *Board);
	//getName: returns the player's name
	std::string getName();
	//getPlayerNumber: returns the player number to make a move
	int getPlayerNumber();
private:
	//name(player's name string
	std::string name;
	//number(player 0 or 1)
	int playerNumber;
};