#include "Block_Moving.h"


Block_Moving::Block_Moving(int x, int y)
{
	this->x = x;
	this->y = y;
	color = {34, 139, 34, 0};
}


void Block_Moving::OnCollision(Player& player, Ball* ball)
{
	player.PlusScore(1);

	this->health--;

	if (health == 0)
	{
		_isDestroyed = true;
	}
}


void Block_Moving::Move(std::vector<Obstacle*>& obstacles)
{
	bool isCollided = false;

	this->x += vel;

	for (int i = 0; i < obstacles.size(); i++)
	{
		if (obstacles[i] == this)
		{
		}
		else
		{
			if (isCollided = CheckCollision(obstacles[i]))
			{
				break;
			}
		}
	}
	if (this->x < 0 || this->x + this->w > SCREEN_WIDTH || isCollided)
	{
		vel = -vel;
	}
}


bool Block_Moving::CheckCollision(Obstacle* obstacle)
{
	if (this->x + this->w >= obstacle->x &&    
		this->x <= obstacle->x + obstacle->w &&
		this->y + this->h >= obstacle->y &&
		this->y <= obstacle->y + obstacle->h) 
	{
		return true;
	}

	return false;
}
