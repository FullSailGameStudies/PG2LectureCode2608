#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	std::cout << "\nKnife: ";
	Weapon::showMe();
	//ternary operator
	std::cout << "\tSerrated: " << (mSerrated ? "True" : "False") << " Sharpness: " << mSharpness << "\n";
}


int Knife::calcDamage()
{
	return Weapon::calcDamage();
}