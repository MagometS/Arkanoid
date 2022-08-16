#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "ScreenConst.h"
#include "Platform.h"
#include "Ball.h"
#include "Block.h"
#include "Player.h"
#include "ScoreBoard.h"

class Game
{
public:


	Game();


	bool Init();


	void LoadLevel_1();


	void Loop();


	void OnRender();


	void Quit();

private:


	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	bool quit = false;
	SDL_Event e;
	Platform platform;
	Ball ball;
	std::vector<Obstacle*>obstacles;
	Player player;
	///std::vector<Block> blocks;
	Block blocks[18];
	ScoreBoard scoreBoard;


};
#endif