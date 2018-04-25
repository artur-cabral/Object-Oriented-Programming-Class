#include "Player.h"
#include "Dealer.h"
#include <algorithm>


Player::Player(std::string pName, int pNumber) {
	name = pName;
	number = pNumber;
}

Player::~Player() {

}

//------GET NAME------------------------------------------------
std::string Player::getName() {
	return(name);
}

//-----SORT CARDS--------------------------------------------------
//create the sort function to be used by sortCards();
bool sorting(Card a, Card b) { return(a.getValue() < b.getValue()); }
//sortCards function-----------------
void Player::sortCards() {
	std::sort(hand.begin(), hand.end(), sorting);
}

//-------GET CARD--------------------------------------------------
void Player::getCard(Card cardFromDealer) {
	hand.push_back(cardFromDealer);
}