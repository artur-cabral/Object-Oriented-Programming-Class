#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Card.h"
#include "Player.h"
#include "Dealer.h"



int main() {
	std::cout << "                 PLAY 5 STUDish\n" << std::endl;
	//Ask how many people are playing
	int players;
	std::string playerName;
	std::cout << "How many players are playing? " << std::endl;
	std::cin >> players;
	//Create players & put them all in a vector allplayers
	std::vector<Player> allplayers;
	for (int i = 0; i < players; i++) {
		std::cout << "Player "<< i << " name: ";
		std::cin >> playerName;
		Player player(playerName, i);
		allplayers.push_back(player);
	}
	std::cout << std::endl;
	//Initialize the deck and shuffle it
	std::vector<Card>deck;
	//create dealer to shuffle deck
	Dealer House;
	House.shuffleDeck();
	//Deal  cards to each player (a card at a time to each player)
	for(int i=0;i<5;i++)
		for (auto dealItr = allplayers.begin(); dealItr < allplayers.end(); dealItr++) {
			dealItr->getCard(House.dealACard());
		}
	//Players sort their hands
	for (auto sortItr = allplayers.begin(); sortItr < allplayers.end(); sortItr++)
		sortItr->sortCards();
	//print all players with sorted cards
	for (auto pitr = allplayers.begin(); pitr < allplayers.end(); pitr++) {
		std::cout << pitr->getName() << "'s Cards: ";
		for (auto hitr = pitr->hand.begin(); hitr < pitr->hand.end(); hitr++) {
			std::cout<<hitr->printCard()<<"  ";
		}
		std::cout << std::endl;
		
	}
	std::cout << std::endl;
	//Dealer deternines which one is the winner
	//Print who's the winner
	std::cout << "The winner is " << allplayers.at(House.determineWinner(allplayers)).getName() << " with a " << House.winHand(allplayers) <<std::endl;

	system("pause");
	return(0);
}