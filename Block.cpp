#include "Block.h"

Block::Block(int x, int y)
{
	isDestroyed = false;
	this->x = x;
	this->y = y;
	this->h = 20;
	this->w = 100;

}


void Block::Render(SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 255, 100, 0, 0);
	SDL_Rect rect = { x,y,w,h };
	SDL_RenderFillRect(ren, &rect);

	if (isDestroyed)
	{
		SDL_Rect rect = { x,y,w,h };
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);// закрашиваем если блок уничтожен
		SDL_RenderFillRect(ren, &rect);
	}
}


Block::~Block() {}


void Block::OnCollision()
{
	isDestroyed = true;
}