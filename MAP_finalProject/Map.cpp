#include <iostream>
#include <vector>
#include <string>
#include "Map.h"
#include "Rooms.h"

//-----------Map.cpp-----------
//
//Author: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
// Map.cpp lists all functions for the Map class defining what they'll do and commenting out what each function does
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

//--------CONSTRUCTOR----------------------------------
Map::Map(int N) {
	//Make n x n map according to player input
	std::vector<Rooms> temp;
	mapSize = N;
	//generate a random room type for each spot on the map

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			//int roomType = rand() % 8;
			//Define exits
			std::vector<bool>exit{ true,true,true,true };	//Determines whether or not the player can go that way. I.E North, south, east, west
			if (i == N - 1)
				exit[0] = false;
			else if (i == 0)
				exit[1] = false;
			if (j == N - 1)
				exit[2] = false;
			else if (j == 0)
				exit[3] = false;
			temp.push_back(Rooms(exit, "nothing", "no enemy"));	//Tells if there is any enemy inside the room
			exit.clear();
		}
		map.push_back(temp);
		temp.clear();
	}

}

//-----MAP CONSTRUCTOR 2--------------------------------
Map::Map(int N, std::string description) {
	//Make n x n map according to player input
	std::vector<Rooms> temp;
	mapSize = N;
	//add all descriptions to room sections and its items and creatures
	// [ Forest     |    Swamp  ]
	// [ Mountains  |    Castle ]
	addDescriptions();
	addMapCreatures();
	addMapItems();

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			//int roomType = rand() % 8;
			//Define exits
			std::vector<bool>exit{ true,true,true,true };
			if (i == N - 1)
				exit[0] = false;
			else if (i == 0)
				exit[1] = false;
			if (j == N - 1)
				exit[2] = false;
			else if (j == 0)
				exit[3] = false;
			//temp.push_back(Rooms(exit, "nothing", "no enemy"));

			// [ Forest     |    Swamp  ]
			// [ Mountains  |    Castle ]

			if (i >= 0 && i < N / 2 && j >= 0 && j < N / 2) {//define the room as mountains
															 //	std::cout << "Moutains" << std::endl;
				description = mountains[rand() % mountains.size()];//randomly choose a description for swamp room

			}
			else if (i >= 0 && i < N / 2 && j >= N / 2 && j < N) {//define the room as forest
																  //	std::cout << "Forest" << std::endl;
				description = forest[rand() % forest.size()];//randomly choose a description to a forest room
			}
			else if (i >= N / 2 && i < N && j >= N / 2 && j < N) {//define the room as swamp
																  //	std::cout << "Swamp" << std::endl;
				description = swamp[rand() % swamp.size()];//randomly choose a description for swamp room

			}
			else if (i >= N / 2 && i < N && j >= 0 && j < N / 2) {//define the room as castle
																  //	std::cout << "Castle" << std::endl;
				description = castle[rand() % castle.size()];//randomly choose a description for a castle room
			}
			Rooms myTempRoom(description, exit);
			//temp.push_back(Rooms);
			if ((rand() % N / 4) % 5 == 0)
				myTempRoom.addCreature(mapCreatures.at(rand() % mapCreatures.size()));
			if ((rand() % N / 4) % 3 == 0)
				myTempRoom.addItem(mapItems.at(rand() % mapItems.size()));
			temp.push_back(myTempRoom);
			exit.clear();
		}
		map.push_back(temp);
		temp.clear();
	}
}
//--------DESTRUCTOR-----------------------------------
Map::~Map() {};

//-------- WINNING PATH ---------------------------------------------
bool Map::winPath() {	//Randomly sets a path that the player embarks on to win. I.E. go north 3 east 1, west 5, north 2, the player has won.
						//Need a fixed starting room: map[3][0]

						//need a while loop with an set algorithm to define how many rooms
						//we need to go through before winning the game, keep track of the 
						//rooms visited, and establish the required rooms and required items to 
						//win the game
	int counter = 0;
	int i = 3, j = 0, I, J;
	int roomWithWinningItem = rand() % (mapSize*mapSize / 3);
	for (int k = 0; k<1000; k++) {

		//set up the moves directions
		int randDir = rand() % 4;

		//this move goes north
		if (randDir == 0) {
			J = j + 1;
			I = i;
		}
		//this move goes south
		else if (randDir == 1) {
			J = j - 1;
			I = i;
		}
		//this move goes east
		else if (randDir == 2) {
			J = j;
			I = i + 1;
		}
		//this move goes west
		else {
			J = j;
			I = i - 1;
		}
		//check to see if move isn't outside the map
		//check to see if move isn't already on winPath
		if (I >= 0 && I < mapSize && J >= 0 && J < mapSize) {
			if (map[I][J].onWinningPath == false) {
				map[I][J].onWinningPath = true;
				i = I;
				j = J;
				counter++;
				if (counter == roomWithWinningItem) {
					for (auto itmItr = mapItems.begin(); itmItr < mapItems.end(); ++itmItr)
						if (itmItr->qs) {
							map[I][J].addItem(*itmItr);
							//				std::cout << "The divine rapier is on coordinates: " << I << " , " << J << std::endl;

						}
				}
			}

		}


		if (counter == mapSize*mapSize / 3) {
			// Scan through all creatures. Add the one with creature.qs = true;
			for (auto itmItr = mapCreatures.begin(); itmItr < mapCreatures.end(); ++itmItr)
				if (itmItr->qs)
					map[I][J].addCreature(*itmItr);
			//std::cout << "The winning room has coordinates " << I << " , " << J << " ; " << std::endl;

			return(true);
		}


	}//end of for loop
	 //this case is if the winPath ends up to be in a a corner and the
	 //path can't go in any of the four directions, say we start at:
	 //(3,0), then go to (3,1) (2,1) (1,1) (0,1) (0,0) (1,0) (2,0) and you're stuck
	 //If that happens, call resetBoard function, and then call winPath again
	resetMap();
	return(false);
}//end of winPath

 //------------ RESET MAP -----------------------------------------
 //this function is called when the winPath gets stuck and needs to
 //be reseted to a new initial spot so the winPath can be completed
void Map::resetMap() {
	//reset the variable onWinningPath to false for all rooms
	for (auto outItr = map.begin(); outItr < map.end(); outItr++)
		for (auto inItr = outItr->begin(); inItr < outItr->end(); inItr++)
			inItr->onWinningPath = false;
}

//------------ EDIT EXITS ---------------------------------------
//this function edits the exits of the rooms that are not in the winning path,
//so it makes a little more complicated for the player to get to 
//the winning room
void Map::editExits() {
	for (auto outItr = map.begin(); outItr < map.end(); outItr++)
		for (auto inItr = outItr->begin(); inItr < outItr->end(); inItr++) {
			if (inItr->onWinningPath == false) {
				inItr->exits[rand() % 4] = false;
				//for (int i = 0; i < 4; i++)
				//if (inItr->exits[i])
				//std::cout << inItr->directions[i] << std::endl;

			}//first if statement
		}//inItr
}//end of editExits

 //------------ADD MAP ITEMS--------------------------------------------------
 //this function just push_back items to the map items vector
void Map::addMapItems() {
	mapItems.push_back(Item("sword", 0, 7));
	mapItems.push_back(Item("shield", 5, 0));
	mapItems.push_back(Item("mace", 0, 10));
	mapItems.push_back(Item("pike", 0, 8));
	mapItems.push_back(Item("broad sword", 0, 11));
	mapItems.push_back(Item("falchion", 0, 8));
	mapItems.push_back(Item("rapier", 0, 4));
	mapItems.push_back(Item("battle axe", 0, 9));
	mapItems.push_back(Item("flail", 0, 7));
	mapItems.push_back(Item("morning star", 0, 8));
	mapItems.push_back(Item("war hammer", 0, 10));
	mapItems.push_back(Item("quarterstaff", 0, 6));
	mapItems.push_back(Item("glaive", 0, 8));
	mapItems.push_back(Item("halberd", 0, 6));
	mapItems.push_back(Item("lance", 0, 4));
	mapItems.push_back(Item("war-scythe", 0, 11));
	mapItems.push_back(Item("longbow", 0, 14));
	mapItems.push_back(Item("cross bow", 0, 16));
	mapItems.push_back(Item("dagger", 0, 3));
	mapItems.push_back(Item("spear", 0, 4));
	mapItems.push_back(Item("culverin", 0, 7));
	mapItems.push_back(Item("mancatcher", 0, 8));
	mapItems.push_back(Item("lantern shield", 5, 9));
	mapItems.push_back(Item("bludgeon", 0, 10));
	mapItems.push_back(Item("military fork", 0, 7));
	mapItems.push_back(Item("chakram", 0, 6));
	mapItems.push_back(Item("katana", 0, 11));
	mapItems.push_back(Item("chest plate", 10, 0));
	mapItems.push_back(Item("helmet", 5, 0));
	mapItems.push_back(Item("gauntlets", 5, 0));
	mapItems.push_back(Item("faulds", 5, 0));
	Item myWinningItem("divine rapier", 0, 15);
	myWinningItem.qs = true;
	mapItems.push_back(myWinningItem);
}
//------------ADD MAP ENEMIES------------------------------------------------
//this function just push_back 
//Adds the enemies to the rooms at the coordinates indicated below
void Map::addMapCreatures() {
	mapCreatures.push_back(Creature("troll", 15, 5));
	mapCreatures.push_back(Creature("golem", 25, 5));
	mapCreatures.push_back(Creature("warlock", 10, 10));
	mapCreatures.push_back(Creature("spectre", 5, 3));
	mapCreatures.push_back(Creature("troll", 15, 5));
	mapCreatures.push_back(Creature("wyvern", 20, 20));
	mapCreatures.push_back(Creature("giant", 30, 10));
	mapCreatures.push_back(Creature("goul", 10, 5));
	mapCreatures.push_back(Creature("dragon", 30, 10));
	mapCreatures.push_back(Creature("ogre", 10, 10));
	mapCreatures.push_back(Creature("orc", 10, 10));
	mapCreatures.push_back(Creature("basilisk", 10, 10));
	mapCreatures.push_back(Creature("centaur", 10, 10));
	mapCreatures.push_back(Creature("treant", 10, 10));
	mapCreatures.push_back(Creature("gargoyle", 10, 10));
	mapCreatures.push_back(Creature("skeleton", 10, 10));
	mapCreatures.push_back(Creature("werewolf ", 10, 10));
	mapCreatures.push_back(Creature("vampire", 10, 10));
	mapCreatures.push_back(Creature("gorgon", 10, 10));
	mapCreatures.push_back(Creature("lich", 10, 10));
	mapCreatures.push_back(Creature("alligator", 10, 10));
	mapCreatures.push_back(Creature("rat", 5, 3));
	mapCreatures.push_back(Creature("archer", 15, 5));
	mapCreatures.push_back(Creature("knight", 20, 20));
	Creature myWinningCreature("roshan", 50, 15);
	myWinningCreature.qs = true;
	mapCreatures.push_back(myWinningCreature);
}
//------------ADD DESCRIPTIONS----------------------------------------
void Map::addDescriptions() {
	//this function just pushes back all the individual descriptions of the determined rooms on map
	//add descriptions to castle area
	castle.push_back("You are in the North Bailey. This is an open space surrounded by walls.");
	castle.push_back("You are in the South Bailey. This is an open space surrounded by walls.");
	castle.push_back("You are in the East Bailey. This is an open space surrounded by walls.");
	castle.push_back("You are in the West Bailey. This is an open space surrounded by walls.");
	castle.push_back("You are in the Barbican. A stone structure that protects the gate of the castle.");
	castle.push_back("You are in the Barmkin. A yard surrounded by the defensive walls of the castle.");
	castle.push_back("You are in the North Bastion. A tower on the North side of the castle.");
	castle.push_back("You are in the South Bastion. A tower on the South side of the castle.");
	castle.push_back("You are in the East Bastion. A tower on the East side of the castle.");
	castle.push_back("You are in the West Bastion. A tower on the West side of the castle.");
	castle.push_back("You are in the Courtyard of the castle. An open area with the curtain walls of a castle.");
	castle.push_back("You are outside of the castle in the Drawbridge. This was a wooden bridge in front of the main gate of the castle.");
	castle.push_back("You were trapped inside the Dungeon. A deep dark cell underground and underneath the castle.");
	castle.push_back("You are up in the Donjon. The great tower of the castle.");
	castle.push_back("You are inside the Gate House. A strongly built and fortified main entrance of the castle. It often has a guard house and or living quarters.");
	castle.push_back("You are in a Hoarding. A covered wooden gallery above the tower.");
	castle.push_back("You are inside the King's Room. Be careful what you do around here.");
	castle.push_back("You entered the Royal Dinning Room, but there is no food here.");
	castle.push_back("You are in the barn. The horses are protected, and it does not smell good here!");
	castle.push_back("You just jumped into the Moat. The body of water surrounding the outer wall of a castle. So you better know how to swim!");
	castle.push_back("You are in the living area of the castle. Try to not break anything, everything here is very expensive!");
	castle.push_back("You are in one of the rooms inside teh castle.");
	//add descriptions to swamp vector
	swamp.push_back("You are in a swamp. On all sides there is water");
	swamp.push_back("You are in a clearing in a swamp.");
	swamp.push_back("You are in a swamp amid a thicket.");
	swamp.push_back("You are in a clearing in a swamp.");
	swamp.push_back("You're in a swamp with amidst mud and trees.");
	swamp.push_back("You are in a clearing. A voodoo doll is in a tree.");
	swamp.push_back("You are surrounded by 10ft grass and marsh in all directions.");
	swamp.push_back("There is a fire coming from the swamp ahead.");
	swamp.push_back("You are in a swamp above you thousands of birds fly high heading north.");
	swamp.push_back("You see dry land in the distance and a mountain.");
	swamp.push_back("You are in a swamp your hear a deer in the distance.");
	swamp.push_back("You are in a depressing tropical swamp.");
	swamp.push_back("You are in a smelly swamp.");
	swamp.push_back("You are in a mushy cold swamp.");
	swamp.push_back("You are in a swamp. Nearby you hear a bird.");
	swamp.push_back("You are in a swamp. You here a scream in the distance.");
	swamp.push_back("Swamp gas has caused you to hallucinate you think you are a medieval Knight.");
	swamp.push_back("You are in the North end of the swamp. It is really foggy here.");
	swamp.push_back("You are in the South end of the swamp. You can see an Ogre house far away.");
	swamp.push_back("You are in the East end of the swamp. There is nothing here but mud.");
	swamp.push_back("You are in the West end of the swamp. There are a lot of insects here.");
	//add florest descriptions to vector
	forest.push_back("You are surrounded by trees on all sides. There is a pile of wood on the ground.");
	forest.push_back("You are in the forest. there is a puddle of water on the ground.");
	forest.push_back("You hear a tree fall in the forest. You have fallen trees all around you.");
	forest.push_back("You see smoke coming from over the trees and a deer is standing in the east.");
	forest.push_back("You are in a clearing in the forest.");
	forest.push_back("You have come across a recently burnt down cabin.");
	forest.push_back("You are in a clearing in the forest and find a burning wagon.");
	forest.push_back("You see a large boulder in the forest covered by birds.");
	forest.push_back("You are surrounded by trees.");
	forest.push_back("You are in a forest. You hear bees buzzing in the distance.");
	forest.push_back("You are in the forest there is a cabin nearby.");
	forest.push_back("You are in the forest surrounded by trees.");
	forest.push_back("You are in a forest amidst large piles of leaves.");
	forest.push_back("You are in the forest there is a small stream of water coming from the ground.");
	forest.push_back("You've entered a circular clearing you see a large voodoo doll in the center.");
	forest.push_back("You are in the forest with trees and barbed plants all around.");
	forest.push_back("You are in the North end of the forest. It is raining a lot.");
	forest.push_back("You are in the South end of the forest. You can see an Lumber Jack house far away.");
	forest.push_back("You are in the East end of the forest. When you walked in, a few birds flew away.");
	forest.push_back("You are in the West end of the forest. There are a lot of bugs here.");
	//add the descriptions of mountains to mountains vector
	mountains.push_back("You have entered a troll's den which is hollowed out of the side of the mountain");
	mountains.push_back("You are on the North edge of a mountain.");
	mountains.push_back("You are on the South edge of a mountain.");
	mountains.push_back("You are on the East edge of a mountain.");
	mountains.push_back("You are on the West edge of a mountain.");
	mountains.push_back("You walk into a dark cave made from mountain corrosion.");
	mountains.push_back("You are on the snowy peak of a mountain.");
	mountains.push_back("You are on a steep ledge of a mountain and can see where previous rocks have fallen all around you.");
	mountains.push_back("You are surrounded by alpine trees near the top of a mountain.");
	mountains.push_back("You have enterd a tent pitched on a ledge of a mountain with a firepit burning outside.");
	mountains.push_back("You are at the base of a mountain surrounded by rolling hills and you can see the peak of the mountain in the distance.");
	mountains.push_back("You are alongside a stream flowing from the peak of the mountain due to melting snow.");
	mountains.push_back("You are at the bottom of a mountain. It seems like you can see some forest in a far land.");
	mountains.push_back("You are at the bottom of a mountain. It is very humid here, there might be a river nearby.");
	mountains.push_back("You are surrounded by rocks, and you can hear a bear growling from distance. Be careful!");
	mountains.push_back("You are on the peak of the mountain. From here you can see a forest, a castle and a swamp.");
	mountains.push_back("It is getting cold here, you might be close to the snowy peak of the montain.");
	mountains.push_back("You are at the top of the mountain. You can see a house from here, it might belong to a Lumber Jack.");
	mountains.push_back("You got trapped between two giant rocks. Find a way out.");

}
