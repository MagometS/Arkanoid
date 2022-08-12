#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include <SDL.h>

class Shape
{
public:
	//virtual Point GetPosition() = 0;
	//bool isChanged();
	virtual void Render(SDL_Renderer* ren) = 0;
	virtual ~Shape() = 0;

};

#endif