#pragma once
#include <string>
class Card
{
public:

	Card(const std::string& face, const std::string& suit)
		: face_(face), suit_(suit)
	{}

	virtual int Value() const;
	void Print() const;

	const std::string& Face() const { return face_; }
	const std::string& Suit() const { return suit_; }

	void Face(const std::string& face)
	{
		if (
			face == "A" or
			face == "2" or
			face == "3" or
			face == "4" or
			face == "5" or
			face == "6" or
			face == "7" or
			face == "8" or
			face == "9" or
			face == "10" or
			face == "J" or
			face == "Q" or
			face == "K"
			)
		{
			face_ = face;
		}

	}
	void Suit(const std::string& suit)
	{
		if (suit == "Hearts" or suit == "Clubs" or suit == "Diamonds" or suit == "Spades")
			suit_ = suit;
	}


protected:
	std::string face_, suit_;


};

