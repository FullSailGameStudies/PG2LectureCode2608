#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	//2 modes of overriding:
	//FULL override: 
	//  ONLY want the new behavior
	// 
	//EXTENSION override:
	//	want the base behavior PLUS additional behavior
	//  do NOT duplicate what the base method does!
	//	call it instead
	std::cout << "\nPistol: ";
	Weapon::showMe();

	std::cout << "\t Ammo: " << mAmmo << " Mag Size: " << mMagSize << "\n";

}
