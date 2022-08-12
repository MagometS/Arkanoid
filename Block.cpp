#include "Block.h"

void Block::Destroy()
{
	_isDestroyed = true;
}


Block::Block(Point minLeft, Point maxRight)
{
	_minLeft = minLeft;
	_maxRight = maxRight;
	_isDestroyed = false;
}

void Block::Draw(SDL_Renderer* ren)
{

}

Block::~Block() {}