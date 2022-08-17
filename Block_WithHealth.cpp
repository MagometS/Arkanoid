#include "Block_WithHealth.h"


Block_WithHealth::Block_WithHealth(int x, int y, int health)
{
	this->x = x;
	this->y = y;
	this->health = health;
}


void Block_WithHealth::OnCollision(Player& player)
{
	player.PlusScore(1);

	health--;

	if (health == 0)
	{
		_isDestroyed = true;
	}
}

