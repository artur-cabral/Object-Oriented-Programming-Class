#pragma once
#include <vector>
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

class c4Board {
public:
	//constructor: the function to run to create the board using an array NxN given by the user
	c4Board();
	//Destructor: Clears the memory(delete currentState)
	~c4Board();
	void displayBoard()const;
	bool isWinner(int whichPlayer);
	bool putMove(int columnNumber, int playerNumber);
	std::vector<std::vector<int>>currentState;

	
private:
	


};
