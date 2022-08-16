#include "Platform.h"

Platform::Platform()
{
	this->x = 0;
	this->y = SCREEN_HEIGHT - w;
	this->h = 20;
	this->w = 100;

}


Platform::Platform(int x, int y)
{
	this->x = x;
	this->y = y;
	this->h = 20;
	this->w = 100;
}

void Platform::Move()
{
	x += velocity;

	if ((x < 0) || (x + w > SCREEN_WIDTH))
	{
		x -= velocity;
	}
}

void Platform::Render(SDL_Renderer* ren)
{
	/*
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderFillRect(ren, &rect);
	*/
	SDL_Rect rect = { x,y,w,h };
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(ren, &rect);

}

void Platform::OnEvent(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT: velocity -= maxVel; break;
		case SDLK_RIGHT: velocity += maxVel; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT: velocity += maxVel; break;
		case SDLK_RIGHT: velocity -= maxVel; break;
		}
	}
}