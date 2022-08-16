#define _CRT_SECURE_NO_WARNINGS //нужно для перевода победных очков в строку
#include "ScoreBoard.h"


ScoreBoard::ScoreBoard()
{
	text = TTF_OpenFont("BAUHS93.ttf", 21);
}


void ScoreBoard::Render(SDL_Renderer* gRenderer, Player player)
{
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	sprintf(str, "Score %i    Health %i", player.GetScore(), player.GetHealth());

	surfaceMessage = TTF_RenderText_Solid(text, str, { 255, 255, 255 });
	Message = SDL_CreateTextureFromSurface(gRenderer, surfaceMessage);

	SDL_RenderCopy(gRenderer, Message, NULL, &Message_rect);
}


void ScoreBoard::Close()
{
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	text = NULL;
}