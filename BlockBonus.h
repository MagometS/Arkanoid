#ifndef BLOCKBONUS_H
#define BLOCKBONUS_H

#include "Block.h"
#include "Bonus.h"

class BlockBonus : public Block
{
public:


	BlockBonus(int x, int y, Bonus* ptr);
	~BlockBonus() { bonus = NULL; }


	void OnCollision(Player& player) override;


private:


	Bonus* bonus = NULL;

};
#endif
