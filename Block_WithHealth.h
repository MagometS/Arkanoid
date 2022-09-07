#ifndef BLOCK_WITHHEALTH_H
#define BLOCK_WITHHEALTH_H


#include "Block.h"
#include "Player.h"
#include "Ball.h"


class Block_WithHealth : public Block
{
public:


	Block_WithHealth(int x, int y, int health);
	~Block_WithHealth() {}


	void OnCollision(Player& player, Ball* ball) override;


private:
	

	int health;
};
#endif
