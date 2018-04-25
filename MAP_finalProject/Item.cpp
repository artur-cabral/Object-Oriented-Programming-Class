#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

//-----------Item.cpp-----------
//Author: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
//Item.cpp lists all functions for the Item class defining what they'll do and commenting out what each function does
//-------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------
/*

,--.  ,--.                             ,--.
|  |,-'  '-. ,---. ,--,--,--.     ,---.|  | ,--,--. ,---.  ,---.
|  |'-.  .-'| .-. :|        |    | .--'|  |' ,-.  |(  .-' (  .-'
|  |  |  |  \   --.|  |  |  |    \ `--.|  |\ '-'  |.-'  `).-'  `)
`--'  `--'   `----'`--`--`--'     `---'`--' `--`--'`----' `----'

*/
//--------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------


//------------- ITEM CLASS FUNCTIONS --------------------------------------

//----------CONSTRUCTOR----------------------------
Item::Item(std::string itemName, int itemHp, int itemDamage) {
	name = itemName;
	hp = itemHp;
	damage = itemDamage;
	qs = false;
}

//-------------DESTRUCTOR-------------------------------
Item::~Item() {}
