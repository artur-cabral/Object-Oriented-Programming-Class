#include "Card.h"

//----------- CONTRUCTOR ---------------------------------------------
Card::Card(std::string mySuit, std::string myRank) {
	suit = mySuit;
	rank = myRank;
}

//----------- DESTRUCTOR ---------------------------------------------
Card::~Card() {}

//----------GET SUIT--------------------------------------------------
std::string Card::getSuit() { return suit; }

//---------GET RANK---------------------------------------------------
std::string Card::getRank() { return rank; }

//------------GET VALUE------------------------------------------------
int Card::getValue() {
	if (rank == "J")
		return(11);
	else if (rank == "Q")
		return(12);
	else if (rank == "K")
		return(13);
	else if (rank == "A")
		return(14);
	else {
		return(std::stoi(rank));
	}
		
	return(-1);
}

//-------PRINT CARD----------------------------------------------------
std::string Card::printCard() {
	return(getRank() + getSuit());
}