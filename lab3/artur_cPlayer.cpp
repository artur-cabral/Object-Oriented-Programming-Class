/*
  ___       _              _       _____                             _            
 / _ \     | |            ( )     /  __ \                           | |           
/ /_\ \_ __| |_ _   _ _ __|/ ___  | /  \/ ___  _ __ ___  _ __  _   _| |_ ___ _ __ 
|  _  | '__| __| | | | '__| / __| | |    / _ \| '_ ` _ \| '_ \| | | | __/ _ \ '__|
| | | | |  | |_| |_| | |    \__ \ | \__/\ (_) | | | | | | |_) | |_| | ||  __/ |   
\_| |_/_|   \__|\__,_|_|    |___/  \____/\___/|_| |_| |_| .__/ \__,_|\__\___|_|   
                                                        | |                       
                                                        |_|                       
 ______ _                                                                         
 | ___ \ |                                                                        
 | |_/ / | __ _ _   _  ___ _ __                                                   
 |  __/| |/ _` | | | |/ _ \ '__|                                                  
 | |   | | (_| | |_| |  __/ |                                                     
 \_|   |_|\__,_|\__, |\___|_|                                                     
                 __/ |                                                            
                |___/
*/


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
			//check if the move wins the game
			if (Board->isWinner(compNumber) == false) { //if the move doesn't win the game, erase move
				Board->putMove(i2, j2, k2, -1);
			}
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