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

int main(int argc, char* args[])
{
	Pistol pewpew(10, 5, 200, 50);
	Pistol p2(10, 2, 200, 50);
	Pistol p3 = pewpew + p2;

	Knife stabby(1.0f, true, 3, 15);

	pewpew.showMe();
	stabby.showMe();


	Add(5.0f, 2.0f);
	Add(5, 2, 10);

	Color clr;
	clr.r = 255;
	clr.g = clr.b = 0;
	clr.a = 255;

	Player p1("The Bat", 100);
	//p1.SetGamerTag("The Bat");
	//p1.Health(100);
	std::cout << p1.GetGamerTag() << ": " << p1.Health() << "\n";


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