//THIS FILE IS THE HEADER OF CREATURES CLASS
#pragma once
#include <string>
#include<vector>

//-----------Creatures.h-----------
//Author: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
//Creatures.h is the header file for Creatures.cpp which defines all functions for the Creature class and comments what each function does
//
//-------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------
/*

,-----.                        ,--.                                         ,--.
'  .--./,--.--. ,---.  ,--,--.,-'  '-.,--.,--.,--.--. ,---.  ,---.      ,---.|  | ,--,--. ,---.  ,---.
|  |    |  .--'| .-. :' ,-.  |'-.  .-'|  ||  ||  .--'| .-. :(  .-'     | .--'|  |' ,-.  |(  .-' (  .-'
'  '--'\|  |   \   --.\ '-'  |  |  |  '  ''  '|  |   \   --..-'  `)    \ `--.|  |\ '-'  |.-'  `).-'  `)
`-----'`--'    `----' `--`--'  `--'   `----' `--'    `----'`----'      `---'`--' `--`--'`----' `----'

*/
//--------------------------------------------------------------------------------------------------------------------------------------


class Creature {

public:
	//constructor
	Creature(std::string creatureName, int creatureHp, int creatureDamage);
	//destructor
	~Creature();

	std::string name;
	int hp;
	int damage;
	bool qs = false;

private:



	// Names attatched to stats.
	// Items they could be holding.
};


// TEST CREATURE// 	Creature Troll("Troll", 15, 5);
