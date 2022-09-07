#ifndef BLOCK_SPEEDUP_H
#define BLOCK_SPEEDUP_H

#include "Block.h"
#include "Ball.h"
#include "Player.h"

class Block_SpeedUp : public Block
{
public:


	Block_SpeedUp(int x, int y)
	{
		this->x = x;
		this->y = y;
		color = { 124, 252, 0, 0 };
	}
	~Block_SpeedUp() {}


	void OnCollision(Player& player, Ball* ball) override;
};
#endif // !BLOCK_SPEEDUP_H

