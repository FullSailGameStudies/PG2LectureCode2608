#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>

//a recursive method is a method that calls itself!
//all recursive methods require 2 things:
//1) a recursive case (it must call itself)
//2) an exit condition (a base case)
void OtherMethod(int someNumber)
{	
	if (someNumber >= 1000) return;//an exit condition
	
	//do some work
	std::cout << someNumber << "\n";
	OtherMethod(someNumber + 1);//recursive case (when the method calls itself)
	
	Console::WriteLine(someNumber, (ConsoleColor)(rand() % ConsoleColor::White));
}

enum class MenuSection
{
	Appetizers,
	Entrees, 
	Desserts
};

int main(int argc, char* args[])
{
	srand(static_cast<unsigned int>(time(NULL)));

	//grouping of our menu items
	//apps, entrees, desserts
	std::map<MenuSection, std::vector<std::string> > menuItems;

	//adding items to maps
	//1) easy way
	//	map[key] = value;
	menuItems[MenuSection::Appetizers] =
	{   "Cheese sticks", 
		"Onion rings", 
		"chips & quac" };
	menuItems[MenuSection::Appetizers] =
	{   "Dino Nuggs",
		"Bloomin' onion" };//overwrite

	//2) not-as-easy way
	//  map.insert(keyValuePair);
	auto kvp = std::make_pair(MenuSection::Desserts,
		std::vector<std::string>{
			"Lava Cake", "Key Lime Pie", "Monster cookie"
		});
	menuItems.insert(kvp);
	kvp = std::make_pair(MenuSection::Desserts,
		std::vector<std::string>{
		"Lava Cake", "Key Lime Pie", "Carrot Cake"
	});
	auto addedItem =  menuItems.insert(kvp);//will NOT overwrite
	//pair objects have 2 parts:
	//	.first
	//	.second
	//addedItem.first is the iterator to the key-value pair in the map
	//addedItem.second is a bool saying if it was actually inserted
	if (addedItem.second == false)
	{
		std::cout << "Desserts is already defined. Do you want to change it?\n";
	}

	//access a value in the map
	//map[key]
	auto items = menuItems[MenuSection::Appetizers];
	std::cout << "There are " << items.size() << "apps on the menu.\n";

	//nothing? blow up?
	//it will add a new key-value pair if the key is not there!!
	//items = menuItems[MenuSection::Entrees];
	//std::cout << "There are " << items.size() << "entrees on the menu.\n";

	//map.find(key) - try to lookup the key
	//it returns an iterator
	//if the key is found, an iterator to the key-value pair in the map
	//if the kye is NOT found, the 
	auto foundSection = menuItems.find(MenuSection::Appetizers);
	if (foundSection == menuItems.end()) //means not found
	{
		std::cout << "There are no Appetizers on the menu.\n";
	}
	else
	{
		//how to access the key and value using the iterator
		//iterator->first (key)
		//iterator->second (value)
		auto entreeVec = foundSection->second;
		int numberOfEntrees = entreeVec.size();
		std::cout << "There are " << foundSection->second.size() << "entrees on the menu.\n";

		//IF you have the iterator, use the iterator to erase
		//it's slightly faster
		menuItems.erase(foundSection);//using the iterator
		//OR...
		menuItems.erase(MenuSection::Appetizers);//using the key
	}

	//looping over the map
	for (auto it = menuItems.begin(); it != menuItems.end(); it++)
	{
		switch (it->first)
		{
		case MenuSection::Appetizers:
			std::cout << "\nAppetizers:\n";
			break;
		case MenuSection::Desserts:
			std::cout << "\nDesserts:\n";
			break;
		case MenuSection::Entrees:
			std::cout << "\nEntrees:\n";
			break;
		default:
			break;
		}
		for (int i = 0; i < it->second.size(); i++)
		{
			std::cout << "\t" << it->second[i] << "\n";
		}
	}
	//range-based for (foreach)
	std::cout << "\n\nrange-based for:\n";
	for (auto& kvp : menuItems)
	{
		switch (kvp.first)
		{
		case MenuSection::Appetizers:
			std::cout << "\nAppetizers:\n";
			break;
		case MenuSection::Desserts:
			std::cout << "\nDesserts:\n";
			break;
		case MenuSection::Entrees:
			std::cout << "\nEntrees:\n";
			break;
		default:
			break;
		}
		for (int i = 0; i < kvp.second.size(); i++)
		{
			std::cout << "\t" << kvp.second[i] << "\n";
		}
	}
	//use structured bindings to make the code more readable
	std::cout << "\n\nStructured Bindings:\n";
	for (auto& [sectionName,sectionVector] : menuItems)
	{
		switch (sectionName)
		{
		case MenuSection::Appetizers:
			std::cout << "\nAppetizers:\n";
			break;
		case MenuSection::Desserts:
			std::cout << "\nDesserts:\n";
			break;
		case MenuSection::Entrees:
			std::cout << "\nEntrees:\n";
			break;
		default:
			break;
		}
		for (int i = 0; i < sectionVector.size(); i++)
		{
			std::cout << "\t" << sectionVector[i] << "\n";
		}
	}

	//OtherMethod(5);

	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}