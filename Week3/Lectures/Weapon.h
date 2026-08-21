#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	//constructor
	//order of ctor calls:
	// base then derived
	Weapon(int range, int damage);

	//destructor
	// order of destructor calls:
	//   derived then base
	// can only have 1 destructor
	// cannot have parameters
	// 
	//a couple of uses when they are needed:
	//1) when your class has internal dynamic memory (heap)
	//2) when your class is used polymorphically
	//		your need a virtual destructor
	virtual ~Weapon()
	{
		//free up any dynamic memory
	}


	//Runtime polymorph:
	//Overriding - step 1: mark the base method as 'virtual'
	//  do NOT mark all base methods as virtual.
	//  ONLY mark the ones that need to be virtual
	virtual void showMe();

	//to make Weapon an Abstract Base Class (ABC)
	//I need make at least 1 method a 'pure virtual function'
	// - add virtual
	// - add '= 0' before the ';'
	//this forces derived classes to override this function
	// ** if they do not, they will be abstract too
	virtual int calcDamage() = 0;

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

