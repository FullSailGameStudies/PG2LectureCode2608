#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

/*
game loop(true)
{
  update(objects)
  render(objects)
}

*/
int Add(int n1, int n2)//n1 and n2 are the parameters
{
	return n1 + n2;
}
void Printer(const std::vector<int>& nummies)
{
	//range-based (foreach)
	for (const int& nummy : nummies)
	{
		std::cout << nummy;
	}
}
//WHEN to use pass by reference
//1) to prevent a copy
//	in general, if the type is a CLASS, pass by reference
//2) need to modify the variable in the other scope
void Incrementer(int& number)//pass by reference (ALIAS)
{
	number++;
}


int main(int argc, char* args[])
{
	const float PI = 3.1415f;
	//CAPTURE the return value
	//1. create a variable with the same type as the return type
	int sum;
	//2. call the function and assign it to my variable
	sum = Add(5, 2);

	int num1 = 5, num2 = 2;
	int& numRef = num1;
	numRef += 2;
	numRef = num2;//copies num2 to num1
	std::cout << num1 << "\n";
	int result = Add(num1, num2);//num1 and num2 are the 'arguments'
	Incrementer(num2);//int& number = num2
	Incrementer(num1);//int& number = num1
	Day2 day2;
	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("Hello PG2! ", ConsoleColor::Red);
			Console::WriteLine("Day01: ", ConsoleColor::Green);
			Console::WriteLine(" Intro", ConsoleColor::Yellow);
			Console::WriteLine(" Static vs non-static", ConsoleColor::Yellow);

			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			std::string name = Input::GetString("What is your name? ");
			std::cout << "You entered " << name << ".\n";
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			int age = Input::GetInteger("What is your age?", 0, 120);
			std::cout << "Your age is " << age << ". Weird!\n";
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB();
			break;
		}
		case 9:
		{
			day2.PartB(2);
			break;
		}
		case 10:
		{
			day2.PartB(3);
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

