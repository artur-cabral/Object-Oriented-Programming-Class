/*Authors:	 Artur Cabral, Katelyn chambers, Temaris Dixon, Van Seiler, Scott Burnley, Dakota Purvis, Emily'Rose Shepard, Edward Leitgeb
Professor: Paul Dostert
Summary: The final project is a group project that combines all learned knowledge from the CS-210 class using object oriented classes, algorithms, STL.
gameInterface.h is the header file for gameInterface.cpp which defines all functions for the Interface class and comments what each function does
*/
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Player.h"
#include "Rooms.h"


//--------------------------------------------------------------------------------------------------------------------------------------
/*

,--.          ,--.                 ,---.                          ,-----.,--.
|  |,--,--, ,-'  '-. ,---. ,--.--./  .-' ,--,--. ,---. ,---.     '  .--./|  | ,--,--. ,---.  ,---.
|  ||      \'-.  .-'| .-. :|  .--'|  `-,' ,-.  || .--'| .-. :    |  |    |  |' ,-.  |(  .-' (  .-'
|  ||  ||  |  |  |  \   --.|  |   |  .-'\ '-'  |\ `--.\   --.    '  '--'\|  |\ '-'  |.-'  `).-'  `)
`--'`--''--'  `--'   `----'`--'   `--'   `--`--' `---' `----'     `-----'`--' `--`--'`----' `----'

*/
//--------------------------------------------------------------------------------------------------------------------------------------

class Interface {

public:
	Interface(Player *myPlayer); //pass in player
	~Interface();
	void sortInput(std::string command, Rooms *thisRoom);//basic function to gather inputs from user, for which room their in
	void displayInventory();	//Player will input command (I) to view the current inventory they have
	void displayHelp();	//Displays help commands 
	void goThere(int I, int J);	//Function to move the player based on what coordinates are passed in

private:
	Player *thePlayer;	//Players name cannot be changed TF it's private

};