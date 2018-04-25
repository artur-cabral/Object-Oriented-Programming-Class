#pragma once
#include <string>
#include<vector>

//-----------Item.h-----------
//Author: Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
//Professor: Paul Dostert
//Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
//Item.h is the header file for Item.cpp which defines all functions for the Item class and comments what each function does
//
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


class Item {
public:
	// same as creature but call a name based on class.
	Item(std::string name, int hp, int damage); // armor
	std::string name;
	int damage;
	int hp;
	~Item();
	bool qs = false;

private:
	// quest specific item
	//bool qs;;

};