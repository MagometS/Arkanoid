#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>

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
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;

};
#endif