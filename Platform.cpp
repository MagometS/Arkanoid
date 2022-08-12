#include "Platform.h"

Platform::Platform(int x, int y)
{
	position = { x,y };
	rect = { position.x,position.y,width,height };
}

void Platform::Move()
{
	position.x += velocity;

	if ((position.x < 0) || (position.x + width > SCREEN_WIDTH))
	{
		position.x -= velocity;
	}
}

void Platform::Render(SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderFillRect(ren, &rect);
	rect = { position.x,position.y,width,height };
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 0);
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