#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Rooms.h"

//-----------Map.h-----------
//Authors: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
//Map.h is the header file for Map.cpp which defines all functions for the Map class and comments what each function does
//
//-------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------
/*

,--.   ,--.                         ,--.
|   `.'   | ,--,--. ,---.      ,---.|  | ,--,--. ,---.  ,---.
|  |'.'|  |' ,-.  || .-. |    | .--'|  |' ,-.  |(  .-' (  .-'
|  |   |  |\ '-'  || '-' '    \ `--.|  |\ '-'  |.-'  `).-'  `)
`--'   `--' `--`--'|  |-'      `---'`--' `--`--'`----' `----'
`--'
*/
//--------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------




class Map {
public:
	//constructor: the maps is a vector of rooms, which can vary with
	//the player difficulty input: easy(8x8),medium(10x10),hard(12x12)
	Map(int N);
	//create another constructor of maps that takes in the size to create the map 
	//divided in 4 sections
	Map(int N, std::string description);
	//destructor
	~Map();

	//mapSize according to the player input
	int mapSize;
	//2D vector of "Rooms" to create the map
	std::vector<std::vector<Rooms>> map;

	//vector of items to be put in the map
	std::vector<Item> mapItems;
	//vector of enemies to be put in the map
	std::vector<Creature> mapCreatures;
	//function to push_back items to vector mapItems
	void addMapItems();
	//function to puck_back creatures to vector mapCreatures
	void addMapCreatures();
	//function to set a winning path to the map
	bool winPath();
	//function to reset the map if the winPah gets stuck
	void resetMap();
	//function to edit the exits if it's not on winPath
	void editExits();
	//vectors that hold all descriptions for the 4 areas of the map
	std::vector<std::string> castle;
	std::vector<std::string> swamp;
	std::vector<std::string> forest;
	std::vector<std::string> mountains;
	//function push_back descriptions to all of 4 areas of the map
	void addDescriptions();
private:


};