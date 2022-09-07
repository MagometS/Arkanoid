#include "Block_SpeedUp.h"


void Block_SpeedUp::OnCollision(Player& player, Ball& ball)
{

	player.PlusScore(1);


	_isDestroyed = true;


}
