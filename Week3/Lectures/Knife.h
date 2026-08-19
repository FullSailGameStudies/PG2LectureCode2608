#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:

	Knife(float sharpness, bool serrated, int range, int damage) : 
		Weapon(range,damage),
		mSharpness(sharpness), 
		mSerrated(serrated)
	{}

	void showMe() override;

	float Sharpness() const { return mSharpness; }
	bool Serrated() const { return mSerrated; }

	void Sharpness(float sharpness)
	{
		if (sharpness >= 0.0f && sharpness <= 1.0f)
		{
			mSharpness = sharpness;
		}
	}
	void Serrated(bool serrated)
	{
		mSerrated = serrated;
	}

private:
	float mSharpness;
	bool mSerrated;
};

