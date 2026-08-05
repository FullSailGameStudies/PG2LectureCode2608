#include "Day2.h"
#include <string>
#include <Console.h>
#include <Input.h>
#include "Player.h"

//
// Part B-1.1: Add a method definition for SpawnZombies
//
void Day2::SpawnZombies(PG2Graphics& engine, std::vector<Zombie>& zeeks, Player& player)
{
	int px = player.GetXPosition();
	int py = player.GetYPosition();

	int x, y;
	for (int i = 0; i < 5; i++)
	{
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (x == px and y == py);
		Zombie zeek(&engine, 0.5f, x, y);
		zeeks.push_back(zeek);
	}
}

//
// Part B-2.1: Add a method definition for RenderZombies
//
void Day2::RenderZombies(const std::vector<Zombie>& zeeks) const
{
	for (const Zombie& zeek : zeeks)
	{
		zeek.Render();
	}
}


//
// Part B-3.1: Add a method definition for EraseZombies
//
int Day2::KillZombies(std::vector<Zombie>& zeeks, const Player& player) const
{
	int counter = 0;

	int x1 = player.GetXPosition();
	int y1 = player.GetYPosition();

	int x2, y2;
	for (int i = 0; i < zeeks.size();)
	{
		//get the zombie's position
		x2 = zeeks[i].GetXPosition();
		y2 = zeeks[i].GetYPosition();

		//calculate the distance
		int distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if (distance < 4)
		{
			//erase the closer zombies
			zeeks.erase(zeeks.begin() + i);
			counter++;
		}
		else
			i++;
	}
	return counter;
}




void Day2::PartB(int option)
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		float scale = 0.25f;
		Player player(&engine, scale, 4, 4);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), player.Size());
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};
			GameObject::SetMap(map.mapData, 10, 10);

			std::vector<Zombie> mobs;
			//
			// Part B-1.3 Call SpawnZombies
			//
			SpawnZombies(engine, mobs, player);

			bool quit = false;
			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
					{
						quit = true;
					}
					else if (e.type == SDL_KEYUP && e.key.repeat == 0)
					{
						if (e.key.keysym.sym == SDLK_SPACE)
						{
							if (option == 3)
							{
								//
								// Part B-3.3 Call KillZombies
								//
								int numberOfKills = KillZombies(mobs, player);
								std::cout << "Steve killed " << numberOfKills << " zombies!\n";
							}
						}
						else if (e.key.keysym.sym == SDLK_r)
						{
							mobs.clear();
							//
							// Part B-1.3 Call SpawnZombies
							//
							SpawnZombies(engine, mobs, player);
						}
					}
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();

				//
				// Part B-2.3 call RenderZombies
				//
				RenderZombies(mobs);


				player.Render();

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}
