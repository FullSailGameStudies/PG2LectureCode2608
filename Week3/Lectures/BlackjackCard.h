#pragma once
#include "Card.h"

//in OOP terms:
// this relationship is called the 'IS-A' relationship
// EX: BlackjackCard IS-A Card
class BlackjackCard : public Card
{
public:
	//do NOT duplicate what the base ctor does
	BlackjackCard(const std::string& face, const std::string& suit)
		: Card(face,suit)
	{}

private:

};

