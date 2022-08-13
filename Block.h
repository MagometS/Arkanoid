#ifndef BLOCK_H
#define BLOCK_H 

#include <SDL.h>
#include "Shape.h"
#include "Point.h"
#include "Obstacle.h"

class Block : public Shape, public Obstacle
{
public:
	Block(int x, int y);
	Block();
	virtual ~Block();
	void Render(SDL_Renderer* ren);
	virtual void OnCollision();
	void Destroy();
};

#endif

