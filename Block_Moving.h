#ifndef BLOCK_MOVING_H
#define BLOCK_MOVING_H

#include "Obstacle.h"
#include "Block.h"



class Block_Moving : public Block
{

public:


	Block_Moving(int x, int y);
	~Block_Moving() {};


	bool isActivated() { return _isActivated; }


	bool isMaterial() { return _isMaterial; }

	
	void Activate() 
	{
		_isActivated = true;
		_isMaterial = true;
	}


	void OffIsMaterial() { _isMaterial = false; }


	void OnCollision(Player& player, Ball* ball) override;


	bool CheckCollision(Obstacle* obstacle);


	void Move(std::vector<Obstacle*>& obstacles);


private:


	int vel = 5;
	int health = 3;
	bool _isActivated = false;
	bool _isMaterial = false;
};

#endif // !BLOCK_MOVING_H
