#include "Block_WithHealth.h"


Block_WithHealth::Block_WithHealth(int x, int y, int health)
{
	this->x = x;
	this->y = y;
	this->health = health;
	color = { 255, 255, 0 ,0 };
}


void Block_WithHealth::OnCollision(Player& player, Ball* ball)
{
	player.PlusScore(1);

	health--;

	if (health == 0)
	{
		_isDestroyed = true;
	}
}

