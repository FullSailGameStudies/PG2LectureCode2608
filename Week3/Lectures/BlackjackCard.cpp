#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
	if (face_ == "A") return 1;
	else if (face_ == "J" or face_ == "Q" or face_ == "K") return 10;

	return std::stoi(face_);
}
