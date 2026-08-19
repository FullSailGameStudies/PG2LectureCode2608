#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	//Runtime polymorph:
	//Overriding - step 1: mark the base method as 'virtual'
	//  do NOT mark all base methods as virtual.
	//  ONLY mark the ones that need to be virtual
	virtual void showMe();
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

