#include "Bonus.h"

Bonus::Bonus()
{
	this->x = 0;
	this->y = 0;
	this->w = 7;
	this->h = 7;

}



Bonus::Bonus(int x, int y)
{
	this->x = x;
	this->y = y;
	this->w = 7;
	this->h = 7;
}


void Bonus::Render(SDL_Renderer* ren)
{
	SDL_Rect rect = { x,y,w,h };
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(ren, &rect);
}


void Bonus::Move()
{
	y += velocity;

	if (y > SCREEN_HEIGHT)
	{
		this->Destroy();
	}
}