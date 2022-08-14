#include "Ball.h"

Ball::Ball(int x, int y)
{
	position = { x,y };
	velocity.y = -maxVel;
	velocity.x = maxVel;
}


void Ball::Move(std::vector<Obstacle*>& obstacles)
{
	isTouchedFloor = false;
	bool isCollided = false;
	position.x += velocity.x;

	std::vector<Obstacle*>::iterator obsIter = obstacles.begin();
	for (;obsIter != obstacles.end();)
	{
		if(isCollided = CheckCollision(*obsIter))
		{
			(*obsIter)->OnCollision();
			if ((*obsIter)->isDestroyed())// ����� ����� �� ������ ������������ ����������� � �����, ��������� �� � ������� �����������
			{
				obsIter = obstacles.erase(obsIter);
			}
			else
			{
				++obsIter;
			}
			break;
		}
		else
		{
			++obsIter;
		}
	}

	if ((position.x - radius < 0) || (position.x + radius > SCREEN_WIDTH) || isCollided)
	{
		position.x -= velocity.x;
		velocity.x = -velocity.x;
	}

	isCollided = false;
	position.y += velocity.y;

	obsIter = obstacles.begin();
	for (; obsIter != obstacles.end();)
	{
		if (isCollided = CheckCollision(*obsIter))
		{
			(*obsIter)->OnCollision();
			if ((*obsIter)->isDestroyed())// ����� ����� �� ������ ������������ ����������� � �����, ��������� �� � ������� �����������
			{
				obsIter = obstacles.erase(obsIter);
			}
			else
			{
				++obsIter;
			}
			break;
		}
		else
		{
			++obsIter;
		}
	}


	if ((position.y - radius < 0) || (position.y + radius > SCREEN_HEIGHT) || isCollided)
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
	/*
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderFillCircle(ren, circle.x, circle.y, circle.rad);//�� �����, �� ������ ���������� ������ ����
	*/
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
	//circle = { position.x,position.y,radius };
	SDL_RenderFillCircle(ren, position.x, position.y, radius);
}


bool Ball::CheckCollision(Obstacle* obstacle)
{
	int cX, cY;

	//Find closest x offset
	if (position.x < obstacle->x)
	{
		cX = obstacle->x;
	}
	else if (position.x > obstacle->x + obstacle->w)
	{
		cX = obstacle->x + obstacle->w;
	}
	else
	{
		cX = position.x;
	}
	//Find closest y offset
	if (position.y < obstacle->y)
	{
		cY = obstacle->y;
	}
	else if (position.y > obstacle->y + obstacle->h)
	{
		cY = obstacle->y + obstacle->h;
	}
	else
	{
		cY = position.y;
	}

	//If the closest point is inside the circle
	if (((cX - position.x) * (cX - position.x) + (cY - position.y) * (cY - position.y)) < radius * radius)
	{
		//This box and the circle have collided
		return true;
	}

	//If the shapes have not collided
	return false;
}