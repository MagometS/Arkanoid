#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
#include "ScreenConst.h"
#include "Platform.h"
#include "Ball.h"
#include "Block.h"
#include "Player.h"

class Game
{
public:


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


};
#endif