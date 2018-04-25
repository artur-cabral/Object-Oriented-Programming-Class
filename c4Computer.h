#pragma once
#include <vector>
#include <iostream>
#include "c4Player.h"

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
class ComputerPlayer :public c4Player {
public:
	ComputerPlayer(std::string cname, int compNumber);
	~ComputerPlayer();
	void chooseMove(c4Board *Board, int compNumber);
private:

};