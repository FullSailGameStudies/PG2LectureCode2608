#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include <Player.h>
#include "Color.h"
#include <Pistol.h>
#include <Knife.h>

//overloading:
//  2 functions have the same name
//  IF:
//		- the number of parameters are different
//		- the types of the parameters are different
int Add(int n1, int n2) { return n1 + n2; }
float Add(float n1, float n2) { return n1 + n2; }
int Add(int n1, int n2, int n3) { return n1 + n2 + n3; }


void Counter()
{
	static int i = 0;
	std::cout << i << " ";
	i++;
}

int main(int argc, char* args[])
{
	//3 sections of memory for your variables:
	// stack - removed when they go out of scope
	// heap - you MUST remove them when you are done with them
	// static
	// 
	//local variables in a function are stack variables

	{
		int g = 10, k = 11;
		int* gPtr = &g;//& means address-of
		gPtr = &k;//gPtr can point to any int
		//to "dereference" a pointer
		//means to get the value it points to
		std::cout << gPtr << "\t" << *gPtr << "\n";

		int& gRef = g;//gRef always refers to g
		gRef++;//updates g
	}

	//heap allocation (setting aside memory to be used for an object)
	//

	Weapon* currentWeapon = nullptr;
	{ //create a local scope
		Pistol* pGun;
		pGun = new Pistol(10, 5, 200, 50);//creates an object on the heap

		//copies the memory address stored in pGun
		// to currentWeapon
		//currentWeapon = pGun;

		//when we're done with the heap memory, we MUST delete it
		//memory leaks if your don't delete
		delete pGun;//calls the destructor

		//modern C++ uses smart pointers
		//shared_ptr unique_ptr

	}
	//read access violation
	//using a pointer to an object that has been deleted
	//or you're trying to use an unitialized pointer
	//currentWeapon->calcDamage();



	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	Pistol pewpew(10, 5, 200, 50);
	Pistol p2(10, 2, 200, 50);
	Pistol p3 = pewpew + p2;

	currentWeapon = &p3;//currently pointing to a stack variable
	p3.damage();
	currentWeapon->damage();//dereference with ->
	(*currentWeapon).damage();//dereference with (*).
	currentWeapon = &pewpew;

	Knife stabby(1.0f, true, 3, 15);

	//copies the weapon parts of stabby to wpn
	//Weapon wpn = stabby;
	//UPCASTING (always safe)
	//  casting from a derived type (Knife)
	//  to a base type (Weapon)
	currentWeapon = &stabby;

	//DOWNCASTING (NOT SAFE!!!)
	//use dynamic_cast and check the result
	Pistol* currentGun = (Pistol*) currentWeapon;
	currentGun->showMe();
	std::cout << currentGun->Ammo() << "\n";

	//inventory
	std::vector<Weapon*> inventory;
	inventory.push_back(&stabby);
	inventory.push_back(&pewpew);
	std::cout << "\n\nJohn Wick's Inventory:\n";
	for (auto& wpn : inventory)
	{
		//runtime polymorphism:
		//every time the loop runs, it has to figure
		//out which showMe to call
		wpn->showMe();//compile time: which method gets called?
	}
	std::cout << "\n";

	pewpew.showMe();
	stabby.showMe();


	Add(5.0f, 2.0f);
	Add(5, 2, 10);

	Color clr;
	clr.r = 255;
	clr.g = clr.b = 0;
	clr.a = 255;

	{
		//p1 is on the stack
		Player p1("The Bat", 100);
		//p1.SetGamerTag("The Bat");
		//p1.Health(100);
		std::cout << p1.GetGamerTag() << ": " << p1.Health() << "\n";
	}//when it goes out of scope, the destructor is called


    std::string hello = "Hello Week 3!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}