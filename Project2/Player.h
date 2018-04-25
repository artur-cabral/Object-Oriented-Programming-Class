//---- Player Header-----------------------------------------------------
// Author: Artur Cabral
// Summary: We need the following
//	Name, number, hand, getCard from dealer
//	handValue
//
//
//-----------------------------------------------------------------------
#pragma once
#include <string>
#include "Card.h"
#include <vector>
class Player {
public:
	Player(std::string pName, int pNumber);
	~Player();
	void getCard(Card cardFromDealer);
	void sortCards();
	std::string getName();
	std::vector<Card> hand;
	std::string name;
	int number;
	//double handValue = 0;
private:
	


};
