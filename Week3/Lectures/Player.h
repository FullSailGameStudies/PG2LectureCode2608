#pragma once
#include <string>
class Player
{
	//access modifiers:
	//  the visibility outside of the class
	//  public: everyone can see it
	//  private: *only this class can see it
	//		* - there are ways around this
	//  protected: this class and ALL descendents
	//		of this class can see it
public:

	//constructors (ctor)
	// initialize the object when it is created
	// to create an object of a class, you MUST call a ctor
	// IF you do not create your own ctor, the compiler will give you a default ctor
	//		a default ctor - no parameters
	// IF you do create a ctor, the compiler's ctor is not longer available
	// RULES:
	//	must have the same name as the class
	//	cannot have any return type (not even void)
	//	can have as many as needed and can have any access modifier

	//a default ctor
	Player(const std::string& gamerTag, int health) :
		//the preferred way: use the 'member intialization list'
		// this is where the fields are FIRST created
		// better to initialize it once
		gamerTag_(gamerTag),
		health_(health)
	{
		//ok but NOT the preferred way
		//gamerTag_ = gamerTag;
		//health = health_;
	}

	//getters/setters
	// the Gate Keepers of our data (fields)
	//they control the acces to your fields
	//they are usually defined in the header
	//
	// getters (accessors)
	// - return type matches the field type
	// - usually no parameters
	// - const b/c they do not modify the class
	// - simply return the field
	const std::string& GetGamerTag() const { return gamerTag_; }

	// setters (mutators)
	// - return type is void
	// - at least 1 parameter that matches the type of the field
	// - can't be const
	void SetGamerTag(const std::string& newGamerTag)
	{
		//here is where validate the parameter
		if (newGamerTag.size() > 0 && newGamerTag.size() <= 32)
		{
			gamerTag_ = newGamerTag;
		}
	}

	//an alternative naming for getters/setters...
	// don't use 'get' or 'set'!
	int Health() const { return health_; }
	void Health(int newHealth) {
		if (newHealth >= 0 && newHealth <= 100)
		{
			health_ = newHealth;
		}
	}

private:

	//FIELDS:
	//	keep it secret, keep it hidden
	//  do better than Frodo
	// usually make them private! to protect them
	// from outside code changing it

	//naming conventions:
	//	camelCasingNamingConvention
	// for member variables, we usually add something
	//	to make it stand out
	// m_sGamerTag, m_gamerTag mGamerTag, _gamerTag, gamerTag_
	// gamer_tag
	std::string gamerTag_;
	int health_;

};

