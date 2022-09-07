#ifndef BLOCK_INDESTRUCTIBLE_H
#define BLOCK_INDESTRUCTIBLE_H

#include "Block.h"
#include "Player.h"

class Block_Indestructible : public Block
{
public:


	Block_Indestructible(int x, int y)
	{
		this->x = x;
		this->y = y;
		color = { 119, 136, 153, 0 };
	}


	void OnCollision(Player& player, Ball* ball) override
	{
		return;
	};
};
#endif
