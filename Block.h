#ifndef BLOCK_H
#define BLOCK_H 

#include <SDL.h>
#include "Point.h"
#include "Obstacle.h"
#include "Color.h"
#include "Player.h"


class Block : public Obstacle
{
public:


	Block();
	Block(int x, int y);
	virtual ~Block();


	void Render(SDL_Renderer* ren);


	virtual void OnCollision(Player& player);


private:


	Color color = { 255, 99, 71 ,0 };
};

#endif

