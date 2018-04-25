#include <iostream>
#include <vector>
#include <string>
#include "Rooms.h"
#include "Map.h"

//-----------Room.cpp-----------
//Author:Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary:
//
//-------------------------------

//-----------CONSTRUCTOR-----------------------------------------
//The constructor creates an empty room
Rooms::Rooms(std::vector<bool> exit, std::string item, std::string enemy) {
	exits = exit;
	onWinningPath = false;
	hasVisited = false;
	//Old way
	/*std::cout << "This room contains: " << item << std::endl;
	std::cout << "There is a " << enemy << " to be defeated!" << std::endl;

	//print available exits
	std::cout << "This room has exits on: ";
	for (int i = 0; i < 4; i++) {

	//display available exits
	if (exits[i])
	std::cout << directions[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	*/
}
//second constructor creates a room with a description
//The constructor creates an empty room
Rooms::Rooms(std::string roomDescription, std::vector<bool> exit) {
	description = roomDescription;
	exits = exit;
	onWinningPath = false;
	hasVisited = false;
	//std::cout << description << std::endl;
	//scanRoom();
	//std::cout << "This room contains a ";
	//for (auto itr = items.begin(); itr < items.end(); itr++)
	//	std::cout << itr->name << " ";
	//std::cout << "There is a ";
	//for (auto itr = enemies.begin(); itr < enemies.end(); itr++)
	//	std::cout << itr->name << " ";
	//std::cout << " to be defeated!" << std::endl;

	////print available exits
	//std::cout << "This room has exits on: ";
	//for (int i = 0; i < 4; i++) {

	//	//display available exits
	//	if (exits[i])
	//		std::cout << directions[i] << "  ";
	//}
	//std::cout << std::endl;
	//std::cout << std::endl;
}
//-------DESTRUCTOR----------------------------------------------
Rooms::~Rooms() {}
//Nothing goes here

//-----------ADD ITEM--------------------------------------
//This function adds an item to the room when we are creating
//the game
void Rooms::addItem(Item item) {
	items.push_back(item);
	//std::cout << "Item added: " << item.name << std::endl;
}

//---------- ADD ENEMY----------------------------------------
//This function adds an enemy to a room when we are creating the game
void Rooms::addCreature(Creature enemy) {
	enemies.push_back(enemy);
	//std::cout << "Enemy added: " << enemy.name << std::endl;
}


//--------- REMOVE ITEM ------------------------------------------
//This function is used when a player picks up an item from the room,
//so now, the item gets removed from the room, and it's possessed by the player
void Rooms::removeItem(std::string item) {
	//loop through the items vector, if input string == item string
	//then remove item from vector
	for (auto itr = items.begin(); itr < items.end(); itr++) {
		if (itr->name == item) {
			//std::cout << "Item erased: " << item << std::endl;
			items.clear();
			//std::cout << " There are " << items.size() << " items" << std::endl;
			return;
		}

	}

}

//------- REMOVE ENEMY -----------------------------------------
//This function is used to delete the enemy from the room, which means that the 
//player have defeated the enemy, so it "dies" and gets removed from the room
void Rooms::removeEnemy(std::string enemy) {
	//loop through the items vector, if input string == item string
	//then remove item from vector
	//std::cout << "!!!!!---There are " << enemies.size() << " enemies in the room" << std::endl;
	for (auto itr = enemies.begin(); itr < enemies.end(); itr++) {
		if (itr->name == enemy) {
			//std::cout << "Enemy erased: " << enemy << std::endl;
			enemies.clear();
			return;
		}

	}

}
//--------- SCAN ROOM --------------------------------------------
//This function scans the room and tells the player which items are
//available to be picked up, which enemies, if any, there are in that room,
//and which are the open exits
void Rooms::scanRoom() {
	int counter = 0;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << description << std::endl;
	std::cout << "When you look around you see ";
	//iterator to print out the items of the room
	if (items.size() == 0) //if there are no items
		std::cout << "no items to be picked up ";
	else
		for (auto itr = items.begin(); itr < items.end(); itr++)
			std::cout << "a " << itr->name << " ";

	std::cout << "on the floor, ";
	//iterator to print out the enemies inside the room

	if (enemies.size() == 0) //if there are no enemies
		std::cout << "and no enemies around.";
	else {
		std::cout << "and you realize there is ";
		for (auto itr = enemies.begin(); itr < enemies.end(); itr++)
			std::cout << "a " << itr->name << " that you have to kill.";
	}

	//iterator to print out the exits of this room
	if (items.size() == 0 && enemies.size() == 0)
		std::cout << " You can go ";
	else
		std::cout << " If you want to run, you can go ";

	for (auto itr = exits.begin(); itr < exits.end(); itr++) {
		if (*itr == 1)
			std::cout << directions[counter] << " , ";
		counter++;
	}//end of iterator
	std::cout << "\b\b" << "  " << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
}
