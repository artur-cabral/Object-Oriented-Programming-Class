#include <iostream>
#include <vector>
#include "c4Board.h"
#include "c4Player.h"

/*
______                     _   _____ _
| ___ \                   | | /  __ \ |
| |_/ / ___   __ _ _ __ __| | | /  \/ | __ _ ___ ___
| ___ \/ _ \ / _` | '__/ _` | | |   | |/ _` / __/ __|
| |_/ / (_) | (_| | | | (_| | | \__/\ | (_| \__ \__ \
\____/ \___/ \__,_|_|  \__,_|  \____/_|\__,_|___/___/
______                _   _
|  ___|              | | (_)
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
\_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/
//--------------CONSTRUCTOR------------------------------------------------
c4Board::c4Board() {
	//Make 7 x 6 board
	std::vector<int> temp;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++)
			temp.push_back(-1);
		currentState.push_back(temp);
		temp.clear();
	}
	displayBoard();
}
//---------DESTRUCTOR------------------------------------------------------
c4Board::~c4Board(){}

//-------DISPLAY BOARD------------------------------------------------------
void c4Board::displayBoard() const {
	// This clears the screen (WINDOWS ONLY!!!!) and makes a heading
	system("cls");

	// The "height" loop
	printf("\n|-0-|-1-|-2-|-3-|-4-|-5-|-6-|\n");
	//This loop goes through each row (top to bottom - r.begin())
	for (auto outItr = currentState.rbegin(); outItr != currentState.rend(); outItr++) {
		printf("|---------------------------|\n|");
		// The "length" loop - goes through each column
		for (auto inItr = outItr->begin(); inItr < outItr->end(); ++inItr) {
			if (*inItr == -1)
				printf("   |");
			else if (*inItr == 0)
				printf(" X |");
			else if (*inItr == 1)
				printf(" O |");
		}
		printf("\n");
	}
	printf("|---------------------------|\n");
}

//--------PUT MOVE----------------------------------------------------
//Idea is a user picks a column number. We start scanning at the bottom of the colum and work
//our way up. the first empty spot we see in that column, we place their move. If it ends up 
//that the column is full, we return a false
bool c4Board::putMove(int columnNumber, int playerNumber) {
	//if the column they want is full, let's just quit
	//take the top row (rbegin - "reverse beginning")
	if (*(currentState.rbegin()->begin() + columnNumber) != -1)	
		return false;
	//make an outter iterator(rows)
	auto outItr = currentState.begin();
	//make an inner iterator(columns)
	auto innerItr = outItr->begin() + columnNumber;
	//loop through the outter iterator and see if currentState is -1. If so, place the move and return
	for (outItr; outItr < currentState.end(); outItr++) {
		//going up
		if (*(outItr->begin() + columnNumber) == -1) {
			*(outItr->begin() + columnNumber) = playerNumber;
			return (true);
		}
	}
}

//----------------IS WINNER ----------------------------------------------
bool c4Board::isWinner(int playerNumber) {
	bool wins;
	//horizontal check for winner
	wins = false;
	//for this check, we need a double iterator to check on the rows and then the colums
	//the outter iterator is to check the rows (from row 0 until row 6)
	for (auto outItr = currentState.begin(); outItr < currentState.end(); outItr++) {
		//the inner iterator is going to check the columns, and the player has to have 4 in a row
		//only go from column 0 until column 3
		for (auto inItr = outItr->begin(); inItr < outItr->begin() + 3; inItr++) {
			wins = true;
			for (int i = 0; i < 4; i++)
				if (*(inItr + i) != playerNumber)
					wins = false;
			if (wins) {
				std::cout << " Horizontal win by player " << playerNumber << std::endl;
				return(true);
			}
		}
	}

	//vertical check for winner
	wins = false;
	// Column counter (outside, since that is our "slow index")
	for (int i = 0; i < 7; i++) {
		//row loop. only need first 3 rows
		for (auto outItr = currentState.begin(); outItr < currentState.begin() + 3; outItr++) {
			//Now, for the column specified by i, loop down 4 rows and see if same person owns all of them
			wins = true;
			for (int j = 0; j < 4; j++) {
				if(*((outItr+j)->begin()+i)!= playerNumber)
					wins=false;
			}
			if (wins) {
				std::cout << " Vertical win by player " << playerNumber << std::endl;
				return(true);
			}
		}
	}
	//diagonals check for winner
	wins = false;
	//diagonals bottom left to up right
	//coulumn switching loop (from columns 0 until 3)
	for (int i = 0; i < 4; i++) {
		//outter iterator to go through the rows 0 until 2 to cover all possible rows of this section
		for (auto outItr = currentState.begin(); outItr < currentState.begin() + 2; outItr++) {
				wins = true;
				for (int k = 0; k < 4; k++) {//loop used to add a row and a column to reach the diagonals of this section
					if (*((outItr + k)->begin() + k + i) != playerNumber)
						wins = false;
					}
				if (wins) {
					std::cout << " Diagonal win by player " << playerNumber << std::endl;
					return(true);
				}
		}//outter iterator end
	}//columns for loop ends
	
	//diagonals bottom right to up left
	//same idea here, but with decreasing loops to cover the other side of the board
	wins = false;
	//diagonals bottom left to up right
	//coulumn switching loop (from columns 0 until 3)
	for (int i = 6; i > 2; i--) {
		//outter iterator to go through the rows 0 until 2 to cover all possible rows of this section
		for (auto outItr = currentState.begin(); outItr < currentState.begin() + 2; outItr++) {
			wins = true;
			for (int k = 0; k < 4; k++) {//loop used to add a row and a column to reach the diagonals of this section
				if (*((outItr + k)->begin() + i - k) != playerNumber)
					wins = false;
			}
			if (wins) {
				std::cout << " Diagonal win by player " << playerNumber << std::endl;
				return(true);
			}
		}//outter iterator end
	}//columns for loop ends

}
//--------------end of isWinner--------------------------------------------------------
