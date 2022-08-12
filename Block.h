#ifndef BLOCK_H
#define BLOCK_H 

#include <SDL.h>
#include "Shape.h"
#include "Point.h"

class Block : public Shape
{
public:
	Block(Point minLeft, Point maxRight);
	~Block();
	Point GetPosition() { return _minLeft; }
	void Draw(SDL_Renderer* ren);
	void Destroy();
	bool isDestroyed() { return _isDestroyed; }

private:
	Point _minLeft;
	Point _maxRight;
	bool _isDestroyed;
};

#endif

