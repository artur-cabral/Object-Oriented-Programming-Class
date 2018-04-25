#include "Dealer.h"
#include "Card.h"
#include "Player.h"
#include <vector>
#include<iomanip>
#include<iostream>
#include <iterator>
#include <ctime>
#include <algorithm>

//----------CONSTRUCTOR---------------------------------------------------------
Dealer::Dealer() {

	//create a vector to put all the ranks of the cards, so we can loop through later
	std::vector<std::string> ranks;
	ranks.push_back("2");
	ranks.push_back("3");
	ranks.push_back("4");
	ranks.push_back("5");
	ranks.push_back("6");
	ranks.push_back("7");
	ranks.push_back("8");
	ranks.push_back("9");
	ranks.push_back("10");
	ranks.push_back("J");
	ranks.push_back("Q");
	ranks.push_back("K");
	ranks.push_back("A");
	// same here, create a vector of the suits availabe to loop through later
	std::vector<std::string> suits;
	suits.push_back("D");
	suits.push_back("H");
	suits.push_back("C");
	suits.push_back("S");
	//Loop through 2 ... A
	for(auto rankItr = ranks.begin();rankItr<ranks.end();rankItr++)
		for (auto suitItr = suits.begin(); suitItr < suits.end(); suitItr++) { //	inside loop through D,H,C,S
			//		Make a card and push into the deck
			deck.push_back(Card(*suitItr,*rankItr));
		}
	
	

}
//------DESTRUCTOR----------------------------------------------------
Dealer::~Dealer() {

}

//--------SHUFFLE DECK---------------------------------------------------
void Dealer::shuffleDeck() {
	//Seed will be the time of the computer
	srand(unsigned(time(NULL)));
	//Throw away a random
	rand();
	//Shuffle the deck from begin to end
	std::random_shuffle(deck.begin(), deck.end());
	/*std::cout << "deck =[";
	for (auto myDeck : deck)
		std::cout << myDeck.printCard() << std::endl;
	std::cout << "]" << std::endl;*/
}

//-------DEAL A CARD-----------------------------------------------------
Card Dealer::dealACard() {
	//gets the last card of the deck
	Card myTempCard = *(deck.end()-1);
	//std::cout << myTempCard.printCard() << std::endl;
	//takes the card out of the deck, to give to a player
	deck.pop_back();
	//"puts the card on the table"for player to pick up
	return(myTempCard);
}

//-------------DETERMINE WINNER-------------------------------------------
// This function determines the winner of the game, interacting with the Player class
int Dealer::determineWinner(std::vector<Player> allplayers) {
	//create a vector to put allplayers' hand values, theWinner, and max
	int index = 0;
	double max = 0;
	std::vector<double> allHandValues;
	//loop through allplayers to find all hand values and push back to allHandValues vector
	for (auto winItr = allplayers.begin(); winItr < allplayers.end(); winItr++)
		allHandValues.push_back(findHandValue(*winItr));
	//loop through the vector of all hand values to find out the highest hand value
	for (auto winItr = allHandValues.begin(); winItr < allHandValues.end(); winItr++)
		if (*winItr > max) {
			max = *winItr;
			index = std::distance(allHandValues.begin(), winItr);
		}
	//returns the index of the winner player
	return(index);
	
}
//---------FIND HAND VALUE------------------------------------------------
double Dealer::findHandValue(Player thisPlayer) {
	bool isFlush = true;
	bool isStraight = true;
	// Find if flush
	// Take the first card, see if others have same suit
	//  if not, reject flush, if so, it is flush
	Card firstCard = *(thisPlayer.hand.begin());
	for (auto cardItr = thisPlayer.hand.begin();
		cardItr < thisPlayer.hand.end(); ++cardItr) {
		if (firstCard.getSuit() != cardItr->getSuit()) {
			isFlush = false;
		}
	}

	// Right here, if isFlush is still true, it is, in fact, a flush

	// Check to see if there is a straight. Assume
	//  the hand is sorted from lowest to highest
	// Also take care of rearranging if we have 
	//  and A and corresponding 2,3,4,5,6
	firstCard = *(thisPlayer.hand.begin());
	isStraight = true;
	int counter = 0;
	for (auto cardItr = thisPlayer.hand.begin();
		cardItr < thisPlayer.hand.end(); ++cardItr) {
		if (firstCard.getValue() + counter != cardItr->getValue()) {
			isStraight = false;
		}
		counter++;
	}
	// Special case if we have a 2,3,4,5,A
	std::vector<std::string> test{ "2","3","4","5","A" };
	bool isSpecialStraight = true;
	for (unsigned int i = 0; i < test.size(); ++i)
		if (test.at(i) != thisPlayer.hand.at(i).getRank())
			isSpecialStraight = false;
	if (isSpecialStraight)
		isStraight = true;

	//9-value of highest card (1 to 14)- Straight Flush
	if (isStraight && isFlush) {
		//std::cout << "Straight Flush" << std::endl;
		double value = 0;
		int counter = 0;
		for (auto cardItr = thisPlayer.hand.begin();
			cardItr < thisPlayer.hand.end();
			cardItr++) {
			value += cardItr->getValue() * pow(15, counter);
			counter++;
		}
		return(9000000 + value);
	}
	//8-value of a card in the four of kind- Four of a kind
	else if ((thisPlayer.hand.begin()->getRank() ==
		(thisPlayer.hand.begin() + 3)->getRank())
		||
		((thisPlayer.hand.begin() + 1)->getRank() ==
		(thisPlayer.hand.begin() + 4)->getRank())) {

		int counter = 0;
		double value = 0;
		int fourOfAKindIndex = 0;
		for (int i = 0; i < thisPlayer.hand.size() - 3; ++i)
			if ((thisPlayer.hand.at(i).getRank() == thisPlayer.hand.at(i + 1).getRank())
				&&
				(thisPlayer.hand.at(i + 1).getRank() == thisPlayer.hand.at(i + 2).getRank())
				&&
				(thisPlayer.hand.at(i + 2).getRank() == thisPlayer.hand.at(i + 3).getRank())) {
				fourOfAKindIndex = i;
				break;
			}

		// So right here, "pairIndex" and "pairIndex+1" are the two pairs.
		counter = 0;
		for (int i = 0; i < thisPlayer.hand.size(); ++i)
			if (i == fourOfAKindIndex)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 4);
			else if (i == fourOfAKindIndex + 1)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 3);
			else if (i == fourOfAKindIndex + 2)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 2);
			else if (i == fourOfAKindIndex + 3)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 1);
			else {
				value += thisPlayer.hand.at(i).getValue()*pow(15, counter);
				counter++;
			}

			return(8000000 + value);
	}
	//7- - Full House  888AA  KKK22 88AAA
	else if ((thisPlayer.hand.begin()->getRank() == (thisPlayer.hand.begin() + 1)->getRank() &&
		(thisPlayer.hand.begin() + 2)->getRank() == (thisPlayer.hand.begin() + 4)->getRank())
		||
		(thisPlayer.hand.begin()->getRank() == (thisPlayer.hand.begin() + 2)->getRank() &&
		(thisPlayer.hand.begin() + 3)->getRank() == (thisPlayer.hand.begin() + 4)->getRank())) {
		//std::cout << "Full House" << std::endl;
		int counter = 0;
		double value = 0;
		int threeOfAKindIndex = 0;
		for (int i = 0; i < thisPlayer.hand.size() - 2; ++i)
			if ((thisPlayer.hand.at(i).getRank() == thisPlayer.hand.at(i + 1).getRank())
				&&
				(thisPlayer.hand.at(i + 1).getRank() == thisPlayer.hand.at(i + 2).getRank())) {
				threeOfAKindIndex = i;
				break;
			}

		// So right here, "pairIndex" and "pairIndex+1" are the two pairs.
		counter = 0;
		for (int i = 0; i < thisPlayer.hand.size(); ++i)
			if (i == threeOfAKindIndex)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 4);
			else if (i == threeOfAKindIndex + 1)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 3);
			else if (i == threeOfAKindIndex + 2)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 2);
			else {
				value += thisPlayer.hand.at(i).getValue()*pow(15, counter);
				counter++;
			}

			return(7000000 + value);
	}
	//6-- Flush
	else if (isFlush) {
		//	std::cout << "Flush" << std::endl;
		double value = 0;
		int counter = 0;
		for (auto cardItr = thisPlayer.hand.begin();
			cardItr < thisPlayer.hand.end();
			cardItr++) {
			value += cardItr->getValue() * pow(15, counter);
			counter++;
		}

		return(6000000 + value);
	}
	//5-- Straight
	else if (isStraight) {
		//std::cout << "Straight" << std::endl;
		double value = 0;
		int counter = 0;
		for (auto cardItr = thisPlayer.hand.begin();
			cardItr < thisPlayer.hand.end();
			cardItr++) {
			value += cardItr->getValue() * pow(15, counter);
			counter++;
		}


		return(5000000 + value);
	}

	//4-- Three of a kind
	else if ((thisPlayer.hand.begin() + 2)->getRank() == (thisPlayer.hand.begin() + 4)->getRank()
		||
		thisPlayer.hand.begin()->getRank() == (thisPlayer.hand.begin() + 2)->getRank()
		||
		(thisPlayer.hand.begin() + 1)->getRank() == (thisPlayer.hand.begin() + 3)->getRank()) {
		//std::cout << "Three of a kind" << std::endl;

		//22234, 23334, 23444
		int counter = 0;
		double value = 0;
		int threeOfAKindIndex = 0;
		for (int i = 0; i < thisPlayer.hand.size() - 2; ++i)
			if ((thisPlayer.hand.at(i).getRank() == thisPlayer.hand.at(i + 1).getRank())
				&&
				(thisPlayer.hand.at(i + 1).getRank() == thisPlayer.hand.at(i + 2).getRank())) {
				threeOfAKindIndex = i;
				break;
			}

		// So right here, "pairIndex" and "pairIndex+1" are the two pairs.
		counter = 0;
		for (int i = 0; i < thisPlayer.hand.size(); ++i)
			if (i == threeOfAKindIndex)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 4);
			else if (i == threeOfAKindIndex + 1)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 3);
			else if (i == threeOfAKindIndex + 2)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 2);
			else {
				value += thisPlayer.hand.at(i).getValue()*pow(15, counter);
				counter++;
			}
			//23334
			return(4000000 + value);
	}
	//3-- Two pair
	else if ((thisPlayer.hand.begin()->getRank() == (thisPlayer.hand.begin() + 1)->getRank() &&
		(thisPlayer.hand.begin() + 2)->getRank() == (thisPlayer.hand.begin() + 3)->getRank())
		||
		(thisPlayer.hand.begin()->getRank() == (thisPlayer.hand.begin() + 1)->getRank() &&
		(thisPlayer.hand.begin() + 3)->getRank() == (thisPlayer.hand.begin() + 4)->getRank())
		||
		((thisPlayer.hand.begin() + 1)->getRank() == (thisPlayer.hand.begin() + 2)->getRank() &&
		(thisPlayer.hand.begin() + 3)->getRank() == (thisPlayer.hand.begin() + 4)->getRank())) {
		//std::cout << "Two pair" << std::endl;
		// 7788A -> A7788 * (15^0 ,...15^4)
		// 22588 -> 52288
		// Identify "high pair"


		// 1st pair we hit backwards are the "high pair" and will take the 
		//  "15^4 and 15^3" spots, next pair will take the "15^2 and 15^1"
		//  and the leftover non matched card takes the 15^0
		int counter = 4;
		double value = 0;
		int i = 4;

		// Top pair is highest cards
		if (thisPlayer.hand.at(i).getRank() == thisPlayer.hand.at(i - 1).getRank()) {
			value += thisPlayer.hand.at(i).getValue()*pow(15, 4);
			value += thisPlayer.hand.at(i - 1).getValue()*pow(15, 3);
			// Next top pair is 2nd highest cards
			if (thisPlayer.hand.at(i - 2).getRank() == thisPlayer.hand.at(i - 3).getRank()) {
				value += thisPlayer.hand.at(i - 2).getValue()*pow(15, 2);
				value += thisPlayer.hand.at(i - 3).getValue()*pow(15, 1);
				value += thisPlayer.hand.at(i - 4).getValue()*pow(15, 0);
			}
			// Next top pair is smallest two cards
			else {
				value += thisPlayer.hand.at(i - 3).getValue()*pow(15, 2);
				value += thisPlayer.hand.at(i - 4).getValue()*pow(15, 1);
				value += thisPlayer.hand.at(i - 2).getValue()*pow(15, 0);
			}

		}
		// Top pair does not contain the last card (6677A)
		else {
			value += thisPlayer.hand.at(i - 1).getValue()*pow(15, 4);
			value += thisPlayer.hand.at(i - 2).getValue()*pow(15, 3);
			value += thisPlayer.hand.at(i - 3).getValue()*pow(15, 2);
			value += thisPlayer.hand.at(i - 4).getValue()*pow(15, 1);
			value += thisPlayer.hand.at(i).getValue()*pow(15, 0);
		}


		return(3000000 + value);
	}
	//2-- One pair
	else if ((thisPlayer.hand.begin() + 0)->getRank() == (thisPlayer.hand.begin() + 1)->getRank()
		||
		(thisPlayer.hand.begin() + 1)->getRank() == (thisPlayer.hand.begin() + 2)->getRank()
		||
		(thisPlayer.hand.begin() + 2)->getRank() == (thisPlayer.hand.begin() + 3)->getRank()
		||
		(thisPlayer.hand.begin() + 3)->getRank() == (thisPlayer.hand.begin() + 4)->getRank()
		) {
		int counter = 0;
		double value = 0;
		int pairIndex = 0;
		for (int i = 0; i < thisPlayer.hand.size() - 1; ++i)
			if (thisPlayer.hand.at(i).getRank() == thisPlayer.hand.at(i + 1).getRank()) {
				pairIndex = i;
				break;
			}

		// So right here, "pairIndex" and "pairIndex+1" are the two pairs.
		counter = 0;
		for (int i = 0; i < thisPlayer.hand.size(); ++i)
			if (i == pairIndex)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 4);
			else if (i == pairIndex + 1)
				value += thisPlayer.hand.at(i).getValue()*pow(15, 3);
			else {
				value += thisPlayer.hand.at(i).getValue()*pow(15, counter);
				counter++;
			}
			//23445 [23544]
			return(2000000 + value);
	}
	//1-- High card
	else {
		//2345A
		//2345K
		//910JQA
		//1412111009
		//1312111009
		double value = 0;
		int counter = 0;
		for (auto cardItr = thisPlayer.hand.begin();
			cardItr < thisPlayer.hand.end();
			cardItr++) {
			value += cardItr->getValue() * pow(15, counter);
			counter++;
		}
		//	std::cout << std::setprecision(14) << std::fixed;
		//	std::cout << "You have value" << (int)value << std::endl;
		return(value);
	}



	return(-1);
}

//----------WIN HAND ------------------------------------------
//This function used the findHandValue function and a vector of all players to determine 
//with which hand the winner player won the game.
std::string Dealer::winHand(std::vector<Player> allplayers) {
	if (findHandValue(allplayers.at(determineWinner(allplayers))) <2000000)
		return("High Card");
	else if (findHandValue(allplayers.at(determineWinner(allplayers))) < 3000000)
		return("Pair");
	else if (findHandValue(allplayers.at(determineWinner(allplayers))) < 4000000)
		return("Two Pairs");
	else if (findHandValue(allplayers.at(determineWinner(allplayers))) < 5000000)
			return("Three of a Kind");
	else if (findHandValue(allplayers.at(determineWinner(allplayers))) < 6000000)
		return("Straight");
	else if (findHandValue(allplayers.at(determineWinner(allplayers))) < 700000)
		return("Flush");
	else if (findHandValue(allplayers.at(determineWinner(allplayers))) < 8000000)
		return("Full House");
	else if (findHandValue(allplayers.at(determineWinner(allplayers))) < 9000000)
		return("Four of a Kind");
	else { return("Straight Flush"); }


}