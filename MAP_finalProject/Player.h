#pragma once
#include <string>
#include<vector>
#include"Item.h"
#include"Creature.h"

//-----------Player.h-----------
//
//Author: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
// Player.h is the header file for Player.cpp listing all functions included in the player class, defining what they do 
//Includes the functions that creates the player, lists it's inventory, adds to inventory and the function used to fight enemies
//
//-------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------
/*

,------. ,--.                                        ,--.
|  .--. '|  | ,--,--.,--. ,--.,---. ,--.--.     ,---.|  | ,--,--. ,---.  ,---.
|  '--' ||  |' ,-.  | \  '  /| .-. :|  .--'    | .--'|  |' ,-.  |(  .-' (  .-'
|  | --' |  |\ '-'  |  \   ' \   --.|  |       \ `--.|  |\ '-'  |.-'  `).-'  `)
`--'     `--' `--`--'.-'  /   `----'`--'        `---'`--' `--`--'`----' `----'
`---'
*/
//--------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------

class Player {

public:
	std::vector<Item> inventory;
	void addToInventory(Item addThis);
	void printInventory();
	// vector of items, and "taking an item" push back into the vector.
	// description
	//int descprition, is battle item, damage

	Player(std::string myName, int hp, int damage);
	~Player();
	std::string name;
	//int MakeMove();
	bool Fight(Creature *thisCreature, Item thisItem);
	int currentI;
	int currentJ;


private:
	int hp;
	int damage;
	//Mage(std::string myName, int hp, int damage);       //  -Stats, passive.
	//Warrior(std::string myName, int hp, int damage);   //   - Stats, passive.
	//Rouge(std::string myName, int hp, int damage);    //    - Stats, Passive.
	//Healer(std::string myName, int hp, int damage);  //     - Stats, Passive.

};