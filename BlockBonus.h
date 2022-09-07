#ifndef BLOCKBONUS_H
#define BLOCKBONUS_H

#include "Block.h"
#include "Bonus.h"
#include "Ball.h"

class BlockBonus : public Block
{
public:


	BlockBonus(int x, int y, Bonus* ptr);
	~BlockBonus() { bonus = NULL; }


	void OnCollision(Player& player,Ball* ball) override;


private:


	Bonus* bonus = NULL;

};
#endif
