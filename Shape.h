#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include <SDL.h>

class Shape
{
public:
	virtual Point GetPosition() = 0;
	virtual void Update() = 0;
	virtual void Draw(SDL_Renderer* ren) = 0;
	virtual ~Shape() = 0;

};

#endif