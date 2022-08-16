#include "Game.h"

Game::Game()
{
	player = Player(3);
	//scoreBoard = ScoreBoard();
	platform = Platform(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 20 * 2);
	ball = Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 55);
}


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
		 if (TTF_Init() == -1)
		 {
			 printf("Failed to initialize!\n");
			 success = false;
		 }

	 }
	 return success;
 }

void Game::LoadLevel_1()
{

	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0); 
	SDL_RenderClear(gRenderer);

	/*
	player = Player(3);
	scoreBoard = ScoreBoard();
	platform = Platform(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 20 * 2);
	ball = Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 55);
	//std::vector<Obstacle*>obstacles;
	*/
	scoreBoard = ScoreBoard();

	obstacles.push_back(&platform);

	for (int i = 0; i < 4; i++)
	{
		blocks[i] = Block(i * SCREEN_WIDTH / 4, 40);
		//blocks.push_back(block);
		obstacles.push_back(&blocks[i]);
	}

	for (int i = 4; i < 9; i++)
	{
		blocks[i] = Block((i - 3) * SCREEN_WIDTH / 5, 70);
		//blocks.push_back(block);

		obstacles.push_back(&blocks[i]);
	}
	for (int i = 9; i < 13; i++)
	{
		blocks[i] = Block((i - 9) * SCREEN_WIDTH / 4, 100);
		//blocks.push_back(block);

		obstacles.push_back(&blocks[i]);
	}

	for (int i = 13; i < 18; i++)
	{
		blocks[i] = Block((i - 13) * SCREEN_WIDTH / 5, 130);
		//blocks.push_back(block);

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

		this->OnRender();
	}

}

void Game::OnRender()
{
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
	SDL_RenderClear(gRenderer);

	ball.Render(gRenderer);

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->Render(gRenderer);
	}

	scoreBoard.Render(gRenderer, player);

	//Update screen
	SDL_RenderPresent(gRenderer);

}


void Game::Quit()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	scoreBoard.Close();
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();


}