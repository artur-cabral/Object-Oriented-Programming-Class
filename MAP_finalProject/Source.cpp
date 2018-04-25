#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <utility>
#include <algorithm>

#include "Interface.h"
#include "Map.h"
#include "Rooms.h"
#include "Item.h"
#include "Player.h"


int main()
{
	int size, N;
	srand((unsigned)time(NULL));

	Player myPlayer("", 100, 5); //sets the player's base hp as 100 and damage as 5
	Interface myinterface(&myPlayer);
	std::cout << "Please choose a size for your map: Easy - 1, Medium - 2, Hard - 3" << std::endl;
	std::cin >> N; //allows the user to input a map difficulty that they want to play
	if (N = 1)
		size = 8;
	else if (N = 2)
		size = 10;
	else if (N = 3)
		size = 12;
	Map gameMap(size, " ");

	std::string name;
	std::cout << "Hello Adventurer, please, enter your full name to begin your quest: ";
	std::cin.ignore(); //takes in the user name
	std::getline(std::cin, name);

	std::cout << "------------------------------------------------------------------------------" << std::endl;
	std::cout << "//////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	std::cout << "Hello, " << name << "!\n";
	gameMap.winPath(); //defines the winning room with roshan
	gameMap.editExits(); //blocks paths to make game more difficult

	std::string command;

	while (true) { //displays what is in the room or display situation then prompt for a command

		gameMap.map[myPlayer.currentI][myPlayer.currentJ].scanRoom(); //scans the current room
		std::cout << name << ", what would you like to do next?" << std::endl;

		std::getline(std::cin, command);//get command			
		std::transform(command.begin(), command.end(), command.begin(), ::tolower); //changes entry to lowercase
		myinterface.sortInput(command, &gameMap.map[myPlayer.currentI][myPlayer.currentJ]);//take command and sort through it

	}


	system("pause");
	return 0;
}