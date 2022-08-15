#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Player.h"


class ScoreBoard
{
public:

	ScoreBoard();


	void Render(SDL_Renderer* gRenderer, Player player);


	void Close();


private:


	TTF_Font* text = NULL;
	SDL_Surface* surfaceMessage = NULL;
	SDL_Texture* Message = NULL;
	SDL_Rect Message_rect = { 0, 0, 200, 40 };
	char str[200];// буфер для вывода
};
#endif

