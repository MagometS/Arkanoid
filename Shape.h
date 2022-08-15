#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include <SDL.h>

class Shape
{
public:
	virtual void Render(SDL_Renderer* ren) = 0;
	virtual ~Shape() = 0;

};

#endif