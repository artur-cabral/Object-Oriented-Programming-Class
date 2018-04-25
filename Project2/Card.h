
//--------Card Header------------------------------------------
// Author: Artur Cabral
// Summary: The header for a class that defines a player card. Each card needs a suit
// (string: H,C,D,S) and a rank (string: 2,3,4.....,10,J,Q,K,A)
//
//--------------------------------------------------------------
#pragma once
# include <string>
class Card {
// constructor and destructor
public:
	Card(std::string mySuit, std::string myRank);
	~Card();
	std::string printCard();
	std::string getSuit();
	std::string getRank();
	int getValue();
private:
	std::string suit, rank;




};