#include <string>
#include <vector>
#include <iostream>
#include "Creature.h"


//-----------Creatures.cpp-----------
//Author: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
//Creatures.cpp lists all functions for the Interface class defining what they'll do and commenting out what each function does
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


//------------------------------------CREATURE CLASS FUNCTIONS------------------------------------------------
//--------CONSTRUCTOR-----------------------
Creature::Creature(std::string creatureName, int creatureHp, int creatureDamage) {

	name = creatureName;
	hp = creatureHp;
	damage = creatureDamage;
	qs = false;

}
//--------DESTRUCTOR-------------------------------
Creature::~Creature() {}



