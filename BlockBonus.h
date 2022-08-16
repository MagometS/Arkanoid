#ifndef BLOCKBONUS_H
#define BLOCKBONUS_H

#include "Block.h"
#include "Bonus.h"

class BlockBonus : public Block
{
public:


	BlockBonus(int x, int y, Bonus* ptr);
	~BlockBonus() { bonus = NULL; }


	virtual void OnCollision(Player& player);


private:


	Bonus* bonus = NULL;

};
#endif
