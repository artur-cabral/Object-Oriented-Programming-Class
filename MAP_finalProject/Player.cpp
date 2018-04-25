#pragma once
#include <string>
#include<vector>
#include"Item.h"
#include"Player.h"
#include"Creature.h"
#include<iostream>
//-----------Player.cpp-----------
//
//Author: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
// Player.cpp lists all functions included in the player class, defines what they do 
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


// ----------------------------------PLAYER CLASS FUNCTIONS------------------------------------------------------



//-------------CONSTRUCTOR--------------------------------------------
Player::Player(std::string myName, int Playerhp, int PlayerDamage) {
	currentI = 3;
	currentJ = 0;
	name = myName;
	hp = Playerhp;
	damage = PlayerDamage;
	inventory.push_back(Item("fist", 0, 5));
}

// -----------------DESTRUCTOR-----------------------------------------
Player::~Player() {};

//-------------------ADD ITEM TO INVENTORY-----------------------------
void Player::addToInventory(Item addThis) {

	//object we want to add to inventory
	inventory.push_back(addThis);


}

//----------------- PRINT INVENTORY---------------------------------------
void Player::printInventory() {
	//itr inventory.name
	for (auto myItr = inventory.begin(); myItr < inventory.end(); ++myItr) {
		std::cout << myItr->name << " " << "\thp: " << myItr->hp << "\tdamage: " << myItr->damage << std::endl;
	}
}


//----------------FIGHT FUNCTION-------------------------------------------
bool Player::Fight(Creature *thisCreature, Item thisItem) {
	int dmg = rand() % 4; // (0,1,2,3)

	if (dmg == 3) {
		thisCreature->hp = thisCreature->hp - (thisItem.damage + damage);
		std::cout << "You hit the " << thisCreature->name << " with the " << thisItem.name << " and land a powerful stike. It takes away " << (thisItem.damage + damage) << " hp from the " << thisCreature->name;
		std::cout << ". Leaving the " << thisCreature->name << " with " << thisCreature->hp << " hp." << std::endl;
	}

	else if (dmg == 2) {
		thisCreature->hp = thisCreature->hp - (thisItem.damage + damage) / 2;
		std::cout << "You hit the " << thisCreature->name << " with the " << thisItem.name << " and land a glancing blow. It takes away " << (thisItem.damage + damage) / 2 << " hp from the " << thisCreature->name;
		std::cout << ". Leaving the " << thisCreature->name << " with " << thisCreature->hp << " hp." << std::endl;
	}

	else if (dmg == 1) {
		std::cout << "The " << thisCreature->name << " dodges your attack" << std::endl;
		std::cout << thisCreature->name << "'s Current HP " << thisCreature->hp << std::endl;
	}

	else {
		std::cout << "The " << thisCreature->name << " attacks first and hits you for " << thisCreature->damage << " hp" << std::endl;
		hp -= thisCreature->damage;
		std::cout << "Your current HP:" << hp << std::endl;
	}

	// check to see if the creature is dead
	if (thisCreature->hp <= 0) {
		std::cout << "The " << thisCreature->name << " is dead" << std::endl;
		return true;
	}

	if (hp <= 0) {
		std::cout << "You have died!" << std::endl;
		system("pause");
		exit(EXIT_SUCCESS);
		return true;
	}
	// Make it so person can die later

}
