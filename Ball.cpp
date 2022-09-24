#include "Ball.h"


Ball::Ball()
{
	position = { radius,radius };
	velocity.y = -maxVel;
	velocity.x = maxVel;
}


Ball::Ball(int x, int y)
{
	position = { x,y };
	velocity.y = -maxVel;
	velocity.x = maxVel;
}


void Ball::Move(std::vector<Obstacle*>& obstacles, Player& player)
{
	bool isCollided = false;
	position.x += velocity.x;


	std::vector<Obstacle*>::iterator obsIter = obstacles.begin();
	for (;obsIter != obstacles.end();)
	{
		if(isCollided = CheckCollision(*obsIter))
		{
			(*obsIter)->OnCollision(player, this);

			if ((*obsIter)->isDestroyed())// Чтобы потом не искать уничтоженные препятствия в цикле, проверяем то с которым столкнулись
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
			(*obsIter)->OnCollision(player, this);

			if ((*obsIter)->isDestroyed())// Чтобы потом не искать уничтоженные препятствия в цикле, проверяем то с которым столкнулись
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
		if (position.y + radius > SCREEN_HEIGHT)
		{
			player.MinusHealth();// при касании пола уменьшаем количество жизней
		}

		position.y -= velocity.y;
		velocity.y = -velocity.y;
	}

}


void Ball::Move(std::vector<Obstacle*>& obstacles, Player& player, Ball* secondBall)
{
	bool isCollided = false;
	bool isCollidedWithBall = false;
	position.x += velocity.x;

	if (isCollidedWithBall = CheckCollision(secondBall) && secondBall->GetVelocity().x * velocity.x < 0)//если мячи двигались навстречу отбросим и второй мяч
	{
		secondBall->ChangeDirection_X();
	}


	std::vector<Obstacle*>::iterator obsIter = obstacles.begin();
	for (; obsIter != obstacles.end();)
	{
		if (isCollided = CheckCollision(*obsIter))
		{
			(*obsIter)->OnCollision(player, this);

			if ((*obsIter)->isDestroyed())// Чтобы потом не искать уничтоженные препятствия в цикле, проверяем то с которым столкнулись
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

	if ((position.x - radius < 0) || (position.x + radius > SCREEN_WIDTH) || isCollided || isCollidedWithBall)
	{
		position.x -= velocity.x;
		velocity.x = -velocity.x;
	}

	isCollided = false;
	isCollidedWithBall = false;
	position.y += velocity.y;

	if (isCollidedWithBall = CheckCollision(secondBall) && secondBall->GetVelocity().y * velocity.y < 0)//если мячи двигались навстречу отбросим и второй мяч
	{
		secondBall->ChangeDirection_Y();
	}

	obsIter = obstacles.begin();
	for (; obsIter != obstacles.end();)
	{
		if (isCollided = CheckCollision(*obsIter))
		{
			(*obsIter)->OnCollision(player, this);

			if ((*obsIter)->isDestroyed())// Чтобы потом не искать уничтоженные препятствия в цикле, проверяем то с которым столкнулись
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


	if ((position.y - radius < 0) || (position.y + radius > SCREEN_HEIGHT) || isCollided || isCollidedWithBall)
	{
		if (position.y + radius > SCREEN_HEIGHT)
		{
			player.MinusHealth();// при касании пола уменьшаем количество жизней
		}

		position.y -= velocity.y;
		velocity.y = -velocity.y;
	}

}



void Ball::StartPosition()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT - 55;
	velocity.y = maxVel;
	velocity.x = maxVel;
}


void Ball::Render(SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
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


bool Ball::CheckCollision(Ball* ball)
{
	Point secondPosition = ball->GetPosition();
	int secondRadius = ball->GetRadius();

	int totalRadius = this->radius + secondRadius;
	int deltaX = position.x - secondPosition.x;
	int deltaY = position.y - secondPosition.y;
	if ((deltaX * deltaX + deltaY * deltaY) < totalRadius * totalRadius)
	{
		return true;
	}
	return false;
}


void Ball::SetColor(int r, int g, int b, int a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}


void Ball::SpeedUp(int vel)
{
	this->maxVel += vel;
}