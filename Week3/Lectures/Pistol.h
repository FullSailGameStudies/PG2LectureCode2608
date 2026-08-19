#pragma once
#include "Weapon.h"
#include <utility>
class Pistol : public Weapon
{
public:

	Pistol(int magSize, int ammo, int range, int damage) :
		Weapon(range,damage),
		mMagSize(magSize), 
		mAmmo(ammo)
	{
	
	}

	//operator overloading
	//p3 = pewpew + p2
	Pistol operator+(const Pistol& other)
	{
		int ammo = mAmmo + other.mAmmo;
		int magSize = std::max(mMagSize, other.mMagSize);
		Pistol gun(magSize, ammo, range(), damage());
		return gun;
	}

	//Overriding - step 2: add a new method in the derived
	//	that matches the base method declaration
	//  you don't need to keep adding 'virtual'
	//  add the new definition for showMe

	// optional: add the 'override' keyword
	void showMe() override;

	int MagSize() const { return mMagSize; }
	int Ammo() const { return mAmmo; }

	void MagSize(int magSize)
	{
		if (magSize > 0 && magSize < 15)
		{
			mMagSize = magSize;
		}
	}
	void Ammo(int ammo)
	{
		if (ammo >= 0 && ammo <= mMagSize)
			mAmmo = ammo;
	}

private:
	int mMagSize;
	int mAmmo;
};

