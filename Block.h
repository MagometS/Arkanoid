#ifndef BLOCK_H
#define BLOCK_H 

#include <SDL.h>
#include "Point.h"
#include "Obstacle.h"
#include "Color.h"

class Block : public Obstacle
{
public:
	Block(int x, int y);
	Block();
	virtual ~Block();
	void Render(SDL_Renderer* ren);
	virtual void OnCollision();
	void Destroy();

private:
	Color color = { 255, 99, 71 ,0 };
};

#endif

