#ifndef BLOCK_MOVING_H
#define BLOCK_MOVING_H


#include "Block.h"


class Block_Moving : public Block
{

public:


	Block_Moving();
	~Block_Moving() {};


	bool isActivated() { return _isActivated; }

	
	void Activate() { _isActivated = true; }


private:


	int vel = 5;
	int health = 3;
	bool _isActivated = false;

};

#endif // !BLOCK_MOVING_H
