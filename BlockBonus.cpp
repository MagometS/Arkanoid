#include "BlockBonus.h"


BlockBonus::BlockBonus(int x, int y, Bonus* ptr)
{
	this->x = x;
	this->y = y;
	bonus = ptr;
}


void BlockBonus::OnCollision(Player& player)
{
	player.PlusScore(1);

	_isDestroyed = true;

	bonus->Activate();

}