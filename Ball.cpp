#include "Ball.h"

Ball::Ball(int x, int y)
{
	position = { x,y };
	circle = { position.x,position.y,radius };
	velocity.y = -maxVel;
	//velocity.x = maxVel;
}


void Ball::Move(std::vector<Shape>& obstacles)
{
	isTouchedFloor = false;

	position.x += velocity.x;
	position.y += velocity.y;

	if ((position.x - radius < 0) || (position.x + radius > SCREEN_WIDTH))
	{
		position.x -= velocity.x;
		velocity.x = -velocity.x;
	}
	if ((position.y - radius < 0) || (position.y + radius > SCREEN_HEIGHT))
	{
		position.y -= velocity.y;
		velocity.y = -velocity.y;

		if (position.y + radius > SCREEN_HEIGHT)
		{
			isTouchedFloor = true;
		}
	}


}


void Ball::StartPosition()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT - 55;
	velocity.y = maxVel;
}


void Ball::Render(SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderFillCircle(ren, circle.x, circle.y, circle.rad);
	SDL_SetRenderDrawColor(ren, 100, 100, 255, 0);
	circle = { position.x,position.y,radius };
	SDL_RenderFillCircle(ren, circle.x, circle.y, circle.rad);

}


bool Ball::CheckCollision(Shape& obstacle)
{
	int cX, cY;

	//Find closest x offset
	if (position.x < obstacle.x)
	{
		cX = b.x;
	}
	else if (a.x > b.x + b.w)
	{
		cX = b.x + b.w;
	}
	else
	{
		cX = a.x;
	}
}