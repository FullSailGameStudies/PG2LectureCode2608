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

