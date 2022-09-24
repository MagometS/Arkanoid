#include "BonusMovingBlock.h"


BonusMovingBlock::BonusMovingBlock(int x, int y, Block_Moving* block)
{
	this->x = x;
	this->y = y;
	this->block = block;
}


BonusMovingBlock::~BonusMovingBlock()
{
	this->block = NULL;
}


void BonusMovingBlock::MakeAction()
{
	block->Activate();
}