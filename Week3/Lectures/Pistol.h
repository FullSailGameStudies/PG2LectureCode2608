#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int magSize, int ammo, int range, int damage) :
		Weapon(range,damage),
		mMagSize(magSize), 
		mAmmo(ammo)
	{
	
	}


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

