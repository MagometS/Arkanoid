#include "Block.h"

Block::Block(int x, int y)
{
	_isDestroyed = false;
	this->x = x;
	this->y = y;
	this->h = 20;
	this->w = 100;

}


Block::Block()
{
	_isDestroyed = false;
	this->x = 0;
	this->y = 0;
	this->h = 20;
	this->w = 100;
}


void Block::Render(SDL_Renderer* ren)
{
	SDL_Rect rect = { x,y,w,h };

	if (_isDestroyed)
	{
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);// закрашиваем если блок уничтожен
		SDL_RenderFillRect(ren, &rect);
		return;
	}
	SDL_SetRenderDrawColor(ren, 255, 100, 0, 0);
	SDL_RenderFillRect(ren, &rect);
}


Block::~Block() {}


void Block::OnCollision()
{
	_isDestroyed = true;
}
