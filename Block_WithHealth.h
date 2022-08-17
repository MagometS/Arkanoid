#ifndef BLOCK_WITHHEALTH_H
#define BLOCK_WITHHEALTH_H

#include "Block.h"
#include "Player.h"

class Block_WithHealth : public Block
{
public:

	Block_WithHealth(int x, int y, int health);
	~Block_WithHealth() {}


	void OnCollision(Player& player);


private:
	

	int health;
};
#endif
