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

	
	void Activate() { _isActivated = true; }


	void OnCollision(Player& player, Ball* ball) override;


	bool CheckCollision(Obstacle* obstacle);


	void Move(std::vector<Obstacle*>& obstacles);


private:


	int vel = 5;
	int health = 3;
	bool _isActivated = false;
};

#endif // !BLOCK_MOVING_H
