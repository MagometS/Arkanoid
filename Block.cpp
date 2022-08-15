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
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(ren, &rect);
}


Block::~Block() {}


void Block::OnCollision(Player& player)
{

	player.PlusScore(1);

	_isDestroyed = true;

}
