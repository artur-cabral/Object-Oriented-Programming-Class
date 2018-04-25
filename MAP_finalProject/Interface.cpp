/*Authors:	 Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
Professor: Paul Dostert
Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
gameInterface.h is the header file for gameInterface.cpp which defines all functions for the Interface class and comments what each function does
*/
#pragma once 
#include "Interface.h"
#include "Map.h"
#include "Rooms.h"
#include "Item.h"
#include "Creature.h"
#include "Player.h"

#include<iostream>
#include<string>
#include<vector>

//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------

//----------------Constructor-------------------------------------
Interface::Interface(Player *myPlayer) { //constructor
	thePlayer = myPlayer;	//Allows the players name equal to the dummy variable (myPlayer), which changes the actual players name 
}

//----------------Destructor-------------------------------------
Interface::~Interface() { //destructor
						  //nothing
}

//----------------Display Inventory-------------------------------------
//Calls for the print inventory function from the player class
void Interface::displayInventory() { //displays the inventory when the user prompts it
	thePlayer->printInventory();
}

//----------------Display Help-------------------------------------
//When Prompted, user can access the commands for the game
void Interface::displayHelp() {
	std::cout << "Here are the commands for the game : " << std::endl;
	std::cout << "H - Help (obviously you figured this one out)" << std::endl;
	std::cout << "I - Inventory (Lets you veiw your loot from your adventure)" << std::endl;
	std::cout << "N , E , S , W - Directions (Choose either N, E, S, W to move to a room in that direction if avaliable) " << std::endl;
	std::cout << " " << std::endl;

};

//----------------Go There-------------------------------------
//based on user inputs, this function will move the player and update their location through
//currentI and currentJ 
void Interface::goThere(int I, int J) { //depending on what direction they type, this moves the user
	thePlayer->currentI = I;
	thePlayer->currentJ = J;

};


//----------------Sort Input-------------------------------------
//this function takes the string input from the player and sorts it to access various 
//functions for gameplay (fighting, picking up items, exploring, checking inventory)
void Interface::sortInput(std::string command, Rooms *thisRoom) { //when prompted, this will tell the user the commands that are avaliable to them in the game
																  //this would be full of "if" loops to help direct user inputs to functions in the player and map classes
																  //once we create halping functions, the "sortInput" function can point to those for help and then they could point to map or player class
	int i = thePlayer->currentI, j = thePlayer->currentJ, I, J;

	//######################################################################################################################################
	//														INVENTORY AND INSTRUCTIONS
	//######################################################################################################################################

	if (command == "m" || command == "h" || command == "help" || command == "manual")	//If player types help or anyother listed commands, displayhelp is called
		displayHelp();

	if (command == "i" || command == "inventory")	//Commands required for the players inventory to be printed
		displayInventory();

	//######################################################################################################################################
	//														FIGHTING PROMPTERS
	//######################################################################################################################################

	//-------------------------BOSS KILL FUNCTION --------------------------------------------------------------------
	if (command.find("fight") != std::string::npos ||
		command.find("kill") != std::string::npos ||
		command.find("attack") != std::string::npos ||
		command.find("hit") != std::string::npos) { //if the user input contains the word "fight" then that triggers the player to attack
		for (auto invItr = thePlayer->inventory.begin(); invItr < thePlayer->inventory.end(); ++invItr) {
			if (invItr->name == "divine rapier") //sets the command equal to the name of the current item being cycled through in the itr
				if (command.find("divine rapier") != std::string::npos) { //searches the command for item name and searches player inventory to use matching item
					for (auto enemyItr = thisRoom->enemies.begin(); enemyItr < thisRoom->enemies.end(); ++enemyItr) {
						if (enemyItr->name == "roshan") //sets the command equal to the name of the enemy being searched
							if (command.find("roshan") != std::string::npos) { //searches the command for enemy name and searches the iterator of enemies to find a matching name
								std::cout << "Roshan will destroy you!" << std::endl;
								thePlayer->Fight(&(*enemyItr), *invItr);
								while (true)
								{
									if (enemyItr->hp > 0) { //if the enemy still has life, give user the option to keep fighting or run
															//	std::cout << enemyItr->hp << std::endl;
										std::string answer;
										std::cout << "Keep fighting? ";
										std::cin >> answer;
										std::cin.ignore();
										if (answer == "yes" || answer == "y")
											thePlayer->Fight(&(*enemyItr), *invItr);

										else if (answer == "no" || answer == "n") //lets the user exit the fighting function and continue playing
											return;
									}
									else if (enemyItr->hp <= 0) { //once the enemy is defeated, it is removed from the map
										thisRoom->removeEnemy(enemyItr->name);
										std::cout << "#############################################################################" << std::endl;
										std::cout << "#############################################################################" << std::endl;
										std::cout << "############## CONGRATULATIONS YOU HAVE KILLED THE EVIL ROSHAN ##############" << std::endl;
										std::cout << "#############################################################################" << std::endl;
										std::cout << "#############################################################################" << std::endl;
										system("pause");
										exit(EXIT_SUCCESS);
									}

								}

							}
					}
				}
		}
	}

	//------------------------------------------kill function-------------------------------------------------
	if (command.find("fight") != std::string::npos ||
		command.find("kill") != std::string::npos ||
		command.find("attack") != std::string::npos ||
		command.find("hit") != std::string::npos) { //if the user input contains the word "fight" then that triggers the player to attack
		for (auto invItr = thePlayer->inventory.begin(); invItr < thePlayer->inventory.end(); ++invItr) {
			std::string commandItemName = invItr->name; //sets the command equal to the name of the current item being cycled through in the itr
			if (invItr->name == "divine rapier") {
				std::cout << "------------- You should save this weapon for a greater evil -----------" << std::endl;
				return;
			}
			if (command.find(commandItemName) != std::string::npos) { //searches the command for item name and searches player inventory to use matching item
				for (auto enemyItr = thisRoom->enemies.begin(); enemyItr < thisRoom->enemies.end(); ++enemyItr) {
					std::string commandEnemyName = enemyItr->name; //sets the command equal to the name of the enemy being searched
					if (enemyItr->name == "roshan") {
						std::cout << "------------- Roshan laughs ''You must find the devine rapier to fight me! Keep exploring puny human!'' -----------" << std::endl;
						return;
					}
					if (command.find(commandEnemyName) != std::string::npos) { //searches the command for enemy name and searches the iterator of enemies to find a matching name
						thePlayer->Fight(&(*enemyItr), *invItr);
						while (true)//enemyItr->hp>0)
						{
							if (enemyItr->hp > 0) { //if the enemy still has life, give user the option to keep fighting or run
													//	std::cout << enemyItr->hp << std::endl;
								std::string answer;
								std::cout << "Keep fighting? ";
								std::cin >> answer;
								std::cin.ignore();
								if (answer == "yes" || answer == "y")
									thePlayer->Fight(&(*enemyItr), *invItr);

								else if (answer == "no" || answer == "n") //lets the user exit the fighting function and continue playing
									return;
							}
							else if (enemyItr->hp <= 0) { //once the enemy is defeated, it is removed from the map
								thisRoom->removeEnemy(enemyItr->name);
								return;
							}

						}

					}
				}
			}
		}
	}


	//######################################################################################################################################
	//														GRAB ITEM / ADD TO INVENTORY
	//######################################################################################################################################


	//List of all commands needed for player to use to pick up the current item inside the room
	if (command.find("pick") != std::string::npos ||
		command.find("grab") != std::string::npos ||
		command.find("take") != std::string::npos ||
		command.find("get") != std::string::npos) {
		for (auto itmItr = thisRoom->items.begin(); itmItr < thisRoom->items.end(); ++itmItr) {
			//std::string commandItemName = itmItr->name; //sets the command equal to the name of the current item being cycled through in the itr
			if (command.find(itmItr->name) != std::string::npos) { //searches the command for item name and searches player inventory to use matching item
				thePlayer->addToInventory(*itmItr);		//The player adds the item to its inventory 
				thisRoom->removeItem(itmItr->name);		//While room removes the item from the location
				break;
			}
		}
	}


	//######################################################################################################################################
	//															MOVING / DIRECTIONS
	//######################################################################################################################################


	if (command == "n" || command == "north" || command == "up") {	//Location for north
		if (thisRoom->exits[0] == true) {	//Determines if the move is valid or not(end of board)
			J = j + 1;	//Determines the Y(J) value for the coordinate
			I = i;	//Since north is going up, only the y(J) value will change, x(I) stays the same
			goThere(I, J);
		}
		else { //tells the user that this is not an exit and to try another path
			std::cout << "The exit is blocked! You must find another way out." << std::endl;
		}
	}

	else if (command == "e" || command == "east" || command == "right") {
		if (thisRoom->exits[2] == true) {
			J = j;
			I = i + 1;
			goThere(I, J);
		}
		else { //tells the user that this is not an exit and to try another path
			std::cout << "The exit is blocked! You must find another way out." << std::endl;
		}
	}

	else if (command == "s" || command == "south" || command == "down") {
		if (thisRoom->exits[1] == true) {
			J = j - 1;
			I = i;
			goThere(I, J);
		}
		else { //tells the user that this is not an exit and to try another path
			std::cout << "The exit is blocked! You must find another way out." << std::endl;
		}
	}

	else if (command == "w" || command == "west" || command == "left") {
		if (thisRoom->exits[3] == true) {
			J = j;
			I = i - 1;
			goThere(I, J);
		}
		else { //tells the user that this is not an exit and to try another path
			std::cout << "The exit is blocked! You must find another way out." << std::endl;
		}
	}

};