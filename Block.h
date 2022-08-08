#ifndef BLOCK_H
#define BLOCK_H 

#include <SDL.h>
#include "Shape.h"
#include "Point.h"

class Block : public Shape
{
public:
	Point GetPosition() { return _minLeft; }
	void Draw(SDL_Renderer* ren);
private:
	Point _minLeft;
	Point _maxRight;
};

#endif

