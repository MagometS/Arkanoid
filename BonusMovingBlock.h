#ifndef BONUSMOVINGBLOCK_H
#define BONUSMOVINGBLOCK_H

#include "Bonus.h"
#include "Block_Moving.h"


class BonusMovingBlock : public Bonus
{
	
public:


	BonusMovingBlock(int x, int y, Block_Moving* block);
	~BonusMovingBlock();


	void MakeAction() override;


private:


	Block_Moving* block;
};

#endif
