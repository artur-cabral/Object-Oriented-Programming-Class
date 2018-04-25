#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Creature.h"
#include "Item.h"

//-----------Rooms.h-----------
//Author:Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor:Paul Dostert
//Summary:The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
//Rooms.h header file which lists all the functions used for the rooms class. Includes functions to add, remove, scan the rooms and define what the winning path is
//
//-------------------------------


class Rooms {
public:
	//constructor (each room has a description, items, and exit status)
	Rooms(std::vector<bool> exit, std::string item, std::string enemy);
	//constructor 2 - with exits, items, enemies, and plus a description
	Rooms(std::string roomDescription, std::vector<bool> exit);
	//destructor
	~Rooms();
	//Functions
	void addItem(Item item);//adds an item to a room

	void removeItem(std::string item);//removes an item of the room

	void addCreature(Creature enemy);//add an enemy to the room

	void removeEnemy(std::string enemy);//removes an enemy from the room

	std::vector<Item> items;//items contained in the room

	std::vector<Creature> enemies;//enemies contained in the room

	void scanRoom();//look around the room

	bool onWinningPath;//checks if it is on winning path

	std::vector<bool>exits;//exits of the room

	std::vector<std::string> directions{ "North","South","East","West" };

	std::string description;//description of the room

	bool hasVisited;//to check if the player has visited the room

	std::string enemy;

private:



};

