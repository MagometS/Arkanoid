#ifndef BLOCK_H
#define BLOCK_H 

#include <SDL.h>
#include "Point.h"
#include "Obstacle.h"
#include "Color.h"
#include "Player.h"
#include "Ball.h"


class Block : public Obstacle
{
public:


	Block();
	Block(int x, int y);
	virtual ~Block();


	void Render(SDL_Renderer* ren) override;


	void OnCollision(Player& player, Ball* ball) override;


protected:


	Color color = { 255, 99, 71 ,0 };
};

#endif

