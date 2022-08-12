#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
#include "ScreenConst.h"

class Game
{
public:
	bool Init();
	void OnEvent();
	void OnLoop();
	void OnRender();
	void Quit();

private:
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	

};
#endif