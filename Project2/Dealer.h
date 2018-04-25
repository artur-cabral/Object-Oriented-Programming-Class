//-----Dealer Header----------------------------------------------------
// Author: Artur Cabral
//Summary: We need the following
//	Deck of cards - vector of Cards (Card.h)
//	Shuffle cards
//	Deal a card
//	Exchange ( take card from person and deal a new card) - not here
//	Find a winner
//
//
//----------------------------------------------------------------------
#pragma once
#include <vector>
#include <string>
#include "Card.h"
#include "Player.h"

class Dealer {
public:
	Dealer();
	~Dealer();
	void shuffleDeck();
	Card dealACard(); //Remove card from deck, and return that card
	//exchange if we want to get fancy
	double findHandValue(Player thisPlayer); // interacts with Player
	int determineWinner(std::vector<Player> allplayers); // interacts with Player
	std::string winHand(std::vector<Player> allplayers); //prints out the winning hand
private:
	std::vector<Card> deck;



};