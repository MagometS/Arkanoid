#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL_ttf.h>

#include "ScreenConst.h"
#include "Platform.h"
#include "Ball.h"
#include "Obstacle.h"
#include "Block.h"
#include "ScoreBoard.h"
#include "Game.h"
#include "BlockBonus.h"
#include "BonusSecondBall.h"
#include "BallForBonus.h"
#include "Block_Indestructible.h"
#include "BonusMovingBlock.h"

bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures



bool init()
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


		//Create window
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

			//Initialize PNG loading

		}
		if (TTF_Init() == -1)
		{
			printf("Failed to initialize!\n");
			return 1;
		}

			
		
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	

	return success;
}

void close()
{
	//Free loaded images
	
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	//IMG_Quit();
	SDL_Quit();
	//TTF_CloseFont();
	TTF_Quit();
}

int main(int argc, char* args[])
{
	
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gRenderer);

		Player player = Player(3);
		ScoreBoard scoreBoard = ScoreBoard();
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//Dot dot;
		Platform platform = Platform(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 20 * 2);
		Ball ball = Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 55);
		std::vector<Obstacle*>obstacles;


		obstacles.push_back(&platform);

		std::vector<Bonus*> bonusesPtr;

		std::vector<Block> blocks(19);

		BallForBonus secBall;
		secBall.StartPosition();
		secBall.ChangeDirection_X();
		secBall.SetColor(255, 69, 0, 0);

		Block_Moving blockMov = Block_Moving(300, 200);

		BonusSecondBall bonus = BonusSecondBall(345, 140, &secBall);
		bonusesPtr.push_back(&bonus);

		BonusMovingBlock bonus2 = BonusMovingBlock(455, 140, &blockMov);
		bonusesPtr.push_back(&bonus2);

		BlockBonus blockBonus = BlockBonus(300, 170, &bonus);
		obstacles.push_back(&blockBonus);

		BlockBonus blockBonus2 = BlockBonus(410, 170, &bonus2);
		obstacles.push_back(&blockBonus2);


		Block_Indestructible blockIndes = Block_Indestructible(0, 140);
		obstacles.push_back(&blockIndes);

		for (int i = 0; i < 5; i++)
		{
			blocks[i] = Block(i * SCREEN_WIDTH / 5, 40);
			obstacles.push_back(&blocks[i]);
		}

		for (int i = 5; i < 10; i++)
		{
			blocks[i] = Block((i - 5) * SCREEN_WIDTH / 5, 65);

			obstacles.push_back(&blocks[i]);
		}
		for (int i = 10; i < 15; i++)
		{
			blocks[i] = Block((i - 10) * SCREEN_WIDTH / 5, 90);
			obstacles.push_back(&blocks[i]);
		}

		for (int i = 15; i < 19; i++)
		{
			blocks[i] = Block((i - 15) * SCREEN_WIDTH / 5, 115);

			obstacles.push_back(&blocks[i]);
		}

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


			platform.Move(bonusesPtr);
			//ball.Move(obstacles, player);

			SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
			SDL_RenderClear(gRenderer);

			for (int i = 0; i < bonusesPtr.size(); i++)
			{
				if (bonusesPtr[i]->isActivated())
				{
					bonusesPtr[i]->Move();
					bonusesPtr[i]->Render(gRenderer);

				}

			}

			if (secBall.isActivated())
			{
				ball.Move(obstacles, player, &secBall);
				secBall.Move(obstacles, player, &ball);
				secBall.Render(gRenderer);
			}
			else
			{
				ball.Move(obstacles, player);

			}

			if (blockMov.isActivated())
			{
				if (blockMov.isMaterial())
					obstacles.push_back(&blockMov);
				blockMov.OffIsMaterial();
			}
			blockMov.Move(obstacles);

			/*
			if (bonus.isActivated())//добавить цикл
			{
				bonus.Render(gRenderer);
			}
			*/
			//platform.Render(gRenderer);
			ball.Render(gRenderer);

			for (int i = 0; i < obstacles.size(); i++)
			{
				obstacles[i]->Render(gRenderer);
			}

			scoreBoard.Render(gRenderer, player);

			//Update screen
			SDL_RenderPresent(gRenderer);
		}

	

	}

	close();
	
	/*
	Game Game;

	if (Game.Init())
	{
		Game.LoadLevel_1();
		Game.Loop();
	}

	Game.Quit();
	*/
	return 0;
}
