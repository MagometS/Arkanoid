#include "Game.h"

 bool Game::Init()
 {
	 //Initialization flag
	 bool success = true;

	 //Initialize SDL
	 if (SDL_Init(SDL_INIT_VIDEO) < 0)
	 {
		 printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		 success = false;
	 }
	 else
	 {

		 gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		 if (gWindow == NULL)
		 {
			 printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			 return 1;
		 }
		 gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		 if (gRenderer == NULL)
		 {
			 printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			 success = false;
		 }
		 else
		 {
			 //Initialize renderer color
			 SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		 }
	 }
	 return success;
 }

void Game::LoadLevel_1()
{

	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0); // Задаем цвет сцены и создаем объекты 
	SDL_RenderClear(gRenderer);

	platform = Platform(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 20 * 2);
	ball = Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 55);
	//std::vector<Obstacle*>obstacles;

	obstacles.push_back(&platform);

	std::vector<Block> blocks(18);
	for (int i = 0; i < 4; i++)
	{
		blocks[i] = Block(i * SCREEN_WIDTH / 4, 40);
		obstacles.push_back(&blocks[i]);
	}

	for (int i = 4; i < 9; i++)
	{
		blocks[i] = Block((i - 3) * SCREEN_WIDTH / 5, 70);

		obstacles.push_back(&blocks[i]);
	}
	for (int i = 9; i < 13; i++)
	{
		blocks[i] = Block((i - 9) * SCREEN_WIDTH / 4, 100);
		obstacles.push_back(&blocks[i]);
	}

	for (int i = 13; i < 18; i++)
	{
		blocks[i] = Block((i - 13) * SCREEN_WIDTH / 5, 130);

		obstacles.push_back(&blocks[i]);
	}
	
}


void Game::Loop()
{
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			platform.OnEvent(e);
		}

		platform.Move();
		ball.Move(obstacles, player);

		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gRenderer);

		//platform.Render(gRenderer);
		ball.Render(gRenderer);

		for (int i = 0; i < obstacles.size(); i++)
		{
			obstacles[i]->Render(gRenderer);
		}



		//Update screen
		SDL_RenderPresent(gRenderer);

	}

}

void Game::OnRender()
{

}


void Game::Quit()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();

}